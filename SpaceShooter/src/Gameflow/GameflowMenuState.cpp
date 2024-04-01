#include "GameflowMenuState.h"
using namespace Unique;

void GameflowMenuState::Enter(GameLayer* layer)
{
	UQ_INFO("Game Menu");
	m_Start = false;
}

void GameflowMenuState::OnEvent(Unique::Event& e)
{
	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<MouseButtonPressedEvent>(UQ_BIND_EVENT_FN(GameflowMenuState::OnMouseButtonPressed));
}

void GameflowMenuState::OnUpdate(GameLayer* layer, Unique::Timestep ts)
{
	m_Time += ts;
	if ((int)(m_Time * 10.0f) % 8 > 4)
		m_Blink = !m_Blink;

	if (m_Start)
		layer->GetFlowStateMachine()->ChangeState(GameFlowState::Game);
}

void GameflowMenuState::OnRender(GameLayer* layer)
{
}

void GameflowMenuState::OnImGuiRender(GameLayer* layer)
{
	auto window = static_cast<sf::RenderWindow*>(Unique::Application::Get().GetWindow().GetNativeWindow());
	ImVec2 windowCenterPos = window->getSize();
	windowCenterPos.x /= 2.f;
	windowCenterPos.y /= 2.f;

	auto gameOverTextPos = windowCenterPos;
	gameOverTextPos.x -= 300.f;
	gameOverTextPos.y -= 100.f;
	ImGui::GetForegroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[0], 120.0f, gameOverTextPos, 0xffffffff, "Space Shooter");

	auto clickTextPos = windowCenterPos;
	clickTextPos.x -= 160.f;
	clickTextPos.y += 0.f;
	if (m_Blink)
		ImGui::GetForegroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[0], 75.0f, clickTextPos, 0xffffffff, "Click to Play !");

}

void GameflowMenuState::Exit(GameLayer* layer)
{
}


bool GameflowMenuState::OnMouseButtonPressed(Unique::MouseButtonPressedEvent& e)
{
	m_Start = true;
	return false;
}