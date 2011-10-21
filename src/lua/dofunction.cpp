/*
 * This file is part of the HackThePlanet project.
 * License is in COPYING file.
 */
#include <config.hpp>
// STD LIBS
#include <iostream>
// BOOST C++
#include <boost/filesystem.hpp>
// LUA
#include <lua.hpp>
#include <htp/lua/dofunction.hpp>

int HTP::lua::dofunction( lua_State *L, const char *function ) {
	lua_getglobal(L, function);
	int ret = lua_pcall(L, 0,0,0);
	//eport_errors(L, ret );
	return ret;
}
