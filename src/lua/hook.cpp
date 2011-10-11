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

HTP::lua::hook::hook(lua_State *L){
	scriptEngine = L;
}

int HTP::lua::hook::onInit() {
	std::cout << "[*] CALL 'onInit' HOOK" << std::endl;
	HTP::lua::dofunction(scriptEngine, (const char*)"onInit");
	return 0;
}
int HTP::lua::hook::onExit() {
	std::cout << "[*] CALL 'onExit' HOOK" << std::endl;
	HTP::lua::dofunction(scriptEngine, (const char*)"onExit");
	return 0;
}
int HTP::lua::hook::onCustom( const char *hook )
{
	std::cout << "[*] CALL '" << hook << "' HOOK" << std::endl;
	HTP::lua::dofunction(scriptEngine, hook);
	return 0;

}
