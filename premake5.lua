workspace "Unique"
    architecture "x64"
    startproject "SpaceShooter"
configurations
{
    "Debug",
    "Release",
    "Dist"
}

Outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
IncludeDir = {}
IncludeDir["SFML_ImGui"] = "Unique/vendor/SFML_Imgui"
IncludeDir["glm"] = "Unique/vendor/glm"

group "Dependencies"
    include "Unique/vendor/SFML_Imgui"

group ""
project "Unique"
    location "Unique"
    kind "SharedLib"
    language "C++"
    staticruntime "off"

    targetdir("bin/" .. Outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. Outputdir .. "/%{prj.name}")

    pchheader "uqpch.h"
    pchsource "Unique/src/uqpch.cpp"


    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.SFML_ImGui}/Imgui",
        "%{IncludeDir.SFML_ImGui}/SFML/include",
        "%{IncludeDir.SFML_ImGui}/SFML/src",
        "%{IncludeDir.glm}"
    }

    links 
    {
        "opengl32.lib",
        "SFML_ImGui"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

        defines
        {
             "UQ_BULD_DLL",
             "UQ_PLAFORM_WINDOWS",
             "SFML_STATIC"
        }



    filter "configurations:Debug"
        defines "UQ_DEBUG"
        runtime "Debug"
        symbols "On"
		


    filter "configurations:Release"
        defines "UQ_RELEASE"
        runtime "Release"
        optimize "On"


    filter "configurations:Dist"
        defines "UQ_DIST"
        runtime "Release"
        optimize "On"


project "SpaceShooter"
    location "SpaceShooter"
    kind "ConsoleApp"
    language "C++"
    staticruntime "off"

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
        "Unique/vendor/imgui",
        "%{IncludeDir.glm}"
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
        systemversion "latest"

        defines
        {
             "UQ_PLAFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "UQ_DEBUG"
        runtime "Debug"
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
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "UQ_DIST"
        runtime "Release"
        optimize "On"


project "UniquePlatform"
    location "UniquePlatform"
    kind "ConsoleApp"
    language "C++"
    staticruntime "off"

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
        "%{IncludeDir.glm}"
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
        systemversion "latest"

        defines
        {
             "UQ_PLAFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "UQ_DEBUG"

        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "UQ_RELEASE"

        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "UQ_DIST"
        runtime "Release"
        optimize "On"