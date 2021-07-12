#pragma once

#include "Koko/Core/Layer.h"

#include "Koko/Events/ApplicationEvent.h"
#include "Koko/Events/KeyEvent.h"
#include "Koko/Events/MouseEvent.h"

namespace Koko {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();

		void BlockEvents(bool block) { m_BlockEvents = block; }

		void SetDarkThemeColors();
	private:
		bool m_BlockEvents = true;
	};

}