workspace "Unique"
architecture "x64"

configurations
{
    "Debug",
    "Release",
    "Dist"
}

Outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
IncludeDir = {}
IncludeDir["SFML_ImGui"] = "Unique/vendor/SFML_Imgui"

include "Unique/vendor/SFML_Imgui"

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
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.SFML_ImGui}/Imgui",
        "%{IncludeDir.SFML_ImGui}/SFML/include",
        "%{IncludeDir.SFML_ImGui}/SFML/src"
    }

    links 
    {
        "SFML_ImGui.lib",
        "opengl32.lib",
        "SFML_ImGui"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
             "UQ_BULD_DLL",
             "UQ_PLAFORM_WINDOWS",
             "SFML_STATIC"
        }



    filter "configurations:Debug"
        defines "UQ_DEBUG"
        buildoptions "/MDd"
        symbols "On"
		


    filter "configurations:Release"
        defines "UQ_RELEASE"
        buildoptions "/MD"
        optimize "On"


    filter "configurations:Dist"
        defines "UQ_DIST"
        buildoptions "/MD"
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
        "Unique/src",
        "Unique/vendor/SFML/include",
        "Unique/vendor/imgui"
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
        buildoptions "/MDd"
        symbols "On"
        libdirs { "Unique/vendor/SFML/lib" }
       
        links 
        {
            "opengl32.lib",
            "sfml-graphics-d.lib",
            "sfml-window-d.lib",
            "sfml-system-d.lib",
            "sfml-network-d.lib",
            "sfml-audio-d.lib"
        }
       
    filter "configurations:Release"
        defines "UQ_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "UQ_DIST"
        buildoptions "/MD"
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
        buildoptions "/MDd"
        symbols "On"

    filter "configurations:Release"
        defines "UQ_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "UQ_DIST"
        buildoptions "/MD"
        optimize "On"