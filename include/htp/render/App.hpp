#ifndef HTP_RENDER_APP_HPP
#define HTP_RENDER_APP_HPP

#include <htp/config.hpp>
#include <iostream>
#include <set>

#ifdef HTP_USE_GL
#	include "glApp.hpp"
#elif defined HTP_USE_NCURSES
#	include "ncApp.hpp"
#endif

namespace HTP {
	namespace render {
		#ifdef HTP_USE_GL
		class App : public glApp {
			public:
				int ProcessInput();

			private:
				std::set<char*>	processedKeys;
		};
		#elif defined HTP_USE_NCURSES
		class App : public ncApp {
			public:
				int ProcessInput();
			private:
				std::set<char*>	processedKeys;
		};
		#endif
	}
}

#endif /* HTP_RENDER_APP_HPP */
