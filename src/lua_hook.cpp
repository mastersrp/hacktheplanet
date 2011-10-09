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

htp::lua::hook::hook(lua_State *L){
	scriptEngine = L;
}

int htp::lua::hook::onInit() {
	std::cout << "[*] CALL 'onInit' HOOK" << std::endl;
	return 0;
}
int htp::lua::hook::onExit() {
	std::cout << "[*] CALL 'onExit' HOOK" << std::endl;
	return 0;
}
