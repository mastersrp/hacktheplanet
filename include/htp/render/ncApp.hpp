#ifndef HTP_RENDER_NCAPP_HPP
#define HTP_RENDER_NCAPP_HPP

#include <config.hpp>

namespace HTP {
	namespace render {
		class ncApp {
			private:
				bool running;
			public:
				ncApp();

				bool init();
				bool isRunning();
				void SetRunning( int inputch );
		};
	}
}

#endif /* HTP_RENDER_NCAPP_HPP */
