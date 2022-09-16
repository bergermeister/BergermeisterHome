cmake_minimum_required( VERSION 3.15 )
project( Bergermeister VERSION 0.0.1 )

set( CMAKE_CXX_STANDARD 14 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

add_library( BDF STATIC )
add_subdirectory( src )
target_include_directories( BDF
   PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}/src
      
   PUBLIC
      # where top-level project will look for the library's public headers
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
      # where external projects will look for the library's public headers
      $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
target_link_libraries( BDF PRIVATE gpiod )

if( BUILD_TESTING )
   # -pg    enable profiling
   target_compile_options( BDF PUBLIC -fprofile-arcs -ftest-coverage --coverage -pg --no-pie -no-pie -fno-pie )
   add_link_options( -fprofile-arcs --coverage -pg --no-pie -no-pie -fno-pie )

   include( FetchContent )
   FetchContent_Declare(
      googletest
      GIT_REPOSITORY https://github.com/google/googletest.git
      GIT_TAG release-1.12.1
   )
   # For Windows: Prevent overriding the parent project's compiler/linker settings
   set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
   FetchContent_MakeAvailable( googletest )

   enable_testing( )

   add_executable( GTestBDF )
   add_subdirectory( tst )
   target_include_directories( GTestBDF
      PRIVATE
         ${CMAKE_CURRENT_SOURCE_DIR}

      PUBLIC
         # where top-level project will look for the library's public headers
         $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
         # where external projects will look for the library's public headers
         $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
   )
   target_link_libraries(
      GTestBDF
      GTest::gtest_main
      BDF
      gcov
   )

   include( GoogleTest )
   gtest_discover_tests( GTestBDF )   
endif( )