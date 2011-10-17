cmake_minimum_required( VERSION 2.8 )
project(HackThePlanet)
	SET( EXECUTABLE_OUTPUT_PATH "bin/" )
	SET( LIBRARY_OUTPUT_PATH "lib/" )
	include_directories( "include" )
	FILE( GLOB_RECURSE HackThePlanet_SRCS src/*.cpp )
	add_executable( HackThePlanet ${HackThePlanet_SRCS} )
	target_link_libraries( HackThePlanet rt boost_random boost_filesystem
	boost_iostreams boost_date_time dl lua )
