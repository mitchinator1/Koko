#ifndef LAYER_BUILDER_H
#define LAYER_BUILDER_H
#include "Koko/Utility/Builder.h"

template <typename T> class Stack;

namespace Koko
{
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
}

#endif