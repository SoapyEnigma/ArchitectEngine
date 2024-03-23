#pragma once

#include "Core/Log.h"
#include "Events/Event.h"

namespace AE
{
	class AE_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(f32 x, f32 y)
			: _MouseX(x), _MouseY(y) {}

		inline f32 GetX() const { return _MouseX; }
		inline f32 GetY() const { return _MouseY; }

		std::string ToString() const override
		{
			std::string s = fmt::format("MouseMovedEvent: {0}, {1}", _MouseX, _MouseY);
			return s;
		}

		EVENT_CLASS_TYPE(MouseMoved);
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);

	private:
		f32 _MouseX;
		f32 _MouseY;
	};

	class AE_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(f32 xOffset, f32 yOffset)
			: _XOffset(xOffset), _YOffset(yOffset) {}

		inline f32 GetX() const { return _XOffset; }
		inline f32 GetY() const { return _YOffset; }

		std::string ToString() const override
		{
			std::string s = fmt::format("MouseScrolledEvent: {0}, {1}", _XOffset, _YOffset);
			return s;
		}

		EVENT_CLASS_TYPE(MouseScrolled);
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);

	private:
		f32 _XOffset;
		f32 _YOffset;
	};

	class AE_API MouseButtonEvent : public Event
	{
	public:
		inline i32 GetMouseButton() const { return _Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);

	protected:
		MouseButtonEvent(i32 button)
			: _Button(button) {}

		i32 _Button;
	};

	class AE_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(i32 button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::string s = fmt::format("MouseButtonPressedEvent: {0}", _Button);
			return s;
		}

		EVENT_CLASS_TYPE(MouseButtonPressed);
	};

	class AE_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(i32 button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::string s = fmt::format("MouseButtonReleasedEvent: {0}", _Button);
			return s;
		}

		EVENT_CLASS_TYPE(MouseButtonReleased);
	};
}