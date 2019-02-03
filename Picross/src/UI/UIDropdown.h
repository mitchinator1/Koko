#ifndef UI_DROPDOWN_H
#define UI_DROPDOWN_H
#include "UIEntity.h"

class UIDropdown : public UIEntity
{
public:
	enum class Direction
	{
		Up		= 0,
		Right	= 1,
		Down	= 2,
		Left	= 3
	};

private:
	Direction direction = Direction::Up;

public:
	~UIDropdown();

	std::vector<float> GetVertices() override;

	bool OnMouseMovedEvent(EventEngine::MouseMovedEvent& e) override;
	bool OnMouseButtonPressedEvent(EventEngine::MouseButtonPressedEvent& e) override;

	void AddEntity(Entity* entity) override;

	void SetDirection(Direction d);
	void SetDirection(const std::string& d);

private:
	bool Reveal();
	bool Hide();

};

#endif