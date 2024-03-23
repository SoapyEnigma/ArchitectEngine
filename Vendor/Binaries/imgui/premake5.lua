project "IMGUI"
    kind "StaticLib"
    language "C"

	targetdir ("bin/%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}/%{prj.name}")
    objdir ("bin-int/%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}/%{prj.name}")

	includedirs
	{
		"backends",
		"include",
		
		"%{wks.location}/Vendor/Binaries/glfw/include",
		--"../Vendor/Binaries/glfw/src"
	}
	
	files 
	{ 
		"include/*.h",
		"include/*.cpp",
		"backends/imgui_impl_opengl3.h",
		"backends/imgui_impl_opengl3.cpp",
		"backends/imgui_impl_glfw.h",
		"backends/imgui_impl_glfw.cpp",
		--"../Vendor/Binaries/glfw/include/GLFW/*.h",
		--"../Vendor/Binaries/glfw/src/*.h",
		--"../Vendor/Binaries/glfw/src/*.c"
	}
	
	links
	{
		"GLFW"
	}

	filter "system:windows"
        staticruntime "On"