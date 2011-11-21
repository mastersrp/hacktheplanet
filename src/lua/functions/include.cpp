/*
 * This file is part of the HackThePlanet project
 * License is in COPYING file.
 */
#include <config.hpp>
// STD LIBS
#include <iostream>
#ifdef USE_BOOST
// BOOST C++
#include <boost/filesystem.hpp>
#else
#include <sys/types.h>
#include <sys/stat.h>
#endif
#include <lua.hpp>
#include <htp/lua/functions/include.hpp>

int HTP::lua_functions::include( lua_State *L ) {
	int top = lua_gettop(L);
	int ret = 0;
	const char *filename = lua_tostring(L, top);
	#ifdef USE_BOOST
	if( boost::filesystem::exists(filename) && boost::filesystem::is_regular_file(filename) ) {
		std::cout << " -- Running: " << filename << " (" << boost::filesystem::file_size(filename) << "byte)" << std::endl;
		ret = luaL_dofile(L, filename);
	}
	#else
	struct stat filestatus;
	stat( filename, &filestatus );
	if( filestatus.st_size > 0 )
	{
		std::cout << "-- Running : " << filename << " (" << filestatus.st_size << "byte)" << std::endl;
		ret = luaL_dofile(L, filename);
	}
	#endif
	return ret;
}
