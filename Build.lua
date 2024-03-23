-- premake5.lua
workspace "AE"
	architecture "x64"
	configurations { "Debug", "Release", "Dist" }
	startproject "App"

	-- Workspace-wide build options for MSVC
	filter "system:windows"
		buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

include "Vendor/Binaries/glfw/premake5.lua"

include "Engine/Build-Engine.lua"

include "App/Build-App.lua"