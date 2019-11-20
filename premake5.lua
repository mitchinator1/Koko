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
IncludeDir["stb_image"] = "Hazel/vendor/stb_image"

group "Dependencies"
	include "Koko/vendor/GLFW"
	include "Koko/vendor/Glad"
	include "Koko/vendor/GLM"

project "Koko"
	location "Koko"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "kkpch.h"
	pchsource "Koko/src/kkpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/GLM/GLM/**.hpp",
		"%{prj.name}/vendor/GLM/GLM/**.inl",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.GLM}",
		"%{IncludeDir.stb_image}"
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"KOKO_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
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
	cppdialect "C++17"
	staticruntime "on"

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
		"Koko/vendor",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.GLM}"
	}

	links
	{
		"Glad",
		"Koko"
	}

	filter "system:windows"
		systemversion "latest"

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