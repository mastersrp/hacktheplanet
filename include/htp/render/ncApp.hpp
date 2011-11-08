#ifndef HTP_RENDER_NCAPP_HPP
#define HTP_RENDER_NCAPP_HPP

#include <config.hpp>

namespace HTP {
	namespace render {
		class ncApp {
			private:
				bool isrunning;
			public:
				ncApp();

				bool init();
				bool running();
		};
	}
}

#endif /* HTP_RENDER_NCAPP_HPP */
