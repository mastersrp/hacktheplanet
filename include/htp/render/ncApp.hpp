#ifndef HTP_RENDER_NCAPP_HPP
#define HTP_RENDER_NCAPP_HPP

#include <htp/config.hpp>
#ifdef HTP_USE_NCURSES

namespace HTP {
	namespace render {
		class ncApp {
			public:
				ncApp();
				virtual ~ncApp();

				virtual bool init();
				virtual bool isRunning();
				virtual void SetRunning( int inputch );
				virtual void Draw();
			private:
				bool running;
		};
	}
}

#endif /* HTP_USE_NCURSES */
#endif /* HTP_RENDER_NCAPP_HPP */
