cmake_minimum_required( VERSION 2.8 )

project( htp_lua )
	file( GLOB_RECURSE htp_lua_SRCS *.cpp )
	add_library( htp_lua ${htp_lua_SRCS} )
