include( "../fastcxx/build" )

solution "HackThePlanet"
	configurations { "Debug", "Release" }
	libdirs { "../lib" }
	includedirs { "../include", "../fastcxx/include" }
	location( "projects/" .. _ACTION )
	
	configuration "Debug"
		defines { "_DEBUG", "VIVOS_USE_NAMESPACE", "VIVOS_HEADER_ONLY" }
		flags { "Symbols" }
	
	configuration "Release"
		defines { "VIVOS_USE_NAMESPACE", "VIVOS_HEADER_ONLY" }
		flags { "Optimize", "StaticRuntime" }

	project "kernel"
		kind "StaticLib"
		targetdir "../lib/kernel"
		language "C++"
		files { "../src/kernel/**.cpp" }

	project "renderer"
		kind "StaticLib"
		targetdir "../lib/renderer"
		language "C++"
		files { "../src/render/**.cpp" }

	project "hacktheplanet"
		kind "WindowedApp"
		targetdir "../bin"
		language "C++"
		files { "../game/**.cpp" }
		links { "kernel", "renderer" }
