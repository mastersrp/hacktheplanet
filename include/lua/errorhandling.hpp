/*
 * This file is part of the HackThePlanet project.
 * License is in COPYING file.
 */
#ifndef HTP_LUA_ERROR_HANDLING_HPP
#define HTP_LUA_ERROR_HANDLING_HPP
#include <config.hpp>
// STD LIBS
#include <iostream>
// LUA
#include <lua.hpp>

namespace HTP {
	namespace lua {
		void report_errors(lua_State *L, int status );
	}
}
#endif /* LUA_ERROR_HANDLING_HPP */
