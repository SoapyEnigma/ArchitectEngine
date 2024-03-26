-- premake5.lua
workspace "AE"
	architecture "x64"
	configurations { "Debug", "Release", "Dist" }
	startproject "App"

	-- Workspace-wide build options for MSVC
	filter "system:windows"
		buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }
	
	flags
	{
		"MultiProcessorCompile"
	}

OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

group "Vendor"
	include "Vendor/Binaries/glm/premake5.lua"
	include "Vendor/Binaries/glad/premake5.lua"
	include "Vendor/Binaries/glfw/premake5.lua"
	include "Vendor/Binaries/imgui/premake5.lua"
group ""

include "Engine/Build-Engine.lua"

include "App/Build-App.lua"