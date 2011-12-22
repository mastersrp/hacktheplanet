#include <htp/config.hpp>
#ifdef HTP_USE_NCURSES
#include <ncurses.h>
#include <htp/render/ncApp.hpp>

HTP::render::ncApp::ncApp()
{
	initscr();
	refresh();
	running = true;
}

bool HTP::render::ncApp::init()
{
	return true;
}

bool HTP::render::ncApp::isRunning()
{
	return running;
}

void HTP::render::ncApp::SetRunning( int inputch )
{
	if( inputch == 1 )
	{
		// TODO:
		// Add proper cleanup code here, or a call to cleanup what's been done.
		running = false;
	}
}
#endif /* HTP_USE_NCURSES */
