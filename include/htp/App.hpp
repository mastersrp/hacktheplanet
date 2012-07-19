/*
 * This file is part of the HackThePlanet project
 * License is in COPYING.txt file.
 */
#ifndef HTP_APP_HPP
#define HTP_APP_HPP
#include <htp/config.hpp>
#include <htp/script/luavm.hpp>
#include <htp/render.hpp>
#include <htp/kernel.hpp>

namespace HTP {
	class App {
		public:
			App( int argc, char *argv[] );
			virtual ~App();

			virtual render::glApp 			*getRenderer();
			virtual script::LuaVM				*getScriptVM();
			virtual kernel::filesystem	*getFileSystem();
		private:
			render::glApp 			*renderer;
			script::LuaVM				*scriptvm;
			kernel::filesystem	*fileSystem;
	};
}

#endif /* HTP_APP_HPP *
