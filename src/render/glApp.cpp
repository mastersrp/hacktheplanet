#include <htp/config.hpp>
#ifndef HTP_USE_NCURSES
#include <iostream>

#include <htp/render/glApp.hpp>
#include <GL/gl.h>
#include <GL/glfw.h>

namespace HTP {
	namespace render {
		glApp::glApp()
		{
			running = false;
			ispaused = false;
			sizeX = 640;
			sizeY = 480;

		}

		bool glApp::init()
		{
			if( glfwInit() == GL_FALSE )
			{
				std::cerr << "Couldn't init glfw!" << std::endl;
				return false;
			}
			if( glfwOpenWindow( sizeX, sizeY, 0, 0, 0, 0, 32, 2, GLFW_WINDOW ) == GL_FALSE )
			{
				std::cerr << "Couldn't open window!" << std::endl;
				glfwTerminate();
				return false;
			}
			isrunning = true;
			return true;
		}

		bool glApp::isRunning()
		{
			if( running == true && ispaused == false )
			{
				glfwSetWindowSize( sizeX, sizeY );
				return isrunning;
			}
			return running;
		}

		void glApp::Draw()
		{
			glfwSwapBuffers();
		}

#endif /* !HTP_USE_NCURSES */
