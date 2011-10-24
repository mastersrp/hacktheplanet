#ifndef HTP_RENDER_GLAPP
#define HTP_RENDER_GLAPP

#include <config.hpp>
// OpenGL
#include <GL/gl.h>
#include <GL/glut.h>

namespace HTP {
	namespace render {
		class glApp
		{
			private:
				bool isrunning,ispaused;
			public:
				glApp();

				void init();
				bool Running();
				void Draw();
		};
	}
}

#endif /* HTP_RENDER_GLAPP */
