#include <htp/config.hpp>

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
		};
		#elif defined HTP_USE_NCURSES
		class App : public ncApp {
			public:
				int ProcessInput();
		};
		#endif
	}
}
