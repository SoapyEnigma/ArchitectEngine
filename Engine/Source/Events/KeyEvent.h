#pragma once

#include "Core/Log.h"
#include "Events/Event.h"

namespace AE
{
	class AE_API KeyEvent : public Event
	{
	public:
		inline i32 GetKeyCode() const { return _KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput);

	protected:
		KeyEvent(i32 keycode)
			: _KeyCode(keycode) {}

		i32 _KeyCode;
	};

	class AE_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(i32 keycode, i32 repeatCount)
			: KeyEvent(keycode), _RepeatCount(repeatCount) {}

		inline i32 GetRepeatCount() const { return _RepeatCount;  }

		std::string ToString() const override
		{
			std::string s = fmt::format("KeyPressedEvent: {0} ({1} repeats)\n", _KeyCode, _RepeatCount);
			return s.c_str();
		}

		EVENT_CLASS_TYPE(KeyPressed);

	private:
		i32 _RepeatCount;
	};

	class AE_API KeyReleasedEvent : KeyEvent
	{
	public:
		KeyReleasedEvent(i32 keycode)
			: KeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::string s = fmt::format("KeyReleasedEvent: {0}\n", _KeyCode);
			return s.c_str();
		}

		EVENT_CLASS_TYPE(KeyReleased);
	};
}