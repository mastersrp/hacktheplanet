#ifndef LUA_HPP
#define LUA_HPP

#include <config.hpp>
#ifdef OS_UBUNTU
extern "C" {
	#include <lua5.1/lua.h>
	#include <lua5.1/lualib.h>
	#include <lua5.1/lauxlib.h>
}
#else
extern "C" {
	#include <lua.h>
	#include <lualib.h>
	#include <lauxlib.h>
}
#endif

#endif /* LUA_HPP */
