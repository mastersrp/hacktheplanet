#ifndef HTP_CONFIG_HPP
#define HTP_CONFIG_HPP

/* CONFIGURATION LISTED BELOW */

// Graphical/Visual configurations
#define HTP_GL_IRRLICHT		// irrLicht + OpenGL
//#define HTP_GL_SDL		// SDL 2.0
//#define HTP_USE_GWEN		// Skinable GUI system written by the creator of Garry's Mod; Garry Newman

#define SCRIPT_USE_CUSTOM_CONFIG
#define SCRIPT_TYPE angelscript // Use AngelScript for our script engine

#define BEGIN_HTP_NAMESPACE namespace HTP {
#define END_HTP_NAMESPACE }

/* CONFIGURATION LISTED ABOVE */

#ifdef __GXX_EXPERIMENTAL_CXX0X__
	#define HTP_CXX0X
#endif

#endif /* CONFIG_HPP */
