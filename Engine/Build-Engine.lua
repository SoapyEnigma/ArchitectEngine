project "Engine"
	kind "SharedLib"
	language "C++"
	cppdialect "C++20"
	targetdir "Binaries/%{cfg.buildcfg}"
	staticruntime "off"

	defines
	{
		"WW_PLATFORM_WINDOWS",
		"WW_BUILD_DLL"
	}
	
	files { "Source/**.h", "Source/**.cpp" }

	includedirs
	{
		"Source",
	  
		-- Include Third Party
		"../Vendor/Binaries/spdlog/include",
		"../Vendor/Binaries/imgui-docking",
		"../Vendor/Binaries/imgui-docking/backends"
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