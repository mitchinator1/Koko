workspace "Picross"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Picross/vendor/GLFW/include"
IncludeDir["Glad"] = "Picross/vendor/Glad/include"
IncludeDir["GLM"] = "Picross/vendor/GLM"

include "Picross/vendor/GLFW"
include "Picross/vendor/Glad"
include "Picross/vendor/GLM"

project "Picross"
	location "Picross"
	kind "ConsoleApp"
	language "C++"

	targetdir "bin/%{cfg.buildcfg}"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.GLM}"
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "PICROSS_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "PICROSS_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "PICROSS_DIST"
		buildoptions "/MD"
		optimize "On"