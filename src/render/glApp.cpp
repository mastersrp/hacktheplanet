#include <config.hpp>
#include <htp/render/glApp.hpp>
#include <GL/gl.h>
#include <GL/glut.h>

HTP::render::glApp::glApp()
{
	isrunning = false;
	ispaused = false;
}

void HTP::render::glApp::init()
{
	isrunning = true;
}

bool HTP::render::glApp::Running()
{
	if( isrunning == true && ispaused == false )
	{
		isrunning = false;
		return isrunning;
	}
	isrunning = false;
	return true;
}

void HTP::render::glApp::Draw()
{
}
