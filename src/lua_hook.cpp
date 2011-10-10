/*
 * This file is part of the HackThePlanet project.
 * License is in COPYING file.
 */
#include <config.hpp>
// STD LIBS
#include <iostream>
#include <fstream>
#include <string>
// BOOST C++
#include <boost/filesystem.hpp>
// LUA
#include <lua.hpp>
// CUSTOM
#include <htp/lua_hook.hpp>

HTP::lua::hook::hook(lua_State *L){
	scriptEngine = L;
}

int HTP::lua::hook::onInit() {
	std::cout << "[*] CALL 'onInit' HOOK" << std::endl;
	return 0;
}
int HTP::lua::hook::onExit() {
	std::cout << "[*] CALL 'onExit' HOOK" << std::endl;
	return 0;
}
int HTP::lua::hook::onCustom( const char *hook )
{
	std::cout << "[*] CALL '" << hook << "' HOOK" << std::endl;
	return 0;
}