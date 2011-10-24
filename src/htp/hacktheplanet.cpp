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
#include <boost/chrono.hpp>
// LUA
#include <lua.hpp>
// CUSTOM
#include <htp/lua.hpp>
#include <htp/input.hpp>
#include <htp/render.hpp>
#include <htp/util/timer.hpp>

int main( int argc, char *argv[] )
{
	HTP::util::Timer timer_runtime;
	HTP::util::Timer timer_loadtime;

	timer_runtime.start();

	// Lua initialization
    std::cout << "[*I Initializing lua" << std::endl;
	timer_loadtime.start();
	lua_State *scriptEngine = HTP::lua::createState();
	// Lua scriptHook creation
    HTP::lua::hook scriptHook;
	// Settings parsing
    std::cout << "[*] Loading settings...";
    boost::property_tree::ptree settings;
    std::ifstream settings_file;
    settings_file.open("data/settings.json");
    if( !settings_file ) {
		std::cerr << "Couldn't open 'settings.json'!" << std::endl;
		scriptHook.onExit(scriptEngine);
		HTP::lua::endState(scriptEngine);
		return 1;
    }
    std::cout << "Done!" << std::endl;
    boost::property_tree::read_json( "data/settings.json", settings );
	std::string profile = settings.get<std::string>("profile", "default");
    std::cout << "Using '" << profile << "' profile." << std::endl;
    std::string profile_skin = settings.get<std::string>("profiles."+settings.get<std::string>(profile,"default")+".skin", "data/DefaultSkin.png" );
    std::cout << "skin:  " << profile_skin << std::endl;
	std::string enginelua = settings.get<std::string>("profiles."+settings.get<std::string>(profile,"default")+".engine", "data/lua/engine.lua" );
	std::cout << "[*] Loading lua framework..." << std::endl;
	HTP::lua::report_errors( scriptEngine, luaL_dofile(scriptEngine, enginelua.c_str()) );
	std::cout << "[i] Loading took '" << timer_loadtime.get_duration() << "' seconds." << std::endl;
	
	HTP::render::glApp glApp;
	glApp.init();
	while( glApp.Running() )
	{
		std::cout << "Running." << std::endl;
	}
	
	// Init scriptHook
	scriptHook.onInit(scriptEngine);
	// lua gameplay loop
	HTP::lua::dofunction(scriptEngine, "mainloop" );
	// Ending scriptHook
    scriptHook.onExit(scriptEngine);
	// Ending lua scriptEngine
    HTP::lua::endState(scriptEngine);
	std::cout << "[i] Ran for " << timer_runtime.get_duration() << " seconds." << std::endl;
    return 0;
}
