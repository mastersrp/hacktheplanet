#include <htp/config.hpp>
#ifndef HTP_USE_NCURSES
#include <iostream>

#include <htp/render/glApp.hpp>
#if defined( HTP_GL_IRRLICHT )
#include <irrlicht/irrlicht.h>
#endif

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
			#if defined( HTP_GL_IRRLICHT )
			device = irr::createDevice( irr::video::EDT_OPENGL, irr::core::dimension2d< irr::u32 >( 640, 480 ), 24, false, false, false, 0 );
			if (!device) 
			{
				return 1;
			}
			device->setWindowCaption( L"Hello World" );
			#endif
			return 0;
		}

		#if defined( HTP_GL_IRRLICHT )
		irr::IrrlichtDevice *glApp::getDevice()
		{
			return this->device;
		}
		#endif

		void glApp::Draw()
		{
			#if defined( HTP_GL_IRRLICHT )
			device->getVideoDriver()->beginScene( true, true, irr::video::SColor( 255, 100, 101, 140 ) );
			
			device->getSceneManager()->drawAll();
			device->getGUIEnvironment()->drawAll();

			device->getVideoDriver()->endScene();
			#endif
		}
	}
}

#endif /* !HTP_USE_NCURSES */
