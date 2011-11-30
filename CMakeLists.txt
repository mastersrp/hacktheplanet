cmake_minimum_required( VERSION 2.8 )
SET( EXECUTABLE_OUTPUT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/bin" )
SET( LIBRARY_OUTPUT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib" )
#SET( CMAKE_VERBOSE_MAKEFILE true )
include_directories( "${CMAKE_CURRENT_SOURCE_DIR}/include"
"${CMAKE_CURRENT_SOURCE_DIR}/deps/libscript/include"
"${CMAKE_CURRENT_SOURCE_DIR}/deps/boost/include" )
link_directories( "${CMAKE_CURRENT_SOURCE_DIR}/deps/libscript/lib" )

add_subdirectory( "${CMAKE_CURRENT_SOURCE_DIR}/deps/libscript" )
add_subdirectory( "${CMAKE_CURRENT_SOURCE_DIR}/src/input" )
add_subdirectory( "${CMAKE_CURRENT_SOURCE_DIR}/src/render" )
add_subdirectory( "${CMAKE_CURRENT_SOURCE_DIR}/src/htp" )
