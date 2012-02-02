/*
 * This file is part of the HackThePlanet project
 * License is in COPYING.txt file.
 */
#include <htp/config.hpp>
#include <htp/App.hpp>

namespace HTP {
	App::App( int argc, char *argv[] )
	{
		this->renderer = new render::glApp();
		this->scriptState = new script::state();
		this->scriptHook = new script::hook();
		this->fileSystem = new kernel::filesystem( argv[0] );
	}

	App::~App()
	{
		this->renderer->getDevice()->drop();
		delete renderer;
		delete scriptState;
		delete scriptHook;
		delete fileSystem;
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

	kernel::filesystem *App::getFileSystem()
	{
		return this->fileSystem;
	}


}
