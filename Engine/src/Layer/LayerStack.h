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
	void PushBackOverlay(Layer* overlay);
	void PopLayer(Layer* layer);
	void PopOverlay(Layer* overlay);

	std::vector<Layer*>::reverse_iterator begin() { return m_Layers.rbegin(); }
	std::vector<Layer*>::reverse_iterator end() { return m_Layers.rend(); }

	int back() { return (int)m_Layers.size() - 1; }
	int front() { return 0; }

	int size() { return (int)m_Layers.size(); }

	Layer* operator[] (int i)
	{
		return i >= (int)m_Layers.size() ? m_Layers.back() : m_Layers[i];
	}
};

#endif