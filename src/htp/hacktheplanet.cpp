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
#ifdef USE_BOOST
#include <boost/chrono.hpp>
#endif
// LUA
#include <lua.hpp>
// Graphical/Visual
#if defined HTP_USE_NCURSES
#include <ncurses.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif

// CUSTOM
#include <script.hpp>
#include <htp/input.hpp>
#include <htp/render.hpp>
#include <htp/util/timer.hpp>

int main( int argc, char *argv[] )
{
	HTP::util::Timer timer_loadtime;

	// Lua initialization
    std::cout << "[*I Initializing lua" << std::endl;
	timer_loadtime.start();
	lua_State *scriptEngine = script::createState();
	lua_pushstring( scriptEngine, "data/lua/includes" );
	lua_setglobal( scriptEngine, "globalincludes" );
	// Lua scriptHook creation
    script::hook scriptHook;
	// Settings parsing
    std::cout << "[*] Loading settings...";
    boost::property_tree::ptree settings;
    std::ifstream settings_file;
    settings_file.open("data/settings.json");
    if( !settings_file ) {
		std::cerr << "Couldn't open 'settings.json'!" << std::endl;
		scriptHook.onExit(scriptEngine);
		script::endState(scriptEngine);
		return 1;
    }
    std::cout << "Done!" << std::endl;
    boost::property_tree::read_json( "data/settings.json", settings );
	std::string profile = settings.get<std::string>("profile", "default");
    std::cout << "[i] Using '" << profile << "' profile." << std::endl;
	std::string enginelua = settings.get<std::string>("profiles."+settings.get<std::string>(profile,"default")+".engine", "data/lua/engine.lua" );
	std::cout << "[*] Loading lua framework..." << std::endl;
	script::report_errors( scriptEngine, luaL_dofile(scriptEngine, enginelua.c_str()) );
	std::cout << "[i] Loading took " << timer_loadtime.get_duration() << "." << std::endl;
	
	HTP::render::App App;
	if( App.init() == false ) {
		return 1;
	}
	timer_loadtime.start();
	scriptHook.onInit( scriptEngine );
	std::cout << "[i] Init took " << timer_loadtime.get_duration() << "." << std::endl;
	script::dofunction( scriptEngine, "init" );

	std::cout << "[i] Running main rendering/interactive loop." << std::endl;
	bool running = App.running();
	initscr();
//	while( running )
//	{
		printw( "Hello world!" );
		refresh();
		App.ProcessInput();
		running = App.running();
//	}
	endwin();
	// Ending scriptHook
	scriptHook.onExit( scriptEngine );
	// Ending lua scriptEngine
	script::endState(scriptEngine);
    return 0;
}
