project "Engine"
	kind "StaticLib"
	targetdir "../Engine/Bin/%{cfg.buildcfg}"
	objdir "../Engine/Bin/%{cfg.buildcfg}"
	
	files { "**.h", "**.cpp" }

        filter "configurations:Debug"
            runtime "Debug"
            symbols "On"
            defines { "DEBUG" }

        filter "configurations:Release"
            defines { "RELEASE" }
            runtime "Release"
            symbols "Off"
            optimize "Full"