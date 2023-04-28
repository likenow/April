workspace "April"
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
IncludeDir["GLFW"] = "April/vendor/GLFW/include"
IncludeDir["Glad"] = "April/vendor/Glad/include"
IncludeDir["ImGui"] = "April/vendor/imgui"
IncludeDir["glm"] = "April/vendor/glm"

group "Dependencies"
    include "April/vendor/GLFW"
    include "April/vendor/Glad"
    include "April/vendor/imgui"

group ""

project "April"
    location "April"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "alpch.h"
    pchsource "April/src/alpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}"
    }

    links 
    { 
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        systemversion "latest"
        
        defines
        {
            "AL_PLATFORM_WINDOWS",
            "AL_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }


    filter "configurations:Debug"
        defines "AL_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "AL_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "AL_Dist"
        runtime "Release"
        optimize "on"


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
        "April/vendor/spdlog/include",
        "April/src",
        "April/vendor",
		"%{IncludeDir.glm}"
    }

    links
    {
        "April"
    }

    filter "system:windows"
        systemversion "latest"
        
        defines
        {
            "AL_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "AL_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "AL_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "AL_Dist"
        runtime "Release"
        optimize "on"