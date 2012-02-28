solution "HackThePlanet"
	configurations { "Debug", "Release" }
	libdirs { "lib" }
	includedirs { "include", "deps/**" }
	location( "build/" .. _ACTION )
	
	configuration "Debug"
		defines { "_DEBUG" }
		flags { "Symbols" }
	
	configuration "Release"
		flags { "Optimize", "StaticRuntime" }
	
	project "kernel"
		kind "StaticLib"
		targetdir "lib/kernel"
		language "C++"
		files { "include/**.hpp", "src/kernel/**.cpp" }

	project "render"
		kind "StaticLib"
		targetdir "lib/render"
		language "C++"
		files { "include/**.hpp", "src/render/**.cpp" }

	project "hacktheplannet"
		kind "ConsoleApp"
		targetdir "bin"
		language "C++"
		files { "include/**.hpp", "src/htp/**.cpp" }
		links { "kernel", "render" }
