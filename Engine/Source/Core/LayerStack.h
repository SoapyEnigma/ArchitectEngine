#pragma once

#include "Core/Defines.h"
#include "Core/Layer.h"

namespace AE
{
	class AE_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return _Layers.begin(); }
		std::vector<Layer*>::iterator end() { return _Layers.end(); }

	private:
		std::vector<Layer*> _Layers;
		u32 _LayerInsertIndex = 0;
	};
}