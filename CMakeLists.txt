cmake_minimum_required( VERSION 3.15 )
project( Bergermeister VERSION 0.0.1 )

#include( CTest )
#enable_testing( )

add_subdirectory( Network )
add_subdirectory( Sensor )
add_subdirectory( Hub )

#set( CPACK_PROJECT_NAME ${PROJECT_NAME} )
#set( CPACK_PROJECT_VERSION ${PROJECT_VERSION} )
#include(CPack)
