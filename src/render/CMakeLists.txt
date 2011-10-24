cmake_minimum_required( VERSION 2.8 )

project( htp_render )
	file( GLOB_RECURSE htp_render_SRCS *.cpp )
	add_library( htp_render ${htp_render_SRCS} )
