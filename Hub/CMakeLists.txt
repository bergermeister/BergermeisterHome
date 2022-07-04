cmake_minimum_required( VERSION 3.15 )

project( "Hub"
    VERSION 0.0.1
    DESCRIPTION "Bergermeister Home Hub Application"
)

set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

find_package( Network 0.0.1 CONFIG REQUIRED )

add_executable( ${PROJECT_NAME} )

target_sources( ${PROJECT_NAME}
    PRIVATE
        src/Hub/Main.cpp
)

target_include_directories( ${PROJECT_NAME}
    PRIVATE
        # where the library itself will look for its internal headers
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries( ${PROJECT_NAME} LINK_PUBLIC  Bergermeister::Network )
# target_link_libraries( ${PROJECT_NAME} PRIVATE gpiod )