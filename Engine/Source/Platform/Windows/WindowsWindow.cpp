#include "aepch.h"
#include "WindowsWindow.h"

namespace AE
{
	static bool _SDLInitialized = false;

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::OnUpdate()
	{
		SDL_Event e;
		SDL_PollEvent(&e);
		//SDL_FillRect(_Surface, nullptr, SDL_MapRGB(_Surface->format, 0x00, 0x00, 0x00));
		SDL_UpdateWindowSurface(_Window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		//SDL_RenderSetVSync(, enabled)
	}

	bool WindowsWindow::IsVSync() const
	{
		return _Data.vSync;
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		_Data.title = props.title;
		_Data.width = props.width;
		_Data.height = props.height;

		AE_ENGINE_INFO("Created window: '{0}' with dimensions ({1}, {2})", props.title, props.width, props.height);
	
		if (!_SDLInitialized)
		{
			bool success = false;
			if (SDL_Init(SDL_INIT_VIDEO) == 0)
			{
				success = true;
			}

			AE_ENGINE_ASSERT(success, "Could not initialize SDL2!");

			_Window = SDL_CreateWindow(props.title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, props.width, props.height, SDL_WINDOW_SHOWN);

			_Surface = SDL_GetWindowSurface(_Window);
		}
	}

	void WindowsWindow::Shutdown()
	{
		SDL_DestroyWindow(_Window);
	}
}