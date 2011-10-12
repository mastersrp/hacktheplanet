/*
 * This file is part of the HackThePlanet project.
 * License is in COPYING file.
 */
#ifndef HTP_LUA_HOOK_HPP
#define HTP_LUA_HOOK_HPP

#include <config.hpp>
// STD LIBS
#include <iostream>
// LUA
#include <lua.hpp>

namespace HTP {
    namespace lua {
	class hook {
	    public:
			int onInit(lua_State *scriptEngine);
			int onExit(lua_State *scriptEngine);
			int onCustom(lua_State *scriptEngine, const char *hook );
	};
	}
}

#endif /* LUA_HOOK_HPP */
