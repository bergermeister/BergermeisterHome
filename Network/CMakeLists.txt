cmake_minimum_required( VERSION 3.15 )

set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

add_library( Network STATIC )

target_sources( Network
    PRIVATE
        src/Network/IPEndpoint.cpp
        src/Network/UDPSocket.cpp
        src/Network/UDPClient.cpp
)

# without it public headers won't get installed
set( public_headers
     src/Network/IPEndpoint.h
     src/Network/UDPSocket.h
     src/Network/UDPClient.h
)

target_include_directories( Network
    PRIVATE
        # where the library itself will look for its internal headers
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    PUBLIC
        # where top-level project will look for the library's public headers
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        # where external projects will look for the library's public headers
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# not for MSVC
if( CMAKE_COMPILER_IS_GNUCXX )
    # compile options for this target only
    # treat warnings as errors
    target_compile_options( Network PRIVATE -Werror )
endif()

