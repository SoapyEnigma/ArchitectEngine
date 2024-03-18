#pragma once

#include "Defines.h"

namespace ww
{
	class WW_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}
