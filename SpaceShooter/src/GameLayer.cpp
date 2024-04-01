#include "GameLayer.h"

using namespace Unique;

GameLayer::GameLayer()
	: Layer("GameLayer")
{
	m_GameFlowStateMachine = new GameFlowStateMachine(this);
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

