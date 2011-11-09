#include <config.hpp>
#include <ncurses.h>
#include <htp/render/ncApp.hpp>

HTP::render::ncApp::ncApp()
{
	isrunning = true;
}

bool HTP::render::ncApp::init()
{
	return true;
}

bool HTP::render::ncApp::running()
{
	return isrunning;
}
