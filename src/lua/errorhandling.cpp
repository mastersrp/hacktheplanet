/*
 * This file is part of the HackThePlanet project.
 * License is in COPYING file.
 */
#include <config.hpp>
// STD LIBS
#include <iostream>
// LUA
#include <lua.hpp>
#include <htp/lua.hpp>

void HTP::lua::report_errors(lua_State *L, int status ) {
	if( status != 0 ) {
		std::cerr << "-- " << lua_tostring(L,-1) << std::endl;
		lua_pop(L,1);
	}
}
