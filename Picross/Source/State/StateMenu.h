#ifndef STATE_MENU_H
#define STATE_MENU_H
#include "StateBase.h"

class Mesh;

namespace State
{
	class StateMenu : public StateBase
	{
	private:
		Mesh* m_Mesh;

	public:
		StateMenu(std::shared_ptr<Display>& display);
		~StateMenu();
		
		void HandleEvents(GameEngine* game)			override;
		void Update(GameEngine* game)				override;
		void Render()						const	override;
	};
}

#endif