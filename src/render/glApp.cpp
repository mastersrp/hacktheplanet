#include <htp/config.hpp>
#ifndef HTP_USE_NCURSES
#include <iostream>

#include <htp/render/glApp.hpp>
#include <irrlicht/irrlicht.h>

namespace HTP {
	namespace render {
		glApp::glApp()
		{
			sizeX = 640;
			sizeY = 480;
		}

		glApp::~glApp()
		{
		}

		int glApp::createDevice()
		{
			device = irr::createDevice( irr::video::EDT_OPENGL, irr::core::dimension2d< irr::u32 >( 640, 480 ), 24, false, false, false, 0 );
			if (!device) 
			{
				return 1;
			}
			device->setWindowCaption( L"Hello World" );
			return 0;
		}

		irr::IrrlichtDevice *glApp::getDevice()
		{
			return this->device;
		}

		void glApp::Draw()
		{
			device->getVideoDriver()->beginScene( true, true, irr::video::SColor( 255, 100, 101, 140 ) );
			
			device->getSceneManager()->drawAll();
			device->getGUIEnvironment()->drawAll();

			device->getVideoDriver()->endScene();
		}
	}
}

#endif /* !HTP_USE_NCURSES */
