#include "kkpch.h"
#include "LayerBuilder.h"

#include "UILayer.h"
#include "Koko/Entity/EntityDirector.h"

#include "Koko/Utility/Stack.h"

#include "Koko/Shader/ShaderManager.h"

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

		std::string shader;
		std::string shaderPath;

		for (auto& attrib : node.Attributes)
		{
			if (attrib.first == "shader")
			{
				shader = attrib.second;
				continue;
			}
			if (attrib.first == "shaderpath")
			{
				shaderPath = attrib.second;
			}
		}

		if (!shader.empty() & !shaderPath.empty())
		{
			ShaderManager::CreateShader(shader, shaderPath);
			shader.clear();
			shaderPath.clear();
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
				shader = attrib.second;
				continue;
			}
			if (attrib.first == "shaderpath")
			{
				shaderPath = attrib.second;
			}
		}

		if (!shader.empty() & !shaderPath.empty())
		{
			ShaderManager::CreateShader(shader, shaderPath);
			shader.clear();
			shaderPath.clear();
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