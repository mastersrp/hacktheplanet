/*
 * This file is part of the HackThePlanet project
 * License is in COPYING file
 */
#include <config.hpp>
// STD LBIS
// LUA
#include <lua.hpp>

namespace HTP {
	namespace lua {
		int initState( lua_State* L);
		int endState( lua_State* L);
		lua_State* createState();
	}
}
