/*
 * This file is part of the HackThePlanet project
 * License is in COPYING.txt file.
 */
#include <htp/config.hpp>
#include <htp/App.hpp>

namespace HTP {
	App::App()
	{
		renderer = new render::glApp();
		scriptState = new script::state();
		scriptHook = new script::hook();
	}

	App::~App()
	{
		this->renderer->getDevice()->drop();
		delete renderer;
		delete scriptState;
		delete scriptHook;
	}

	render::glApp *App::getRenderer()
	{
		return this->renderer;
	}

	script::state *App::getScriptState()
	{
		return this->scriptState;
	}

	script::hook *App::getScriptHook()
	{
		return this->scriptHook;
	}


}
