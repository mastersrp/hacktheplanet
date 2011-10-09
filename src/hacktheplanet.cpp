/*
    This file is part of the HackThePlanet project.
    License is in COPYING file.
*/
// STD LIBS
#include <iostream>
#include <fstream>
#include <string>
// OPENGL
#include <GL/gl.h>
#include <GL/glut.h>
#ifdef __WIN32
#   include <GL/wglext.h>
#else
#   include <GL/glext.h>
#endif
// BOOST C++
#include <boost/random.hpp>
#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

int main( int argc, char *argv[] )
{
    boost::property_tree::ptree settings;
    std::ifstream settings_file;
    settings_file.open("data/settings.json");
    if( !settings_file ) { std::cerr << "Couldn't open 'settings.json'!" << std::endl; return 1; }

    boost::property_tree::read_json( "data/settings.json", settings );
    std::cout << "Please enter your profile name: ";
    char profile_in[256];
    std::cin.getline(profile_in, 255);
    std::string profile = settings.get<std::string>(profile_in, "default" );
    if( profile == "default" )
    {
    	std::cout << "Could NOT find your profile name!" << std::endl;
    }
    std::cout << "Using '" << profile << "' profile." << std::endl;
    std::string profile_skin = settings.get<std::string>("profiles."+settings.get<std::string>(profile,"default")+".skin", "data/DefaultSkin.png" );
    std::cout << "skin:  " << profile_skin << std::endl;
    /*
    // Graphics init
    glutInit();
    glutInitDispayMode( GLUT_SINGLE );
    glutInitWindowSize( 500, 500 );
    glutInitWindowPosition(200,200);
    glutCreateWindow("HackThePlanet");
    */
    return 0;
}
