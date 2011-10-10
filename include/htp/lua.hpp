/*
 * This file is part of the HackThePlanet project.
 * License is in COPYING file.
 */
#include <config.hpp>

#ifdef USE_LUA_HOOK
#	ifndef LUA_DOFUNCTION
#		include <htp/lua/dofunction.hpp>
#	endif
#	include <htp/lua/hook.hpp>
#endif
#ifdef USE_LUA_ERROR_HANDLING
#	include <htp/lua/errorhandling.hpp>
#endif
