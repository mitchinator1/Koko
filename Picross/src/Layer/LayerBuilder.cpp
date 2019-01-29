#include "LayerBuilder.h"
#include "LayerStack.h"

#include "UILayer.h"
#include "Entity/EntityDirector.h"


LayerBuilder::LayerBuilder(const std::string& name)
	: Builder(name), m_Name(name)
{
	
}

LayerBuilder::~LayerBuilder()
{

}

void LayerBuilder::Build(LayerStack& stack)
{
	EntityDirector director;
	director.SetBuilder(new Builder(m_Name));

	UILayer* ui = new UILayer();

	auto node = GetNode("UI");
	 
	for (auto& n : node.ChildNodes)
	{
		if (n.Name == "Entity")
		{
			ui->PushEntity(director.GetEntity(n));
		}
	}

	stack.PushOverlay(ui);

	Layer* foreground = new Layer();

	node = GetNode("Foreground");

	for (auto& n : node.ChildNodes)
	{
		if (n.Name == "Entity")
		{
			foreground->PushEntity(director.GetEntity(n));
		}
	}

	stack.PushLayer(foreground);

}