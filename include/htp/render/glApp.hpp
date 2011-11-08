#ifndef HTP_RENDER_GLAPP_HPP
#define HTP_RENDER_GLAPP_HPP

#include <config.hpp>

namespace HTP {
	namespace render {
		class glApp
		{
			private:
				bool isrunning,ispaused;
				int sizeX,sizeY;
			public:
				glApp();

				bool init();
				bool Running();
				void Draw();
		};
	}
}

#endif /* HTP_RENDER_GLAPP_HPP */
