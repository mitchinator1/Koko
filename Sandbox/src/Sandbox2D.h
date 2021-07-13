#ifndef SANDBOX_2D_H
#define SANDBOX_2D_H

#include "Koko.h"

class Sandbox2D : public Koko::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Koko::Timestep ts) override;
	//virtual void OnImGuiRender() override;
	void OnEvent(Koko::Event& e) override;
private:
	Koko::OrthographicCameraController m_CameraController;

	Koko::Ref<Koko::Texture2D> m_CheckerboardTexture;

	struct ProfileResult
	{
		const char* Name;
		float Time;
	};

	std::vector<ProfileResult> m_ProfileResults;
};

#endif