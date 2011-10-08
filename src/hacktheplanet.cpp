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
    settings_file.open("settings.json");
    if( !settings_file ) { std::cerr << "Couldn't open 'settings.json'!" << std::endl; return 1; }

    boost::property_tree::read_json( "settings.json", settings );
    
    std::cout << settings.get<std::string>("profile", "default") << std::endl;
    std::string path_data = settings.get<std::string>("paths.data", "data");
    std::cout << "path(data): " << path_data << std::endl;
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
