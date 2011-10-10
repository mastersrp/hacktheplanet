/*
 * This file is part of the HackThePlanet project.
 * License is in COPYING file.
 */
#ifndef LUA_DOFUNCTION_HPP
#define LUA_DOFUNCTION_HPP
#include <config.hpp>
// STD LIBS
#include <iostream>
// BOOST C++
#include <boost/filesystem.hpp>
// LUA
#include <lua.hpp>

namespace htp {
    namespace lua {
	template<class input>
	int dofunction( input function );
    }
}
#ifndef LUA_DOFUNCTION
#	define LUA_DOFUNCTION htp::lua::dofunction
#endif
#endif /* LUA_DOFUNCTION_HPP */
