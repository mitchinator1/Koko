#include "LayerBuilder.h"
#include "LayerStack.h"
#include "Entity/Entity.h"

#include "UILayer.h"
#include "Entity/EntityDirector.h"
#include "Entity/EntityBuilder.h"

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
	director.SetBuilder(new EntityBuilder(m_Name));

	UILayer* ui = new UILayer();

	//TODO: Loop through until complete
	ui->PushEntity(director.GetEntity());
	ui->PushEntity(director.GetEntity());

	stack.PushLayer(ui);

}