project "Testbed"
	kind "ConsoleApp"
	targetdir "../Testbed/Bin/%{cfg.buildcfg}"
	objdir "../Testbed/Bin/%{cfg.buildcfg}"
	
	dependson "Engine"
	
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