solution "HackThePlanet"
	configurations { "Debug", "Release" }
	libdirs { "../lib" }
	includedirs { "../include" }
	location( "projects/" .. _ACTION )
	
	configuration "Debug"
		defines { "_DEBUG" }
		flags { "Symbols" }
	
	configuration "Release"
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
