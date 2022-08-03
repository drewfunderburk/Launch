workspace "Launch"
    architecture "x64"
    configurations { "Debug", "Release", "Dist" }
    startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-$%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Launch/vendor/GLFW/include"
IncludeDir["Glad"] = "Launch/vendor/Glad/include"

include "Launch/vendor/GLFW"
include "Launch/vendor/Glad"

project "Launch"
    location "Launch"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "lnpch.h"
    pchsource "Launch/src/lnpch.cpp"

    files 
    { 
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/src",
        "%{prj.name}/src/Launch",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}"
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
            "LN_PLATFORM_WINDOWS",
            "LN_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir.. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "LN_DEBUG"
        buildoptions "/MDd"
        symbols "On"

    filter "configurations:Release"
        defines "LN_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "LN_DIST"
        buildoptions "/MD"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")

    files 
    { 
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Launch/vendor/spdlog/include",
        "Launch/src",
        "Launch/src/Launch"
    }

    links
    {
        "Launch"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "LN_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "LN_DEBUG"
        buildoptions "/MDd"
        symbols "On"

    filter "configurations:Release"
        defines "LN_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "LN_DIST"
        buildoptions "/MD"
        optimize "On"