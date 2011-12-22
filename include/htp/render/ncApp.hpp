#ifndef HTP_RENDER_NCAPP_HPP
#define HTP_RENDER_NCAPP_HPP

#include <htp/config.hpp>
#ifdef HTP_USE_NCURSES

namespace HTP {
	namespace render {
		class ncApp {
			private:
				bool running;
			public:
				ncApp();

				virtual bool init();
				virtual bool isRunning();
				virtual void SetRunning( int inputch );
		};
	}
}

#endif /* HTP_USE_NCURSES */
#endif /* HTP_RENDER_NCAPP_HPP */
