project "Engine"
	kind "SharedLib"
	language "C++"
	cppdialect "C++20"
	targetdir "Binaries/%{cfg.buildcfg}"
	staticruntime "off"

	defines
	{
		"AE_PLATFORM_WINDOWS",
		"AE_BUILD_DLL",
		"AE_ENABLE_ASSERTS"
	}
	
	pchheader "aepch.h"
	pchsource "Source/aepch.cpp"
	
	files { "Source/**.h", "Source/**.cpp" }

	includedirs
	{
		"Source",
	  
		-- Include Third Party
		"../Vendor/Binaries/spdlog/include",
		"../Vendor/Binaries/imgui-docking",
		"../Vendor/Binaries/imgui-docking/backends",
		"../Vendor/Binaries/SDL2/include",
		"$(VULKAN_SDK)/include"
	}
	
	links
	{
		"../Vendor/Binaries/SDL2/lib/x64/SDL2",
		"../Vendor/Binaries/SDL2/lib/x64/SDL2main",
		"$(VULKAN_SDK)/Lib/vulkan-1"
	}

	targetdir ("../Binaries/" .. OutputDir .. "/%{prj.name}")
	objdir ("../Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")
	
	filter "system:windows"
		systemversion "latest"
		defines { }
	
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