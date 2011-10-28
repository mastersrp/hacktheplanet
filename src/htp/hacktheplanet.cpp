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
// OpenGL
#include <GL/gl.h>
#include <GL/glfw.h>

#ifdef HTP_USE_GWEN
// GWEN
#	include <Gwen/Gwen.h>
#	include <Gwen/Skins/Simple.h>
#	include <Gwen/Skins/TexturedBase.h>
#	include <Gwen/UnitTest/UnitTest.h>
#	include <Gwen/Renderers/OpenGL_DebugFont.h>
#endif

// CUSTOM
#include <htp/lua.hpp>
#include <htp/input.hpp>
#include <htp/render.hpp>
#include <htp/util/timer.hpp>

int main( int argc, char *argv[] )
{
	HTP::util::Timer timer_loadtime;

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
	std::cout << "[i] Loading took " << timer_loadtime.get_duration() << "." << std::endl;
	
	HTP::render::glApp glApp;
	if( glApp.init() == false ) {
		return 1;
	}
	timer_loadtime.start();
	scriptHook.onInit( scriptEngine );
	std::cout << "[i] Init took " << timer_loadtime.get_duration() << "." << std::endl;
	HTP::lua::dofunction( scriptEngine, "init" );
	glfwSetWindowTitle( "Engine | HackThePlanet" );

	#ifdef HTP_USE_GWEN
	// Setting up Gwen
	
	Gwen::Renderer::OpenGL *pRenderer = new Gwen::Renderer::OpenGL_DebugFont();
	Gwen::Skin::TexturedBase skin;
	skin.SetRender( pRenderer );
	skin.Init( "data/DefaultSkin.png" );
	Gwen::Controls::Canvas *pCanvas = new Gwen::Controls::Canvas( &skin );
	pCanvas->SetSize( 640,480 );
	pCanvas->SetDrawBackground( true );
	pCanvas->SetBackgroundColor( Gwen::Color( 150, 170, 170, 255 ) );

	UnitTest *pUnit = new UnitTest( pCanvas );
	pUnit->SetPos( 10, 10 );
	#endif /* HTP_USE_GWEN */

	int running = GL_TRUE;
	std::cout << "[i] Running main rendering/interactive loop." << std::endl;
	while( running )
	{
		running = !glfwGetKey( GLFW_KEY_ESC ) && glfwGetWindowParam( GLFW_OPENED );
		glClear( GL_COLOR_BUFFER_BIT );
		#ifdef HTP_USE_GWEN
		pCanvas->RenderCanvas();
		#endif
		glApp.Draw();

	}
	glfwTerminate();
	// Ending scriptHook
    scriptHook.onExit( scriptEngine );
	// Ending lua scriptEngine
    HTP::lua::endState(scriptEngine);
    return 0;
}
