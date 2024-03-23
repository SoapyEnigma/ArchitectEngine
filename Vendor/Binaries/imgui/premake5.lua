project "IMGUI"
    kind "StaticLib"
    language "C"

	targetdir ("bin/%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}/%{prj.name}")
    objdir ("bin-int/%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}/%{prj.name}")

	includedirs
	{
		"backends",
		"include",
		
		"../Vendor/Binaries/glfw/include/GLFW"
	}
	
	files 
	{ 
		"include/*.h",
		"include/*.cpp",
		"backends/imgui_impl_opengl3.h",
		"backends/imgui_impl_opengl3.cpp",
		--"backends/imgui_impl_glfw.h",
		--"backends/imgui_impl_glfw.cpp"
	}
	
	links
	{
		"GLFW"
	}

	filter "system:windows"
        staticruntime "On"