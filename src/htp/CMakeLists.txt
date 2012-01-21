cmake_minimum_required( VERSION 2.8 )

project( HackThePlanet )
	file( GLOB_RECURSE HackThePlanet_SRCS *.cpp )
	find_package( Boost COMPONENTS system random filesystem iostreams date_time)
	if( NOT Boost_FOUND )
		message( FATAL_ERROR "Could not find Boost! ")
	endif( NOT Boost_FOUND )
	set( CMAKE_CXX_FLAGS "-std=c++0x" )
	include_directories( "${Boost_INCLUDE_DIR}" "${LIBRARY_OUTPUT_PATH}/gwen/trunk/gwen/include" )
	link_directories( "${LIBRARY_OUTPUT_PATH}" )
	add_executable( HackThePlanet ${HackThePlanet_SRCS} )
	target_link_libraries( HackThePlanet rt dl ${Boost_LIBRARIES}
	Angelscript htp_render script GL GLU Xext
	X11 png jpeg Irrlicht )

add_dependencies( HackThePlanet script )
