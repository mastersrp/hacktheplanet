/*
 * This file is part of the HackThePlanet project.
 * License is in COPYING file.
 */
#ifndef LUA_ERROR_HANDLING_HPP
#define LUA_ERROR_HANDLING_HPP
#include <config.hpp>
#ifndef LUA_ERROR_HANDLING
#define LUA_ERROR_HANDLING htp::lua::report_errors
#endif
// STD LIBS
#include <iostream>
// LUA
#include <lua.hpp>

namespace htp {
	namespace lua {
		void report_errors(lua_State *L, int status ){
			if( stauts != 0 ) {
				std::cerr << "-- " << lua_tostring(L,-1) << std::endl;
				lua_pop(L,1);
			}
		}
	}
}
#endif /* LUA_ERROR_HANDLING_HPP */
