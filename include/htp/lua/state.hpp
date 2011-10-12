/*
 * This file is part of the HackThePlanet project
 * License is in COPYING file
 */
#include <config.hpp>
// STD LBIS
#include <iostream>
// LUA
#include <lua.hpp>
#include <htp/lua.hpp>

namespace HTP {
	namespace lua {
		int initState(lua_State* L);
		lua_State* createState();
	}
}
