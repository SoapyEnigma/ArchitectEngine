#pragma once

#include "Core/Defines.h"
#include "Events/Event.h"

namespace AE
{
	class AE_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return _DebugName; }

	protected:
		std::string _DebugName;
	};
}
