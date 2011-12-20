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

				virtual bool init();
				virtual bool isRunning();
				virtual void SetRunning( int inputch );
		};
	}
}

#endif /* HTP_RENDER_NCAPP_HPP */
