#ifndef HTP_RENDER_GLAPP_HPP
#define HTP_RENDER_GLAPP_HPP

#include <htp/config.hpp>
#ifndef HTP_USE_NCURSES
#include <irrlicht/irrlicht.h>

namespace HTP {
	namespace render {
		class glApp
		{
			public:
				glApp();
				virtual ~glApp();

				virtual int createDevice();
				virtual irr::IrrlichtDevice *getDevice();
				virtual void Draw();

			private:
				int sizeX, sizeY;

				irr::IrrlichtDevice *device;
		};
	}
}
#endif /* !HTP_USE_NCURSES */
#endif /* HTP_RENDER_GLAPP_HPP */
