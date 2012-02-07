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
// Low-level library
#include <htp/kernel.hpp>
// Other
#include <htp/util/timer.hpp>


int main( int argc, char *argv[] )
{

	HTP::App				*g_App = new HTP::App( argc, argv );
	HTP::render::glApp		*g_Renderer = g_App->getRenderer();
	script::state			*g_ScriptState = g_App->getScriptState();
	script::hook			*g_ScriptHook = g_App->getScriptHook();
	HTP::kernel::filesystem	*g_FileSystem = g_App->getFileSystem();

	HTP::util::Timer<std::chrono::nanoseconds> timer_loadtime;;
	// Setting up filesystem and paths
	// Script initialization
	std::cout << "[*I Initializing scripting system" << std::endl;
	g_ScriptState->CreateState();
	g_ScriptHook->InsertState( g_ScriptState->getState() );
	// Settings parsing
	std::cout << "[*] Loading settings...";
	boost::property_tree::ptree settings;
    if( g_FileSystem->exists( "data/settings.json" ) == false || g_FileSystem->is_file( "data/settings.json") == false ) {
		std::cerr << "Couldn't open 'settings.json'!" << std::endl;
		g_ScriptHook->onExit();
		return 1;
	}
	boost::property_tree::read_json( "data/settings.json", settings );
	std::cout << "Done!" << std::endl;
	std::string profile = settings.get<std::string>("profile", "default");
	std::cout << "[i] Using '" << profile << "' profile." << std::endl;
	std::string enginescript = settings.get<std::string>("profiles."+settings.get<std::string>(profile,"default")+".engine", "data/lua/engine" );
	enginescript += ".as";
	std::string enginedata = settings.get<std::string>("profile."+settings.get<std::string>(profile,"default")+".data", "data/" );
	//g_ScriptState->DoFile( enginelua.c_str() );
	std::cout << "[*] Loading script framework..." << std::endl;
	if( g_ScriptState->DoFile( enginescript ) != 0 ) {
		std::cout << "[note] did something go wrong?" << std::endl;
	}
	std::cout << "[i] Loading took " << timer_loadtime.get_duration().count() << " nanoseconds." << std::endl;
	
	//g_ScriptHook->onInit();
	
	std::cout << "[i] Passing control to Irrlicht..." << std::endl;
	std::cout << "===================================" << std::endl;
	g_Renderer->createDevice();
	g_FileSystem->insertDevice( g_Renderer->getDevice() );
	int err = g_FileSystem->setWritePath( enginedata );
	switch( err )
	{
		case 200 :
			break;
		case 404 :
			std::cerr << "[ERR] DATA PATH COULD NOT LOAD" << std::endl;
			return 1;
		case 300 :
			std::cerr << "[ERR] DATA PATH SET TO FILE" << std::endl;
			return 1;
		default:
			break;
	}

	g_Renderer->getDevice()->getSceneManager()->addCameraSceneNodeFPS();

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
