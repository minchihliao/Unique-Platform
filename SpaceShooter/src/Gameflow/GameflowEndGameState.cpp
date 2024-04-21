#include "GameflowEndGameState.h"
#include <shlwapi.h>
#include <filesystem>
#include <fstream>
#include <iostream>
using namespace Unique;

void GameflowEndGameState::Enter(GameLayer* layer)
{
	UQ_INFO("Game EndGame");
	m_Restart = false;
	
	int currentScore = layer->GetScore();
	int highestScore = layer->GetPlayerData()->GetScore("SpaceShooter");
	UQ_INFO(highestScore);
	if (highestScore < currentScore) {
		layer->GetPlayerData()->UpdateScore("SpaceShooter", currentScore);
		/*char path[MAX_PATH] = { 0 };
		GetModuleFileNameA(nullptr, path, MAX_PATH);
		std::filesystem::path execPath = std::string(path);
		std::filesystem::path saveDir = execPath.parent_path().parent_path() / "UniquePlatform" / "PlayerData.json";
		UQ_INFO(saveDir.string());*/
		layer->GetPlayerData()->SaveToFile();
	}

	
	
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

	/*if(m_Restart)
		layer->GetFlowStateMachine()->ChangeState(GameFlowState::Game);*/
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
	windowCenterPos.y -= 50.f;
	auto gameOverTextPos = windowCenterPos;
	gameOverTextPos.x -= 250.f;
	gameOverTextPos.y -= 100.f;
	ImGui::GetForegroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[0], 120.0f, gameOverTextPos, 0xffffffff, "Game Over !");

	uint32_t playerScore = layer->GetScore();
	ImVec2 scorePos = windowCenterPos;
	scorePos.x -= 150.f;
	scorePos.y += 5.f;
	std::string scoreStr = std::string("Your Score: ") + std::to_string(playerScore);
	ImGui::GetForegroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[0], 65.f, scorePos, 0xffffffff, scoreStr.c_str());

	ImVec2 buttonPos = windowCenterPos;
	buttonPos.x -= 150.f;
	buttonPos.y += 80.f;
	ImGui::SetCursorPos(buttonPos);
	
	ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[1]);
	if (ImGui::Button("Restart Game",ImVec2(300,65))) {
		layer->GetFlowStateMachine()->ChangeState(GameFlowState::Game);
	}
	ImGui::PopFont();

}



void GameflowEndGameState::Exit(GameLayer* layer)
{
	
}


bool GameflowEndGameState::OnMouseButtonPressed(Unique::MouseButtonPressedEvent& e)
{
	m_Restart = true;
	return false;
}