#include "aepch.h"

#include "Core/Application.h"
#include "Core/Defines.h"
#include "Core/Log.h"

#include "Input.h"

#include "GLFW/glfw3.h"

namespace AE
{
	Application* Application::_Instance = nullptr;

	Application::Application()
	{
		AE_ENGINE_ASSERT(!_Instance, "Application already exists!");
		_Instance = this;

		_Window = std::unique_ptr<Window>(Window::Create());
		_Window->SetEventCallback(AE_BIND_EVENT_FN(Application::OnEvent));

		_ImGuiLayer = new ImGuiLayer();
		PushOverlay(_ImGuiLayer);
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

			_ImGuiLayer->Begin();
			for (Layer* layer : _LayerStack)
				layer->OnImGuiRender();

			_ImGuiLayer->End();

			_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(AE_BIND_EVENT_FN(Application::OnWindowClose));

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