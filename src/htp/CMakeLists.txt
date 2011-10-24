cmake_minimum_required( VERSION 2.8 )

project( HackThePlanet )
	file( GLOB_RECURSE HackThePlanet_SRCS *.cpp )
	add_executable( HackThePlanet ${HackThePlanet_SRCS} )
	target_link_libraries( HackThePlanet rt boost_random boost_filesystem
		boost_iostreams boost_date_time GL dl lua htp_input htp_lua
		htp_render )
