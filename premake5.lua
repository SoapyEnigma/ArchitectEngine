workspace "Citadel"
	language "C++"
	cppdialect "C++20"
	configurations { "Debug", "Release" }
	platforms { "Win64" }
	
	include "Engine"
	include "Testbed"
	
	filter { "platforms:Win64" }
    system "Windows"
    architecture "x86_64"