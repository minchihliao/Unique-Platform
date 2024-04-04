#include "GameLayer.h"
#include <shlwapi.h>
#include <filesystem>
#include <fstream>
#include <iostream>
using namespace Unique;

GameLayer::GameLayer()
	: Layer("GameLayer")
{
	m_GameFlowStateMachine = new GameFlowStateMachine(this);
	char path[MAX_PATH] = { 0 };
	GetModuleFileNameA(nullptr, path, MAX_PATH);
	std::filesystem::path execPath = std::string(path);
	std::filesystem::path saveDir = execPath.parent_path().parent_path() / "UniquePlatform"/ "PlayerData.json";
	m_PlayerData = new Unique::PlayerData(saveDir.string());
	
}

void GameLayer::OnAttach()
{

	m_GameFlowStateMachine->Init();
	m_GameFlowStateMachine->ChangeState(GameFlowState::Init);
}

void GameLayer::OnDetach()
{
}

void GameLayer::OnUpdate(Timestep ts)
{
	m_GameFlowStateMachine->OnUpdate(ts);
}

void GameLayer::OnRender(Unique::Timestep ts)
{
	m_GameFlowStateMachine->OnRender();
}

void GameLayer::OnImGuiRender()
{
	m_GameFlowStateMachine->OnImGuiRender();
}

void GameLayer::OnEvent(Unique::Event& e)
{
	m_GameFlowStateMachine->OnEvent(e);
	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<WindowResizeEvent>(UQ_BIND_EVENT_FN(GameLayer::OnWindowResize));
	dispatcher.Dispatch<MouseButtonPressedEvent>(UQ_BIND_EVENT_FN(GameLayer::OnMouseButtonPressed));
}

bool GameLayer::OnMouseButtonPressed(Unique::MouseButtonPressedEvent& e)
{
	
	return false;
}

bool GameLayer::OnWindowResize(Unique::WindowResizeEvent& e)
{
	return false;
}

