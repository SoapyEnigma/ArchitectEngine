#include "aepch.h"

#include "WindowsWindow.h"

#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"

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
			if (SDL_Init(SDL_INIT_VIDEO) != 0)
			{
				AE_ENGINE_ASSERT(0, "Could not initialize SDL2!");
			}

			_SDLInitialized = true;

			_Window = SDL_CreateWindow(props.title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, props.width, props.height, SDL_WINDOW_SHOWN);

			_Surface = SDL_GetWindowSurface(_Window);
		}

		auto SDLWindowResize = [](SDL_Window* window, u32 width, u32 height)
		{
			WindowData& data = *(WindowData*)window;
			
			WindowResizeEvent event(width, height);
			data.eventCallback(event);
			data.width = width;
			data.height = height;
		};
	}

	void WindowsWindow::Shutdown()
	{
		SDL_DestroyWindow(_Window);
	}
}