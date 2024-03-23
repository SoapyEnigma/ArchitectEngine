#pragma once

#include "Core/Input.h"

namespace AE
{
	class WindowsInput : public Input
	{
	protected:
		virtual bool IsKeyPressedImpl(i32 keycode) override;
		virtual bool IsMouseButtonPressedImpl(i32 button) override;
		virtual std::pair<f32, f32> GetMousePositionImpl() override;
		virtual float GetMouseButtonXImpl() override;
		virtual float GetMouseButtonYImpl() override;
	};
}