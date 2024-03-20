#pragma once

#include "Core/Defines.h"
#include "Core/Window.h"

namespace AE
{
	class AE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void OnEvent(Event& e);

		void Run();

	private:
		std::unique_ptr<Window> _Window;
		bool _Running = true;
	};

	Application* CreateApplication();
}
