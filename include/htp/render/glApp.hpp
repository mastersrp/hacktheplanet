#ifndef HTP_RENDER_GLAPP_HPP
#define HTP_RENDER_GLAPP_HPP

#include <config.hpp>

namespace HTP {
	namespace render {
		class glApp
		{
			private:
				bool running,ispaused;
				int sizeX,sizeY;
			public:
				glApp();

				bool init();
				bool isRunning();
				void Draw();
		};
	}
}

#endif /* HTP_RENDER_GLAPP_HPP */
