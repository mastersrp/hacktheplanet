/*
 * This file is part of the HackThePlanet project.
 * License is in COPYING file.
 */
#ifndef LUA_HOOK_HPP
#define LUA_HOOK_HPP'

#include <config.hpp>
// STD LIBS
#include <iostream>
#include <fstream>
#include <string>
// BOOST C++
#include <boost/filesystem.hpp>
// LUA
#include <lua.hpp>

namespace HTP {
    namespace lua {
	class hook {
	    	lua_State *scriptEngine;
	    public:
	    	hook( lua_State *L);
		int onInit();
		int onExit();
		int onCustom(const char *hook);
	};
    }
}

#endif /* LUA_HOOK_HPP */
