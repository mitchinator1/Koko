#ifndef LAYER_STACK_H
#define LAYER_STACK_H
#include "Layer.h"
#include <vector>

class LayerStack
{
private:
	std::vector<Layer*> m_Layers;
	std::vector<Layer*>::iterator m_LayerInsert;

public:
	LayerStack();
	~LayerStack();

	void PushLayer(Layer* layer);
	void PushOverlay(Layer* overlay);
	void PopLayer(Layer* layer);
	void PopOverlay(Layer* overlay);

	auto& GetLayer() { return m_Layers; }
	std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
	std::vector<Layer*>::iterator end() { return m_Layers.end(); }
};

#endif