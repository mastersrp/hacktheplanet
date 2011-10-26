#include <config.hpp>
#include <iostream>

#include <htp/render/glApp.hpp>
#include <GL/gl.h>
#include <GL/glfw.h>

HTP::render::glApp::glApp()
{
	isrunning = false;
	ispaused = false;

}

bool HTP::render::glApp::init()
{
	if( glfwInit() == GL_FALSE )
	{
		std::cerr << "Couldn't init glfw!" << std::endl;
		return false;
	}
	if( glfwOpenWindow( 640, 480, 0, 0, 0, 0, 32, 2, GLFW_WINDOW ) == GL_FALSE )
	{
		std::cerr << "Couldn't open window!" << std::endl;
		return false;
	}
	isrunning = true;
}

bool HTP::render::glApp::Running()
{
	if( isrunning == true && ispaused == false )
	{
		return isrunning;
	}
	return isrunning;
}

void HTP::render::glApp::Draw()
{
}
