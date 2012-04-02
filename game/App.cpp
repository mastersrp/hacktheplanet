/*
 * This file is part of the HackThePlanet project
 * License is in COPYING.txt file.
 */
#include <htp/config.hpp>
#include <htp/App.hpp>

namespace HTP {
	App::App( int argc, char *argv[] )
	{
		this->renderer 		= new render::glApp();
		this->scriptvm		= new fastcxx::script::LuaVM();
		this->fileSystem 	= new kernel::filesystem( argv[0] );
	}

	App::~App()
	{
		this->renderer->getDevice()->drop();
		delete renderer;
		delete scriptvm;
		delete fileSystem;
	}

	render::glApp *App::getRenderer()
	{
		return this->renderer;
	}

	fastcxx::script::LuaVM *App::getScriptVM()
	{
		return this->scriptvm;
	}

	kernel::filesystem *App::getFileSystem()
	{
		return this->fileSystem;
	}


}
