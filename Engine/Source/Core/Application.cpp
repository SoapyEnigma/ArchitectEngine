#include "aepch.h"

#include "Core/Application.h"
#include "Core/Log.h"

#include "Events/ApplicationEvent.h"

namespace AE
{
#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Application::Application()
	{
		_Window = std::unique_ptr<Window>(Window::Create());
		_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application()
	{

	}

	void Application::OnEvent(Event& e)
	{
		AE_APP_INFO("{0}", e);
	}

	void Application::Run()
	{
		while (_Running)
		{
			_Window->OnUpdate();
		}
	}
}