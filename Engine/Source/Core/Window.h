#pragma once

#include "aepch.h"

#include "Core/Defines.h"
#include "Events/Event.h"

namespace AE
{
	struct WindowProps
	{
		std::string title;
		u32 width;
		u32 height;

		WindowProps(const std::string& title = "Architect Engine",
			u32 width = 1280,
			u32 height = 720)
			: title(title), width(width), height(height) {}
	};

	class AE_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual u32 GetWidth() const = 0;
		virtual u32 GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}