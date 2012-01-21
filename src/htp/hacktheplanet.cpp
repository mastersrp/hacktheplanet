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
#include <htp/render.hpp>
// Scripting library
#include <script.hpp>
// Other
#include <htp/util/timer.hpp>


HTP::App			*g_App = new HTP::App();
HTP::render::glApp	*g_Renderer = g_App->getRenderer();
script::state		*g_ScriptState = g_App->getScriptState();
script::hook		*g_ScriptHook = g_App->getScriptHook();

int main( int argc, char *argv[] )
{
	HTP::util::Timer<std::chrono::nanoseconds> timer_loadtime;;
	// Lua initialization
	std::cout << "[*I Initializing scripting system" << std::endl;
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
	std::string enginelua = settings.get<std::string>("profiles."+settings.get<std::string>(profile,"default")+".engine", "data/lua/engine" );
	//g_ScriptState->DoFile( enginelua.c_str() );
	std::cout << "[*] Loading lua framework..." << std::endl;
	std::cout << "[i] Loading took " << timer_loadtime.get_duration().count() << " nanoseconds." << std::endl;
	
	//g_ScriptHook->onInit();
	
	std::cout << "[i] Passing control to Irrlicht..." << std::endl;
	std::cout << "===================================" << std::endl;
	g_Renderer->createDevice();

	while( g_Renderer->getDevice()->run() )
	{
		if( g_Renderer->getDevice()->isWindowActive() )
		{
			g_Renderer->Draw();
		} else {
			g_Renderer->getDevice()->yield();
		}
	}

	// Ending scriptHook
	//g_ScriptHook->onExit();
	g_Renderer->getDevice()->drop();
	return 0;
}
