#pragma once

#include "Core/Defines.h"
#include "Core/Types.h"

namespace AE
{
	class AE_API Input
	{
	public:
		inline static bool IsKeyPressed(i32 keycode) { return _Instance->IsKeyPressedImpl(keycode); }
		inline static bool IsMouseButtonPressed(i32 button) { return _Instance->IsMouseButtonPressedImpl(button); }
		inline static std::pair<f32, f32> GetMousePosition() { return _Instance->GetMousePositionImpl(); }
		inline static float GetMouseButtonX() { return _Instance->GetMouseButtonXImpl(); }
		inline static float GetMouseButtonY() { return _Instance->GetMouseButtonYImpl(); }

	protected:
		virtual bool IsKeyPressedImpl(i32 keycode) = 0;
		virtual bool IsMouseButtonPressedImpl(i32 button) = 0;
		virtual std::pair<f32, f32> GetMousePositionImpl() = 0;
		virtual float GetMouseButtonXImpl() = 0;
		virtual float GetMouseButtonYImpl() = 0;

	private:
		static Input* _Instance;
	};
}