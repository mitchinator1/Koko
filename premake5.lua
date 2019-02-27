workspace "GameEngine"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Koko/vendor/GLFW/include"
IncludeDir["Glad"] = "Koko/vendor/Glad/include"
IncludeDir["GLM"] = "Koko/vendor/GLM"

include "Koko/vendor/GLFW"
include "Koko/vendor/Glad"
include "Koko/vendor/GLM"

project "Koko"
	location "Koko"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "kkpch.h"
	pchsource "Koko/src/kkpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/GLM/GLM/**.hpp",
		"%{prj.name}/vendor/GLM/GLM/**.inl",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.GLM}",
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"KOKO_PLATFORM_WINDOWS",
			"KOKO_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "KOKO_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "KOKO_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "KOKO_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Koko/src",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.GLM}"
	}

	links
	{
		"Glad",
		"Koko"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"KOKO_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "KOKO_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "KOKO_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "KOKO_DIST"
		runtime "Release"
		optimize "On"