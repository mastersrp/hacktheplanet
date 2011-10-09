/*
 * This file is part of the HackThePlanet project.
 * License is in COPYING file.
 */
#include <config.hpp>
// STD LIBS
#include <iostream>
#include <fstream>
#include <string>
// BOOST C++
#include <boost/filesystem.hpp>
// LUA
#include <lua.hpp>

namespace htp {
    namespace lua {
	class hook {
	    	lua_State *scriptEngine;
	    public:
	    	hook( lua_State *L);
		int onInit();
		int onExit();
		int onCustom(const char hook);
	};
    }
}
