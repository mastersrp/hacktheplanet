/*
 * This file is part of the HackThePlanet project.
 * License is in COPYING file.
 */
#include <htp/config.hpp>
// STD LIBS
#include <iostream>
#include <fstream>
#include <string>
// BOOST C++
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
// Graphical/Visual
#if defined HTP_USE_NCURSES
#include <ncurses.h>
#elif defined HTP_USE_GL
#include <GL/gl.h>
#include <GL/glut.h>
#endif
// Scripting library
#if defined( SCRIPT_USE_LUA )
#	include <lua.hpp>
#elif defined( SCRIPT_USE_AS )
#	include <angelscript.h>
#endif
#include <script.hpp> // The scripthook system
// CUSTOM
#include <htp/render.hpp>
#include <htp/util/timer.hpp>

script::state*		g_ScriptState = new script::state();
script::hook*		g_ScriptHook = new script::hook();

int main( int argc, char *argv[] )
{
	HTP::util::Timer<std::chrono::nanoseconds> timer_loadtime;
	// Lua initialization
	std::cout << "[*I Initializing lua" << std::endl;
	timer_loadtime.start();
	g_ScriptState->CreateState();
	g_ScriptHook->InsertState( g_ScriptState->getState() );
	// Settings parsing
	std::cout << "[*] Loading settings...";
	boost::property_tree::ptree settings;
	std::ifstream settings_file;
	settings_file.open("data/settings.json");
    if( !settings_file ) {
		std::cerr << "Couldn't open 'settings.json'!" << std::endl;
		g_ScriptHook->onExit();
		return 1;
	}
	std::cout << "Done!" << std::endl;
	boost::property_tree::read_json( "data/settings.json", settings );
	std::string profile = settings.get<std::string>("profile", "default");
	std::cout << "[i] Using '" << profile << "' profile." << std::endl;
	std::string enginelua = settings.get<std::string>("profiles."+settings.get<std::string>(profile,"default")+".engine", "data/lua/engine.lua" );
	g_ScriptState->DoFile( enginelua.c_str() );
	std::cout << "[*] Loading lua framework..." << std::endl;
	std::cout << "[i] Loading took " << timer_loadtime.get_duration().count() << " nanoseconds." << std::endl;
	
	HTP::render::App App;
	g_ScriptHook->onInit();
	int input;
	/*
	while( App.isRunning() )
	{
		input = App.ProcessInput();
		App.SetRunning( input );
	}
	*/
	// Ending scriptHook
	g_ScriptHook->onExit();
	return 0;
}
