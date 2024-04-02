workspace "Unique"
    architecture "x64"
    startproject "UniquePlatform"
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
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
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
        systemversion "latest"

        defines
        {
             "UQ_PLAFORM_WINDOWS",
             "SFML_STATIC",
             "_SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING"
        }



    filter "configurations:Debug"
        defines "UQ_DEBUG"
        runtime "Debug"
        symbols "on"
		


    filter "configurations:Release"
        defines "UQ_RELEASE"
        runtime "Release"
        optimize "on"


    filter "configurations:Dist"
        defines "UQ_DIST"
        runtime "Release"
        optimize "on"


project "SpaceShooter"
    location "SpaceShooter"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
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
        "%{prj.name}/src",
        "Unique/vendor/spdlog/include",
        "Unique/src",
        "Unique/vendor/SFML_Imgui/SFML/include",
        "Unique/vendor/SFML_Imgui/Imgui",
        "%{IncludeDir.glm}"
    }

    links
    {
        "Unique"
    }


    filter "system:windows"
        systemversion "latest"

        defines
        {
             "UQ_PLAFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "UQ_DEBUG"
        runtime "Debug"
        symbols "on"

       
    filter "configurations:Release"
        defines "UQ_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "UQ_DIST"
        runtime "Release"
        optimize "on"


project "UniquePlatform"
    location "UniquePlatform"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
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
        "%{prj.name}/src",
        "Unique/vendor/spdlog/include",
        "Unique/src",
        "Unique/vendor/SFML_Imgui/SFML/include",
        "Unique/vendor/SFML_Imgui/Imgui",
        "%{IncludeDir.glm}"
    }

    links
    {
        "Unique"
    }



    filter "system:windows"
        systemversion "latest"

        defines
        {
             "UQ_PLAFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "UQ_DEBUG"
        runtime "Debug"
        symbols "on"

       
    filter "configurations:Release"
        defines "UQ_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "UQ_DIST"
        runtime "Release"
        optimize "on"
