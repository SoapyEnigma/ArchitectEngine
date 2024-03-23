#pragma once

#include "Core/Window.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

namespace AE
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline u32 GetWidth() const override { return _Data.width; }
		inline u32 GetHeight() const override { return _Data.height; }

		inline void SetEventCallback(const EventCallbackFn& callback) override { _Data.eventCallback = callback;  }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		inline virtual void* GetNativeWindow() const { return _Window; }

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

	private:
		GLFWwindow* _Window;

		struct WindowData
		{
			std::string title;
			u32 width;
			u32 height;
			bool vSync;

			EventCallbackFn eventCallback;
		};

		WindowData _Data;
	};
}

