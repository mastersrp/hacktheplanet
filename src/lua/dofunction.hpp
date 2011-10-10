/*
 * This file is part of the HackThePlanet project.
 * License is in COPYING file.
 */
#ifndef LUA_DOFUNCTION_HPP
#define LUA_DOFUNCTION_HPP
#include <config.hpp>
// STD LIBS
#include <iostream>
// BOOST C++
#include <boost/filesystem.hpp>
// LUA
#include <lua.hpp>

int htp::lua::dofunction( input function ) {
	lua_getglobal(L, function);
	int ret = lua_pcall(L, 0,0,0,0);
	LUA_ERROR_HANDLING (L, ret );
	return ret;
}
#endif /* LUA_DOFUNCTION_HPP */
