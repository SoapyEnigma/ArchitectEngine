#pragma once

#include "Events/Event.h"

namespace AE
{
	class AE_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(u32 width, u32 height)
			: _Width(width), _Height(height) {}

		inline u32 GetWidth() const { return _Width; }
		inline u32 GetHeight() const { return _Height; }

		std::string ToString() const override
		{	
			std::string s = fmt::format("WindowResizeEvent: {}, {}", _Width, _Height);
			return s;
		}

		EVENT_CLASS_TYPE(WindowResize);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);

	private:
		u32 _Width;
		u32 _Height;
	};

	class AE_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
	};

	class AE_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() {}

		EVENT_CLASS_TYPE(AppTick);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
	};

	class AE_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(AppUpdate);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
	};

	class AE_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() {}

		EVENT_CLASS_TYPE(AppRender);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
	};
}