cmake_minimum_required( VERSION 2.8 )

include_directories( "${CMAKE_CURRENT_SOURCE_DIR}/angelscript/include" )

add_subdirectory( "${CMAKE_CURRENT_SOURCE_DIR}/libscript" )

project( Angelscript )
	file( GLOB_RECURSE Angelscript_SRCS "angelscript/source/*.cpp" )
	add_library( Angelscript ${Angelscript_SRCS} )
