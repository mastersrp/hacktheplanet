/*
 * This file is part of the HackThePlanet project.
 * License is in COPYING file.
 */
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
