#ifndef STATE_BASE_H
#define STATE_BASE_H
#include <memory>
#include "../GameEngine.h"
#include "../Display.h"
//#include "../UI/UIMaster.h"
//#include "../Camera/CameraBase.h"
#include "../Renderer/Renderer.h"

namespace State
{
	class StateBase
	{
	protected:
		std::shared_ptr<Display> s_Display;
		//std::unique_ptr<UI::UIMaster> m_UI;
		//std::shared_ptr<Camera::CameraBase> m_Camera;
		std::unique_ptr<Renderer> m_Renderer;
		
	public:
		StateBase(std::shared_ptr<Display>& display) 
			: s_Display(display)
			//, m_UI(std::make_unique<UI::UIMaster>(display))
			//, m_Camera(std::make_shared<Camera::CameraBase>(display))
			, m_Renderer(std::make_unique<Renderer>(display))
		{}
		virtual ~StateBase() {}

		virtual void Pause() {};
		virtual void Resume() {};

		virtual void HandleEvents(GameEngine* game)			= 0;
		virtual void Update(GameEngine* game)				= 0;
		virtual void Render()						const	= 0;

		void ChangeState(GameEngine* game, std::unique_ptr<State::StateBase> state)
		{
			game->ChangeState(std::move(state));
		}
	};
}

#endif