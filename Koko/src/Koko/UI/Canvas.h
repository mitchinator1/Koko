#ifndef CANVAS_H
#define CANVAS_H
#include "Element.h"
#include "Koko/Mesh/Mesh.h"

namespace Koko
{
	class Event;
	class MouseMovedEvent;
	class MouseButtonPressedEvent;

	class Canvas
	{
	public:
		float X, Y;
		float Width, Height;

	private:
		std::unique_ptr<Mesh> m_Mesh;
		std::vector<Element*> m_Elements;

	public:
		Canvas(float x, float y, float width, float height);

		void OnUpdate();
		void OnEvent(Event& e);
		
		void AddElement(Element* e);
		void RemoveElement(Element* e);

		inline auto GetMesh() { return m_Mesh.get(); }

	private:
		std::vector<float> ToScreenSpace(std::vector<float>& vertices);

		void CreateMesh();

		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
	};
	
}

#endif