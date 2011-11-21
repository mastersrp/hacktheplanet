/*
 * This file is part of the HackThePlanet project.
 * License is in COPYING file.
 */
#ifndef HTP_LUA_DOFUNCTION_HPP
#define HTP_LUA_DOFUNCTION_HPP
#include <config.hpp>
// STD LIBS
#include <iostream>
// LUA
#include <lua.hpp>

namespace HTP {
    namespace lua {
	int dofunction( lua_State *L, const char *function );
    }
}
#endif /* LUA_DOFUNCTION_HPP */
