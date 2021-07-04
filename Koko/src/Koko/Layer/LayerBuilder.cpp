#include "kkpch.h"
#include "LayerBuilder.h"

#include "Koko/Layer/UILayer.h"
#include "Koko/Entity/EntityDirector.h"

#include "Koko/Utility/Stack.h"
#include "Koko/UI/Canvas.h"
#include "Koko/UI/DropdownElement.h"

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
				//ui->PushEntity(director.GetUIEntity(n));
			}
			if (n.Name == "Dropdown")
			{
				//ui->PushEntity(director.GetUIDropdown(n));
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
				//layer->PushEntity(director.GetUIEntity(n));
			}
		}

		stack.PushBack(layer);
	}

	void LayerBuilder::Build(Canvas* canvas)
	{
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
			//shader.clear();
			//shaderPath.clear();
		}

		for (auto& n : node.ChildNodes)
		{
			if (n.Name == "Entity")
			{
				//ui->PushEntity(director.GetUIEntity(n));
			}
			if (n.Name == "Dropdown")
			{
				Dropdown* dropdown = new Dropdown();
				dropdown->X = 0.0f;
				dropdown->Y = 20.0f;
				dropdown->Z = 0.0f;
				dropdown->Width = 15.0f;
				dropdown->Height = 15.0f;
				dropdown->R = 90.0f;
				dropdown->G = 30.0f;
				dropdown->B = 18.0f;
				dropdown->A = 100.0f;

				Element* element = new Element();
				element->X = 0.0f;
				element->Y = 15.0f;
				element->Z = 0.0f;
				element->Width = 15.0f;
				element->Height = 15.0f;
				element->R = 19.0f;
				element->G = 13.0f;
				element->B = 85.0f;
				element->A = 100.0f;

				element->GetState().Enable(KK_HIDDEN);

				dropdown->AddElement(element);

				canvas->AddElement(dropdown);


				return;
				//ui->PushEntity(director.GetUIDropdown(n));
			}
		}

	}
} 