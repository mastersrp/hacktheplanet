/*
 * This file is part of the HackThePlanet project.
 * License is in COPYING file.
 */
#include <config.hpp>
// STD LBIS
#include <iostream>
// LUA
#include <lua.hpp>
#include <htp/lua.hpp>

int HTP::lua::initState( lua_State* L) {
	lua_pushstring(L, "data/lua/include" );
	lua_setglobal(L, "globalinclude" );
	lua_register(L, "include", HTP::lua_functions::include );
	return 0;
}
int HTP::lua::endState( lua_State* L ) {
	lua_close(L);
	return 0;
}

lua_State* HTP::lua::createState() {
	lua_State *L = lua_open();
	luaL_openlibs(L);
	if( HTP::lua::initState(L) != 0 ) {
		std::cerr << "could NOT init state!" << std::endl;
		}
	return L;
}
