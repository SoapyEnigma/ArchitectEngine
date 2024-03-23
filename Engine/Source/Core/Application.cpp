#include "aepch.h"

#include "Core/Application.h"
#include "Core/Log.h"

#include "GLFW/glfw3.h"

namespace AE
{
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::_Instance = nullptr;

	Application::Application()
	{
		AE_ENGINE_ASSERT(!_Instance, "Application already exists!");
		_Instance = this;

		_Window = std::unique_ptr<Window>(Window::Create());
		_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : _LayerStack)
				layer->OnUpdate();

			_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		//AE_ENGINE_TRACE("{0}", e);

		for (auto it = _LayerStack.end(); it != _LayerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e._Handled)
				break;
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer)
	{
		_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		_Running = false;

		return true;
	}
}