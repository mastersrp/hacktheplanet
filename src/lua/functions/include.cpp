/*
 * This file is part of the HackThePlanet project
 * License is in COPYING file.
 */
#include <config.hpp>
#include <iostream>
#include <boost/filesystem.hpp>
#include <lua.hpp>
#include <htp/lua/functions/include.hpp>

int HTP::lua_functions::include( lua_State *L ) {
	int top = lua_gettop(L);
	int ret = 0;
	const char *filename = lua_tostring(L, top);
	if( boost::filesystem::exists(filename) && boost::filesystem::is_regular_file(filename) ) {
		std::cout << " -- Running: " << filename << " (" << boost::filesystem::file_size(filename) << "byte)" << std::endl;
		ret = luaL_dofile(L, filename);
	}
	return ret;
}
