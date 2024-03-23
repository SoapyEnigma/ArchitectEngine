#include "aepch.h"
#include "WindowsInput.h"

#include "Core/Application.h"
#include <GLFW/glfw3.h>

namespace AE
{
	Input* Input::_Instance = new WindowsInput();

	bool AE::WindowsInput::IsKeyPressedImpl(i32 keycode)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, keycode);

		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}
	bool WindowsInput::IsMouseButtonPressedImpl(i32 button)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(window, button);

		return state == GLFW_PRESS;
	}
	std::pair<f32, f32> WindowsInput::GetMousePositionImpl()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		f64 xpos;
		f64 ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		return { (f32)xpos, (f32)ypos };
	}
	float WindowsInput::GetMouseButtonXImpl()
	{
		auto [x, y] = GetMousePositionImpl();

		return x;
	}
	float WindowsInput::GetMouseButtonYImpl()
	{
		auto [x, y] = GetMousePositionImpl();

		return y;
	}
}