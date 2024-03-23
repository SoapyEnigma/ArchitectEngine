project "GLAD"
    kind "StaticLib"
    language "C"

	targetdir ("bin/%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}/%{prj.name}")
    objdir ("bin-int/%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}/%{prj.name}")

	includedirs
	{
		"include",
		"src"
	}
	
	files 
	{ 
		"include/glad/glad.h",
		"include/KHR/khrplatform.h",
		"src/glad.c"
	}

	filter "system:windows"
        staticruntime "On"