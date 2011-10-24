cmake_minimum_required( VERSION 2.8 )

project( htp_input )
	file( GLOB_RECURSE htp_input_SRCS *.cpp )
	add_library( htp_input ${htp_input_SRCS} )
