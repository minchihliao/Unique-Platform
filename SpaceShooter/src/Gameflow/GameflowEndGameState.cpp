#include "GameflowEndGameState.h"
using namespace Unique;

void GameflowEndGameState::Enter(GameLayer* layer)
{
	UQ_INFO("Game EndGame");
	m_Restart = false;
	
}

void GameflowEndGameState::OnEvent(Event& e)
{
	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<MouseButtonPressedEvent>(UQ_BIND_EVENT_FN(GameflowEndGameState::OnMouseButtonPressed));
}

void GameflowEndGameState::OnUpdate(GameLayer* layer, Unique::Timestep ts)
{
	m_Time += ts;
	if ((int)(m_Time * 10.0f) % 8 > 4)
		m_Blink = !m_Blink;

	if(m_Restart)
		layer->GetFlowStateMachine()->ChangeState(GameFlowState::Menu);
}

void GameflowEndGameState::OnRender(GameLayer* layer)
{
}

void GameflowEndGameState::OnImGuiRender(GameLayer* layer)
{
	auto window = static_cast<sf::RenderWindow*>(Unique::Application::Get().GetWindow().GetNativeWindow());
	ImVec2 windowCenterPos = window->getSize();
	windowCenterPos.x /= 2.f;
	windowCenterPos.y /= 2.f;

	auto gameOverTextPos = windowCenterPos;
	gameOverTextPos.x -= 250.f;
	gameOverTextPos.y -= 100.f;
	ImGui::GetForegroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[0], 120.0f, gameOverTextPos, 0xffffffff, "Game Over !");

	auto clickTextPos = windowCenterPos;
	clickTextPos.x -= 160.f;
	clickTextPos.y += 0.f;
	if(m_Blink)
		ImGui::GetForegroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[0], 75.0f, clickTextPos, 0xffffffff, "Click to Play !");

}



void GameflowEndGameState::Exit(GameLayer* layer)
{
	
}


bool GameflowEndGameState::OnMouseButtonPressed(Unique::MouseButtonPressedEvent& e)
{
	m_Restart = true;
	return false;
}