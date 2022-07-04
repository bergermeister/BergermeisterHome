cmake_minimum_required( VERSION 3.15 )

project( "Sensor"
    VERSION 0.0.1
    DESCRIPTION "Bergermeister Home Temperature & Humidity Sensor Application"
)

set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

find_package( Network 0.0.1 CONFIG REQUIRED )

add_executable( ${PROJECT_NAME} )

target_sources( ${PROJECT_NAME}
    PRIVATE
        src/Sensor/Main.cpp
        src/Sensor/DHT22.cpp
)

target_include_directories( ${PROJECT_NAME}
    PRIVATE
        # where the library itself will look for its internal headers
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries( ${PROJECT_NAME} PRIVATE Bergermeister::Network )
target_link_libraries( ${PROJECT_NAME} PRIVATE gpiod )