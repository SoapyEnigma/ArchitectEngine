-- premake5.lua
workspace "Wormwood"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "Editor"

   -- Workspace-wide build options for MSVC
   filter "system:windows"
      buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

include "Engine/Build-Engine.lua"

include "Editor/Build-Editor.lua"