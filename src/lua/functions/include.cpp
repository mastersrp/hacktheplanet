/*
 * This file is part of the HackThePlanet project
 * License is in COPYING file.
 */
#include <config.hpp>
#include <iostream>
#include <boost/filesystem.hpp>
#include <lua.hpp>
#include <htp/lua.hpp>

int HTP::lua_functions::include( lua_State *L ) {
	int top = lua_gettop(L);
	const char *filename = lua_tostring(L, top);
	if( boost::filesystem::exists(filename) && boost::filesystem::is_regular_file(filename) ) {
		std::cout << " -- including: " << filename << " (" << boost::filesystem::file_size(filename) << "byte)" << std::endl;
		luaL_dofile(L, filename);
	}
	return 0;
}
