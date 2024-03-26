#pragma once

#include "Renderer/GraphicsContext.h"

//#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

struct GLFWwindow;

namespace AE
{
	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;
	
	private:
		GLFWwindow* _WindowHandle;
	};
}