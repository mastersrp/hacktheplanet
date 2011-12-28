#ifndef HTP_CONFIG_HPP
#define HTP_CONFIG_HPP

/* CONFIGURATION LISTED BELOW */

// Graphical/Visual configurations
#define HTP_USE_NCURSES
//#define HTP_USE_GL		// OpenGL + GLFW
//#define HTP_USE_GWEN		// Skinable GUI system written by the creator of Garry's Mod; Garry Newman

/* CONFIGURATION LISTED ABOVE */

// BELOW IS FALLBACK VALUES
// IF NO VALUES HAVE BEEN SPECIFIED, THESE ARE USED
// DO NOT EDIT BELOW THIS LINE UNLES YOU KNOW WHAT YOU ARE DOING.

//Visual configuration FALLBACK
#ifndef HTP_USE_NCURSES
#	ifndef HTP_USE_GL
#		define HTP_USE_NCURSES
//#		define HTP_USE_GL
#	endif
#endif

#endif /* CONFIG_HPP */
