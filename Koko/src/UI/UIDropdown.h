#ifndef UI_DROPDOWN_H
#define UI_DROPDOWN_H
#include "UIEntity.h"

namespace Koko
{
	class UIDropdown : public UIEntity
	{
	public:
		enum class Direction
		{
			Up = 0,
			Right = 1,
			Down = 2,
			Left = 3
		};

	private:
		Direction direction = Direction::Up;

	public:
		~UIDropdown();

		bool OnMouseMovedEvent(MouseMovedEvent& e) override;
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e) override;

		Action GetMousePress() override;

		void AddEntity(Entity* entity) override;

		void SetDirection(Direction d);
		void SetDirection(const std::string& d);

	private:
		bool Reveal();
		bool Hide();

		void UpdateChildPosition(Entity* entity);

	};
}

#endif