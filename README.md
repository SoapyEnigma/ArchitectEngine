// TODO: Readme

## What is the Architect Engine?
The Architect Engine is a game engine. It is being developed with C++(20) and with Vulkan as it's primary graphics API. It will have various libraries implemented to increase the development speed. Libraries used will be listed below. The goal of this project is to create something fast and lightweight for personal use as well as creating an additional pathway to learn.

## How to build
Make sure to have [Premake5](https://premake.github.io/) installed and set up properly as well as [Microsoft Visual Studio 2022](https://visualstudio.microsoft.com/downloads/?cid=learn-navbar-download-cta). Once you have cloned the project and have Premake5 and VS installed, go to the `Scripts` folder and run the `.bat` file. This will generate `AE.sln`. Open the `.sln` file and build the project. Built files will be generated in a new `Binaries` folder within the main `ArchitectEngine` folder. Copy the `Engine.dll` to the same folder as the `App.exe`. You can now run the engine from either the `.exe` or within visual studio.

## Libraries
- [Vulkan](https://www.vulkan.org/)
- [Vulkan Memory Allocator](https://github.com/GPUOpen-LibrariesAndSDKs/VulkanMemoryAllocator)
- [vk-bootstrap](https://github.com/charles-lunarg/vk-bootstrap/tree/main)
- [SDL2](https://www.libsdl.org/)
- [Dear Imgui (Docking Branch)](https://github.com/ocornut/imgui/tree/docking)
- [sdplog](https://github.com/gabime/spdlog)

## Links
- [Discord Link](https://discord.com/invite/zhhHu5HG8c)
