#ifndef HTP_RENDER_HPP
#define HTP_RENDER_HPP
#include <config.hpp>
#ifdef HTP_USE_NCURSES
#	include <htp/render/ncApp.hpp>
#elif defined HTP_USE_GL
#	include <htp/render/glApp.hpp>
#endif
#include <htp/render/App.hpp>

#endif /* HTP_RENDER_HPP */
