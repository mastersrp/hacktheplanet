#include <config.hpp>
#ifdef HTP_USE_NCURSES
#include <ncurses.h>
#endif
#include <htp/render/App.hpp>
int HTP::render::App::ProcessInput()
{
	#ifdef HTP_USE_NCURSES
	int ch = getch();
	switch( ch )
	{
		case KEY_F(11):
			return 1;
			break;
	}
	#endif
}
