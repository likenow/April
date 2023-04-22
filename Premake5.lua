workspace "April"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "April"
	location "April"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22000.0"
		
		defines
		{
			"AL_PLATFORM_WINDOWS",
			"AL_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "AL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "AL_Dist"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"April/vendor/spdlog/include",
		"April/src"
	}

	links
	{
		"April"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22000.0"
		
		defines
		{
			"AL_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "AL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "AL_Dist"
		optimize "On"