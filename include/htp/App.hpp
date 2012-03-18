/*
 * This file is part of the HackThePlanet project
 * License is in COPYING.txt file.
 */
#ifndef HTP_APP_HPP
#define HTP_APP_HPP
#include <htp/config.hpp>
#include <fastcxx/script.hpp>
#include <htp/render.hpp>
#include <htp/kernel.hpp>

namespace HTP {
	class App {
		public:
			App( int argc, char *argv[] );
			virtual ~App();

			virtual render::glApp 			*getRenderer();
			virtual fastcxx::script::State 	*getScriptState();
			virtual fastcxx::script::Hook 	*getScriptHook();
			virtual kernel::filesystem		*getFileSystem();
		private:
			render::glApp 				*renderer;
			fastcxx::script::State		*scriptState;
			fastcxx::script::Hook		*scriptHook;
			kernel::filesystem			*fileSystem;
	};
}

#endif /* HTP_APP_HPP */
