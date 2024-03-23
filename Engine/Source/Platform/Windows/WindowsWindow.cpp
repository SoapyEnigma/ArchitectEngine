#include "aepch.h"

#include "WindowsWindow.h"

#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"

#include <glad/glad.h>

namespace AE
{
	static bool _GLFWInitialized = false;

	static void GLFWErrorCallback(i32 error, const char* description)
	{
		AE_ENGINE_ERROR("GLFW Error ({0}): {1}", error, description);
	}

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
		glfwPollEvents();
		glfwSwapBuffers(_Window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		glfwSwapInterval(enabled);

		_Data.vSync = enabled;
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

		if (!_GLFWInitialized)
		{
			int success = glfwInit();
			AE_ENGINE_ASSERT(success, "Could not initialize GLFW!");
			glfwSetErrorCallback(GLFWErrorCallback);
			_GLFWInitialized = true;
		}

		_Window = glfwCreateWindow((i32)props.width, (i32)props.height, _Data.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(_Window);

		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		AE_ENGINE_ASSERT(status, "Failed to initialize glad!");

		glfwSetWindowUserPointer(_Window, &_Data);
		SetVSync(true);

		glfwSetWindowSizeCallback(_Window, [](GLFWwindow* window, i32 width, i32 height)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.width = width;
				data.height = height;

				WindowResizeEvent event(width, height);
				data.eventCallback(event);
			});

		glfwSetWindowCloseCallback(_Window, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				WindowCloseEvent event;
				data.eventCallback(event);
			});

		glfwSetKeyCallback(_Window, [](GLFWwindow* window, i32 key, i32 scancode, i32 action, i32 mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					data.eventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					data.eventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					data.eventCallback(event);
					break;
				}
				}
			});

		glfwSetCharCallback(_Window, [](GLFWwindow* window, u32 keycode)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				KeyTypedEvent event(keycode);
				data.eventCallback(event);
			});

		glfwSetMouseButtonCallback(_Window, [](GLFWwindow* window, i32 button, i32 action, i32 mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					data.eventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					data.eventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					MouseButtonPressedEvent event(button);
					data.eventCallback(event);
					break;
				}
				}
			});

		glfwSetScrollCallback(_Window, [](GLFWwindow* window, f64 xOffset, f64 yOffset)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseScrolledEvent event((f32)xOffset, (f32)yOffset);
				data.eventCallback(event);

			});

		glfwSetCursorPosCallback(_Window, [](GLFWwindow* window, f64 xPos, f64 yPos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseMovedEvent event((f32)xPos, (f32)yPos);
				data.eventCallback(event);
			});
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(_Window);
	}
}