project "Engine"
	kind "StaticLib"
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
		"../Vendor/Binaries/imgui",
		"../Vendor/Binaries/imgui/backends",
		"../Vendor/Binaries/glfw/include",
		"../Vendor/Binaries/glad/include",
		"../Vendor/Binaries/glad/src",
		"../Vendor/Binaries/glm",
	}
	
	links
	{
		"SPDLOG",
		"IMGUI",
		"GLFW",
		"GLAD",
		"opengl32",
	}

	targetdir ("../Binaries/" .. OutputDir .. "/%{prj.name}")
	objdir ("../Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")
	
	postbuildcommands { "{COPYFILE} %[%{!cfg.targetdir}/Engine.dll] %[%{!wks.location}/Binaries/" .. OutputDir .. "/App/]" }
	
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