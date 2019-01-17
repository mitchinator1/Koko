#ifndef LAYER_BUILDER_H
#define LAYER_BUILDER_H
#include <string>
#include "../Entity/EntityComponent.h"
#include "Utility/Builder.h"

class LayerStack;

class LayerBuilder : public Builder
{
private:
	std::string m_Name;
public:
	LayerBuilder(const std::string& name);
	~LayerBuilder();

	void Build(LayerStack& stack);
};

#endif