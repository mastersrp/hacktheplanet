/*
 * This file is part of the HackThePlanet project.
 * License is in COPYING file.
 */
#include <htp/config.hpp>
// STD LIBS
#include <iostream>
#include <fstream>
// String library
#include <fastcxx/types/string.hpp>
// Settings system
#include <fastcxx/property_tree/ptree.hpp>
#include <fastcxx/property_tree/json.hpp>
// Graphical/Visual
#include <htp/render.hpp>
#include <irrlicht/irrlicht.h>
// Scripting library
#include <fastcxx/script/luavm.hpp>
// Low-level library
#include <htp/kernel.hpp>
// Other
#include <htp/util/timer.hpp>

int main( int argc, char *argv[] )
{

	HTP::App				*g_App = new HTP::App( argc, argv );
	HTP::render::glApp		*g_Renderer = g_App->getRenderer();
	fastcxx::script::LuaVM	*g_ScriptVM = g_App->getScriptVM();
	HTP::kernel::filesystem	*g_FileSystem = g_App->getFileSystem();

	#ifdef HTP_CXX0X
	HTP::util::Timer<std::chrono::nanoseconds> timer_loadtime;;
	#else
	HTP::util::Timer timer_loadtime;
	#endif
	// Setting up filesystem and paths
	// Script initialization
	std::cout << "[*I Initializing scripting system" << std::endl;
	g_ScriptVM->Init();
	// Settings parsing
	std::cout << "[*] Loading settings...";
	fastcxx::property_tree::ptree ptree;
    if( g_FileSystem->exists( "data/settings.json" ) == false || g_FileSystem->is_file( "data/settings.json") == false ) {
		std::cerr << "Couldn't open 'data/settings.json'!" << std::endl;
	} else {
		fastcxx::property_tree::JSONParser().ReadFile( "data/settings.json", ptree );
		std::cout << "Done!" << std::endl;
	}
	std::cout << "[*] Loading script framework..." << std::endl;
	#ifdef HTP_CXX0X
	std::cout << "[i] Loading took " << timer_loadtime.get_duration().count() << " nanoseconds." << std::endl;
	#else
	std::cout << "[i] Loading took " << timer_loadtime.get_duration() << " nanoseconds." << std::endl;
	#endif
	
	g_Renderer->createDevice();
	g_FileSystem->insertDevice( g_Renderer->getDevice() );
	int err = g_FileSystem->setWritePath( "data/" );
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
	g_Renderer->getDevice()->drop();
	return 0;
}
