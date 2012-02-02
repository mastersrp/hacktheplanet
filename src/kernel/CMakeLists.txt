cmake_minimum_required( VERSION 2.8 )

project( htp_kernel )
	file( GLOB_RECURSE htp_kernel_SRCS *.cpp )
	add_library( htp_kernel ${htp_kernel_SRCS} )
