#include <htp/config.hpp>
#ifdef HTP_USE_NCURSES
#include <ncurses.h>
#include <htp/render/ncApp.hpp>

namespace HTP {
	namespace render {
		ncApp::ncApp()
		{
			initscr();
			refresh();
			running = true;
		}

		ncApp::~ncApp()
		{
			endwin();
		}

		bool ncApp::init()
		{
			return true;
		}

		bool ncApp::isRunning()
		{
			return running;
		}

		void ncApp::SetRunning( int inputch )
		{
			if( inputch == 1 )
			{
				// TODO:
				// Add proper cleanup code here, or a call to cleanup what's been done.
				running = false;
			}
		}

		void ncApp::Draw()
		{
			refresh();
		}
	}
}
#endif /* HTP_USE_NCURSES */
