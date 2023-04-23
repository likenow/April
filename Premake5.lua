workspace "April"
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
IncludeDir["GLFW"] = "April/vendor/GLFW/include"
IncludeDir["Glad"] = "April/vendor/Glad/include"
IncludeDir["ImGui"] = "April/vendor/imgui"

include "April/vendor/GLFW"
include "April/vendor/Glad"
include "April/vendor/imgui"

project "April"
    location "April"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "alpch.h"
    pchsource "April/src/alpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}"
    }

    links 
    { 
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "on"
        systemversion "latest"
        
        defines
        {
            "AL_PLATFORM_WINDOWS",
            "AL_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "AL_DEBUG"
        buildoptions "/MDd"
        symbols "on"

    filter "configurations:Release"
        defines "AL_RELEASE"
        buildoptions "/MDd"
        optimize "on"

    filter "configurations:Dist"
        defines "AL_Dist"
        buildoptions "/MDd"
        optimize "on"


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
        staticruntime "on"
        systemversion "latest"
        
        defines
        {
            "AL_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "AL_DEBUG"
        buildoptions "/MDd"
        symbols "on"

    filter "configurations:Release"
        defines "AL_RELEASE"
        buildoptions "/MDd"
        optimize "on"

    filter "configurations:Dist"
        defines "AL_Dist"
        buildoptions "/MDd"
        optimize "on"