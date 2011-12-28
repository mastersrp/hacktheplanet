#ifndef HTP_RENDER_GLAPP_HPP
#define HTP_RENDER_GLAPP_HPP

#include <htp/config.hpp>
#ifndef HTP_USE_NCURSES

namespace HTP {
	namespace render {
		class glApp
		{
			private:
				bool running,ispaused;
				int sizeX,sizeY;
			public:
				glApp();
				virtual ~glApp();

				virtual bool init();
				virtual bool isRunning();
				virtual void Draw();
		};
	}
}
#endif /* !HTP_USE_NCURSES */
#endif /* HTP_RENDER_GLAPP_HPP */
