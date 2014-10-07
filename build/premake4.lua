solution "HackThePlanet"
	configurations { "Debug", "Release" }
	libdirs { "../lib" }
	includedirs { "../include", "../fastcxx/include" }
	location( "projects/" .. _ACTION )
	
	configuration "Debug"
		defines { "_DEBUG" }
		flags { "Symbols" }
	
	configuration "Release"
		flags { "Optimize", "StaticRuntime" }

	-- Dependencies
	
	project "fastcxx_propertytree"
		kind "StaticLib"
		targetdir "../lib"
		includedirs { "../include", "../fastcxx/include", "../fastcxx/deps/yaml-cpp/include", "../fastcxx/deps/yajl/src" }
		language "C++"
		files { "../fastcxx/source/fastcxx/property_tree/**.cpp", "../fastcxx/deps/yaml-cp/src/**.cpp", "../fastcxx/deps/yajl/src/**.c" }

	project "fastcxx_script"
		kind "StaticLib"
		targetdir "../lib"
		includedirs { "../fastcxx/deps/lua-5.2.0/src", "../fastcxx/include" }
		language "C++"
		files { "../fastcxx/source/fastcxx/script/**.cpp", "../fastcxx/deps/lua-5.2.0/src/**.c" }

	project "fastcxx_filesystem"
		kind "StaticLib"
		includedirs { "../fastcxx/include" }
		language "C++"
		files { "../fastcxx/source/fastcxx/filesystem.cpp", "../fastcxx/source/fastcxx/filesystem/**.cpp" }

	-- Engine Backend

	project "kernel"
		kind "StaticLib"
		targetdir "../lib"
		language "C++"
		files { "../src/kernel/**.cpp" }
		links { "fastcxx_filesystem" }

	project "renderer"
		kind "StaticLib"
		targetdir "../lib"
		language "C++"
		files { "../src/render/**.cpp" }

	-- Engine

	project "hacktheplanet"
		kind "WindowedApp"
		targetdir "../bin"
		language "C++"
		files { "../game/**.cpp" }
		links { "kernel", "renderer", "fastcxx_propertytree", "fastcxx_script", "fastcxx_filesystem", "Irrlicht", "GL", "png", "jpeg", "bz2" }
