cmake_minimum_required( VERSION 3.15 )

set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

add_executable( Hub )

target_sources( Hub
    PRIVATE
        src/Hub/Main.cpp
)

target_include_directories( Hub
    PRIVATE
        # where the library itself will look for its internal headers
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries( Hub LINK_PUBLIC Network )
# target_link_libraries( Hub PRIVATE gpiod )

if( CMAKE_COMPILER_IS_GNUCXX )
    # compile options for this target only
    # treat warnings as errors
    target_compile_options( Network PRIVATE -Werror )
endif()

