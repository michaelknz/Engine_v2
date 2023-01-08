workspace "Engine"
	configurations { "Debug", "Release" }
	startproject "Sandbox"
	dependson { "Engine", "Sandbox" }

project "Engine"
	kind "StaticLib"
	location "%{prj.name}"
    language "C++"
	architecture "x64"
	targetdir "%{wks.location}/bin/%{prj.name}/%{cfg.buildcfg}"
	objdir ("%{wks.location}/bin-int/%{prj.name}/%{cfg.buildcfg}")
	libdirs {"%{wks.location}/%{prj.name}/lib/glad/%{cfg.buildcfg}", "%{wks.location}/%{prj.name}/lib/glfw/%{cfg.buildcfg}", "%{wks.location}/%{prj.name}/lib/soil/%{cfg.buildcfg}"}
	links{"Glad.lib", "glfw3.lib", "SOIL.lib"}
	includedirs {"%{wks.location}/%{prj.name}/include/glad", "%{wks.location}/%{prj.name}/include/glfw", "%{wks.location}/Engine/include/soil", "%{wks.location}/%{prj.name}/src"}

	vpaths {
    ["Headers"] = { "**.h", "**.hpp" },
    ["Sources"] = {"**.c", "**.cpp"}
    }

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"}

	filter { "configurations:Debug" }
		symbols "On"

	filter { "configurations:Release" }
		optimize "On"

	filter { "system:windows" }
		links { "OpenGL32" }

	filter { "system:not windows" }
		links { "GL" }

project "Sandbox"
	kind "ConsoleApp"
	location "%{prj.name}"
	language "C++"
	architecture "x64"
	targetdir "%{wks.location}/bin/%{prj.name}/%{cfg.buildcfg}"
	objdir ("%{wks.location}/bin-int/%{prj.name}/%{cfg.buildcfg}")
	libdirs "%{wks.location}/bin/Engine/%{cfg.buildcfg}"
	links {"Engine.lib"}
	includedirs{"%{wks.location}/Engine/src", "%{wks.location}/Engine/include/glad", "%{wks.location}/Engine/include/glfw", "%{wks.location}/%{prj.name}/src"}

	vpaths {
    ["Headers"] = { "**.h", "**.hpp" },
    ["Sources"] = {"**.c", "**.cpp"},
	["Shaders"] = {"**.vert", "**.frag"},
    }

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/shaders/**.vert",
		"%{prj.name}/shaders/**.frag"}

	filter { "configurations:Debug" }
		symbols "On"

	filter { "configurations:Release" }
		optimize "On"