#include "aepch.h"

#include "Core/Application.h"
#include "Core/Log.h"

#include "Events/ApplicationEvent.h"

namespace AE
{
	Application::Application()
	{
		_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (_Running)
		{
			_Window->OnUpdate();
		}
	}
}