#ifndef LAYER_BUILDER_H
#define LAYER_BUILDER_H
#include <string>
#include "../Entity/EntityComponent.h"

class LayerStack;

class LayerBuilder
{
public:
	LayerBuilder(const std::string& name);
	~LayerBuilder();

	void Build(LayerStack& stack);
};

#endif