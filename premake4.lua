include( "deps/libscript" )
include( "deps/vivos" )

solution "HackThePlanet"
	configurations { "Debug", "Release" }
	libdirs { "lib" }
	includedirs { "include", "deps/libscript/include", "deps/vivos/include" }
	location( "build/" .. _ACTION )
	
	configuration "Debug"
		defines { "_DEBUG", "VIVOS_USE_NAMESPACE", "VIVOS_HEADER_ONLY" }
		flags { "Symbols" }
	
	configuration "Release"
		defines { "VIVOS_USE_NAMESPACE", "VIVOS_HEADER_ONLY" }
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

	project "hacktheplanet"
		kind "ConsoleApp"
		targetdir "bin"
		language "C++"
		files { "include/**.hpp", "src/htp/**.cpp" }
		links { "kernel", "render", "Vivos/vivos" }
