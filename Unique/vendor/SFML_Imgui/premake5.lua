project "SFML_ImGui"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"
    
    targetdir ("bin/" .. Outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. Outputdir .. "/%{prj.name}")


    -- 全平台通用配置
    includedirs 
    { 
        "SFML/include",
        "Imgui"
    }

    files
    {
        "Imgui/imconfig.h",
        "Imgui/imconfig-SFML.h",
        "Imgui/imgui.h",
        "Imgui/imgui.cpp",
        "Imgui/imgui_draw.cpp",
        "Imgui/imgui_internal.h",
        "Imgui/imgui_tables.cpp",
        "Imgui/imgui-SFML.cpp",
        "Imgui/imgui-SFML.h",
        "Imgui/imgui-SFML_export.h",
        "Imgui/imgui_widgets.cpp",
        "Imgui/imstb_rectpack.h",
        "Imgui/imstb_textedit.h",
        "Imgui/imstb_truetype.h",
        "SFML/include/**.hpp",
        "SFML/include/**.inl"
    }


    -- 通用預處理器定義
    defines
    {
        "SFML_STATIC"
    }

    -- Windows 平台設定
   filter "system:windows"
        systemversion "latest"
        files
        {
            "SFML/src/SFML/Window/Win32/**.cpp",
            "SFML/src/SFML/Window/Win32/**.hpp",
            "SFML/src/SFML/Window/*.cpp",
            "SFML/src/SFML/Window/*.hpp",
            "SFML/src/SFML/System/Win32/**.cpp",
            "SFML/src/SFML/System/Win32/**.hpp",
            "SFML/src/SFML/Network/Win32/**.cpp"
        }
        defines
        {
            "WIN32",
            "_WINDOWS",
            "DEBUG"
        }

     

   -- Linux 平台設定
    filter "system:linux"
    links
    {
        "GL",
        "pthread",
        "dl",
        "rt",
        "X11",
        "udev"
    }
    defines
    {
        "SFML_SYSTEM_LINUX"
    }

   -- macOS 平台設定
    filter "system:macosx"
    links
    {
        "Cocoa.framework",
        "OpenGL.framework",
        "IOKit.framework",
        "CoreVideo.framework"
      }
    defines
    {
        "SFML_SYSTEM_MACOS"
    }


    filter "configurations:Debug"
        systemversion "latest"
        runtime "Debug"
        
        libdirs { "SFML/lib" }

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
        runtime "Release"
        libdirs { "SFML/lib" }
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
