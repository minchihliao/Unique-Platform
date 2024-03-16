workspace "Unique"
architecture "x64"

configurations
{
    "Debug",
    "Release",
    "Dist"
}

Outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Unique"
    location "Unique"
    kind "SharedLib"
    language "C++"

    targetdir("bin/" .. Outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. Outputdir .. "/%{prj.name}")

    pchheader "uqpch.h"
    pchsource "Unique/src/uqpch.cpp"


    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
             "UQ_BULD_DLL",
             "UQ_PLAFORM_WINDOWS"
        }



    filter "configurations:Debug"
        defines "UQ_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "UQ_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "UQ_DIST"
        optimize "On"


project "SpaceShooter"
    location "SpaceShooter"
    kind "ConsoleApp"
    language "C++"

    targetdir("bin/" .. Outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. Outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }
      includedirs
    {
        "Unique/vendor/spdlog/include",
        "Unique/src"
    }

    links
    {
        "Unique"
    }

    postbuildcommands
    {
        ("{COPY} ../bin/" .. Outputdir .. "/Unique/Unique.dll %{cfg.targetdir}")
    }


    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
             "UQ_PLAFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "UQ_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "UQ_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "UQ_DIST"
        optimize "On"


project "UniquePlatform"
    location "UniquePlatform"
    kind "ConsoleApp"
    language "C++"

    targetdir("bin/" .. Outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. Outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }
      includedirs
    {
        "Unique/vendor/spdlog/include",
        "Unique/src;"
    }

    links
    {
        "Unique"
    }


    postbuildcommands
    {
        ("{COPY} ../bin/" .. Outputdir .. "/Unique/Unique.dll %{cfg.targetdir}")
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
             "UQ_PLAFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "UQ_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "UQ_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "UQ_DIST"
        optimize "On"