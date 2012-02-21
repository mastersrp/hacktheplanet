#ifndef HTP_RENDER_GLAPP_HPP
#define HTP_RENDER_GLAPP_HPP

#include <htp/config.hpp>
#if defined( HTP_GL_IRRLICHT )
#include <irrlicht/irrlicht.h>
#endif

namespace HTP {
	namespace render {
		class glApp
		{
			public:
				glApp();
				virtual ~glApp();

				virtual int createDevice();
				#if defined( HTP_GL_IRRLICHT )
				virtual irr::IrrlichtDevice *getDevice();
				#endif
				virtual void Draw();

			private:
				int sizeX, sizeY;

				#if defined( HTP_GL_IRRLICHT )
				irr::IrrlichtDevice *device;
				#endif
		};
	}
}
#endif /* HTP_RENDER_GLAPP_HPP */
