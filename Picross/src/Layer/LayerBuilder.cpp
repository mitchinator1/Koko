#include "LayerBuilder.h"
#include "LayerStack.h"
#include "../Entity/Entity.h"

#include "../Utility/FileProgram.h"

#include "UILayer.h"
#include "../Entity/EntityDirector.h"
#include "../Entity/EntityBuilder.h"

LayerBuilder::LayerBuilder(const std::string& name)
{
	/*FileProgram file("Resources/Data/" + name + ".data");
	while (file.GetLine())
	{

	}*/
}

LayerBuilder::~LayerBuilder()
{

}

void LayerBuilder::Build(LayerStack& stack)
{
	EntityDirector director;
	director.SetBuilder(new EntityBuilder());

	UILayer* ui = new UILayer();
	//TODO: Loop through file to load all entities
	ui->PushEntity(director.GetEntity());
	stack.PushLayer(ui);

	/*UILayer* ui2 = new UILayer();
	ui2->PushEntity(new Entity(30.0f, 30.0f, 15.0f, 10.0f, 80.0f));
	stack.PushOverlay(ui2);

	UILayer* ui1 = new UILayer();
	ui1->PushEntity(new Entity(40.0f, 35.0f, 15.0f, 10.0f, 50.0f, 60.0f, 70.0f));
	stack.PushLayer(ui1);

	UILayer* ui3 = new UILayer();
	ui3->PushEntity(new Entity(35.0f, 32.5f, 15.0f, 10.0f, 0.0f, 100.0f, 0.0f));
	stack.PushBackOverlay(ui3);*/
}