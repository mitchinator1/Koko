#include "Sandbox2D.h"

#include <GLM/gtc/matrix_transform.hpp>
#include <GLM/gtc/type_ptr.hpp>

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1920.0f / 1080.0f, true)
{
	
}

void Sandbox2D::OnAttach()
{
	KK_PROFILE_FUNCTION();
	
	m_CheckerboardTexture = Koko::Texture2D::Create("assets/textures/Checkerboard.png");
}

void Sandbox2D::OnDetach()
{
	KK_PROFILE_FUNCTION();
	//TODO: cleanup
}

void Sandbox2D::OnUpdate(Koko::Timestep ts)
{
	KK_PROFILE_FUNCTION();
	
	// Update
	m_CameraController.OnUpdate(ts);

	// Render
	Koko::Renderer2D::ResetStats();
	{
		KK_PROFILE_SCOPE("Renderer Prep");
		Koko::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Koko::RenderCommand::Clear();
	}

	{
		static float rotation = 0.0f;
		rotation += ts * 40.0f;

		KK_PROFILE_SCOPE("Renderer Draw");
		Koko::Renderer2D::BeginScene(m_CameraController.GetCamera());
		Koko::Renderer2D::DrawRotatedQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, 30.0f, { 0.8f, 0.2f, 0.3f, 1.0f });
		Koko::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.5f, 0.7f, 0.8f, 1.0f });
		Koko::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, m_CheckerboardTexture, 10.0f);
		Koko::Renderer2D::DrawRotatedQuad({ 0.0f, 0.0f, 0.0f }, { 1.0f, 1.0f }, rotation, m_CheckerboardTexture, 20.0f);
		Koko::Renderer2D::EndScene();

		Koko::Renderer2D::BeginScene(m_CameraController.GetCamera());
		for (float y = -5.0f; y < 5.0f; y += 0.5f)
		{
			for (float x = -5.0f; x < 5.0f; x += 0.5f)
			{
				glm::vec4 color = { (x + 5.0f) / 10.0f, 0.4f, (y + 5.0f) / 10.0f, 0.7f };
				Koko::Renderer2D::DrawQuad({ x, y }, { 0.45f, 0.45f }, color);
			}
		}
		Koko::Renderer2D::EndScene();
	}
}

//void Sandbox2D::OnImGuiRender()
//{
//	KK_PROFILE_FUNCTION();
//
//	ImGui::Begin("Settings");
//
//	auto stats = Koko::Renderer2D::GetStats();
//	ImGui::Text("Renderer2D Stats:");
//	ImGui::Text("Draw Calls: %d", stats.DrawCalls);
//	ImGui::Text("Quads: %d", stats.QuadCount);
//	ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
//	ImGui::Text("Indices: %d", stats.GetTotalIndexCount());
//
//	ImGui::End();
//}

void Sandbox2D::OnEvent(Koko::Event& e)
{
	m_CameraController.OnEvent(e);
}