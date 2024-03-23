project "App"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	targetdir "Binaries/%{cfg.buildcfg}"
	staticruntime "off"
	
	defines
	{
		"AE_PLATFORM_WINDOWS",
	}
	
	files { "Source/**.h", "Source/**.cpp" }
	
	includedirs
	{
		"Source",
	
		-- Include Engine
		"../Engine/Source",
		
		-- Include Third Party
		"../Vendor/Binaries/spdlog/include",
		"../Vendor/Binaries/imgui/include",
		"../Vendor/Binaries/imgui/backends"
	}
	
	links
	{
		"Engine"
	}
	
	targetdir ("../Binaries/" .. OutputDir .. "/%{prj.name}")
	objdir ("../Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")
	
	filter "system:windows"
		systemversion "latest"
		defines { "WINDOWS" }
	
	filter "configurations:Debug"
		defines { "DEBUG" }
		runtime "Debug"
		symbols "On"
	
	filter "configurations:Release"
		defines { "RELEASE" }
		runtime "Release"
		optimize "On"
		symbols "On"
	
	filter "configurations:Dist"
		defines { "DIST" }
		runtime "Release"
		optimize "On"
		symbols "Off"