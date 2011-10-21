cmake_minimum_required( VERSION 2.8 )
SET( EXECUTABLE_OUTPUT_PATH "bin/" )
SET( LIBRARY_OUTPUT_PATH "lib/" )

project( htp_input )
	include_directories( "include" )
	FILE( GLOB_RECURSE htp_input_SRCS src/input/*.cpp )
	add_library( htp_input ${htp_input_SRCS} )

project( htp_lua )
	include_directories( "include" )
	FILE( GLOB_RECURSE htp_lua_SRCS src/lua/*.cpp )
	add_library( htp_lua ${htp_lua_SRCS} )

project( htp_render )
	include_directories( "include" )
	FILE( GLOB_RECURSE htp_render_SRCS src/render/*.cpp )
	add_library( htp_render ${htp_render_SRCS} )

project( HackThePlanet )
	include_directories( "include" )
	FILE( GLOB_RECURSE HackThePlanet_SRCS src/htp/*.cpp )
	add_executable( HackThePlanet ${HackThePlanet_SRCS} )
	target_link_libraries( HackThePlanet rt boost_random boost_filesystem boost_iostreams boost_date_time GL dl lua htp_input htp_lua htp_render )
