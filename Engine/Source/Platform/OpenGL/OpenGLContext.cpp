#include "aepch.h"

#include <glad/glad.h>
#include "OpenGLContext.h"

namespace AE
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: _WindowHandle(windowHandle)
	{
		AE_ENGINE_ASSERT(windowHandle, "Window handle is null!");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		AE_ENGINE_ASSERT(status, "Failed to initialize glad!");
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(_WindowHandle);
	}
}