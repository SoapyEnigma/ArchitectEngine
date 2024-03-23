#pragma once

#include "Core/Window.h"
#include "Core/LayerStack.h"

#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

#include "ImGui/ImGuiLayer.h"

namespace AE
{
	class AE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline static Application& Get() { return *_Instance; }
		inline Window& GetWindow() { return *_Window; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

	private:
		static Application* _Instance;
		std::unique_ptr<Window> _Window;
		ImGuiLayer* _ImGuiLayer;
		bool _Running = true;

		LayerStack _LayerStack;
	};

	Application* CreateApplication();
}
