#pragma once

#include "Core/Defines.h"
#include "Core/Types.h"

namespace AE
{
	enum class EventType
	{
		None = 0,

		WindowClose,
		WindowResize,
		WindowFocus,
		WindowLostFocus,
		WindowMoved,

		AppTick,
		AppUpdate,
		AppRender,

		KeyPressed,
		KeyReleased,
		KeyTyped,

		MouseButtonPressed,
		MouseButtonReleased,
		MouseMoved,
		MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual i32 GetCategoryFlags() const override { return category; }

	class AE_API Event
	{
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual i32 GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); };

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}

	public:
		bool _Handled = false;
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& event)
			: _Event(event) {}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (_Event.GetEventType() == T::GetStaticType())
			{
				_Event._Handled = func(*(T*)&_Event);
				return true;
			}
			else
			{
				return false;
			}
		}

	private:
		Event& _Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}