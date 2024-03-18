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
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/vendor/SFML/include"
    }

    links 
    {
        "opengl32.lib"
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
        libdirs { "%{prj.name}/vendor/SFML/lib" }
       
        links 
        {
            "sfml-graphics-s-d.lib",
            "sfml-window-s-d.lib",
            "sfml-system-s-d.lib",
            "sfml-network-s-d.lib",
            "sfml-audio-s-d.lib",
            "openal32.lib",
            "freetype.lib",
            "winmm.lib",
            "gdi32.lib",
            "flac.lib",
            "vorbisenc.lib",
            "vorbisfile.lib",
            "vorbis.lib",
            "ogg.lib",
            "ws2_32.lib"
            
        }

    filter "configurations:Release"
        defines "UQ_RELEASE"
        buildoptions "/MD"
        optimize "On"
        libdirs { "%{prj.name}/vendor/SFML/lib" }
        links 
        {
            "sfml-system-s.lib",
            "sfml-graphics-s.lib",
            "sfml-audio-s.lib",
            "sfml-window-s.lib",
            "sfml-network-s.lib",
            "openal32.lib",
            "freetype.lib",
            "winmm.lib",
            "gdi32.lib",
            "flac.lib",
            "vorbisenc.lib",
            "vorbisfile.lib",
            "vorbis.lib",
            "ogg.lib",
            "ws2_32.lib"
        }

    filter "configurations:Dist"
        defines "UQ_DIST"
        buildoptions "/MD"
        optimize "On"
        libdirs { "%{prj.name}/vendor/SFML/lib" }
        links 
        {
            "sfml-system-s.lib",
            "sfml-graphics-s.lib",
            "sfml-audio-s.lib",
            "sfml-window-s.lib",
            "sfml-network-s.lib",
            "openal32.lib",
            "freetype.lib",
            "winmm.lib",
            "gdi32.lib",
            "flac.lib",
            "vorbisenc.lib",
            "vorbisfile.lib",
            "vorbis.lib",
            "ogg.lib",
            "ws2_32.lib"
        }

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