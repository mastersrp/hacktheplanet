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
#include <boost/random.hpp>
#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
// LUA
#include <lua.hpp>
// CUSTOM
#include <htp/lua.hpp>

int main( int argc, char *argv[] )
{
    std::cout << "[*I Initializing lua" << std::endl;
    lua_State *scriptEngine = lua_open();
    luaL_openlibs(scriptEngine);
	lua_pushstring(scriptEngine, "data/lua/include" );
	lua_setglobal(scriptEngine, "globalinclude");
	HTP::lua::report_errors(scriptEngine, luaL_dofile(scriptEngine, "data/engine.lua"));
    HTP::lua::hook scriptHook(scriptEngine);
    scriptHook.onInit();
    std::cout << "[*] Loading settings...";
    boost::property_tree::ptree settings;
    std::ifstream settings_file;
    settings_file.open("data/settings.json");
    if( !settings_file ) {
		std::cerr << "Couldn't open 'settings.json'!" << std::endl;
		scriptHook.onExit();
		lua_close(scriptEngine);
		return 1;
    }
    std::cout << "Done!" << std::endl;
    boost::property_tree::read_json( "data/settings.json", settings );
	std::string profile = settings.get<std::string>("profile", "default");
    std::cout << "Using '" << profile << "' profile." << std::endl;
    std::string profile_skin = settings.get<std::string>("profiles."+settings.get<std::string>(profile,"default")+".skin", "data/DefaultSkin.png" );
    std::cout << "skin:  " << profile_skin << std::endl;
    scriptHook.onExit();
    lua_close(scriptEngine);
    return 0;
}
