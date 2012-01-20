/*
 * This file is part of the HackThePlanet project
 * License is in COPYING.txt file.
 */
#ifndef HTP_APP_HPP
#define HTP_APP_HPP
#include <htp/config.hpp>
#include <script.hpp>
#include <htp/render.hpp>

namespace HTP {
	class App {
		public:
			App();
			virtual ~App();

			virtual render::glApp *getRenderer();
			virtual script::state *getScriptState();
			virtual script::hook *getScriptHook();
		private:
			render::glApp *renderer;
			script::state *scriptState;
			script::hook *scriptHook;
	};
}

#endif /* HTP_APP_HPP */
