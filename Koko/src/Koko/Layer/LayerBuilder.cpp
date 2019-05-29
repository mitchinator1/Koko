#include "kkpch.h"
#include "LayerBuilder.h"

#include "UILayer.h"
#include "Koko/Entity/EntityDirector.h"

#include "Koko/Utility/Stack.h"

namespace Koko
{
	LayerBuilder::LayerBuilder(const std::string& name)
		: Builder(name), m_Name(name)
	{

	}

	LayerBuilder::~LayerBuilder()
	{

	}

	void LayerBuilder::Build(Stack<Layer>& stack)
	{
		EntityDirector director;
		director.SetBuilder(new Builder(m_Name));

		UILayer* ui = new UILayer();

		auto node = GetNodes("UI");

		for (auto& attrib : node.Attributes)
		{
			if (attrib.first == "shader")
			{
				ui->AddShaderName(attrib.second);
				continue;
			}
			if (attrib.first == "shaderpath")
			{
				ui->AddShaderPath(attrib.second);
			}
		}

		for (auto& n : node.ChildNodes)
		{
			if (n.Name == "Entity")
			{
				ui->PushEntity(director.GetUIEntity(n));
			}
			if (n.Name == "Dropdown")
			{
				ui->PushEntity(director.GetUIDropdown(n));
			}
		}

		stack.Push(ui);

		UILayer* layer = new UILayer();

		node = GetNodes("Foreground");

		for (auto& attrib : node.Attributes)
		{
			if (attrib.first == "shader")
			{
				layer->AddShaderName(attrib.second);
				continue;
			}
			if (attrib.first == "shaderpath")
			{
				layer->AddShaderPath(attrib.second);
			}
		}

		for (auto& n : node.ChildNodes)
		{
			if (n.Name == "Entity")
			{
				layer->PushEntity(director.GetUIEntity(n));
			}
		}

		stack.PushBack(layer);
	}

} 