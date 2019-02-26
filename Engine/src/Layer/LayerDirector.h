#ifndef LAYER_DIRECTOR_H
#define LAYER_DIRECTOR_H
#include "LayerBuilder.h"

class LayerDirector
{
private:
	LayerBuilder* m_Builder;

public:
	void SetBuilder(LayerBuilder* builder);

};

#endif