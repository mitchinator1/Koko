#ifndef LAYER_BUILDER_H
#define LAYER_BUILDER_H
#include <string>
#include "Utility/Builder.h"

template <typename T> class Stack;
class Layer;

class LayerBuilder : public Builder
{
private:
	std::string m_Name;
public:
	LayerBuilder(const std::string& name);
	~LayerBuilder();

	void Build(Stack<Layer>& stack);
};

#endif