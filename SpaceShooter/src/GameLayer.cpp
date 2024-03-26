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

void GameLayer::OnUpdate()
{
	Unique::Ref<Unique::Texture2D> enemy = Unique::SFMLTexture::Create("assets/textures/enemy.png");
	Unique::Renderer2D::DrawSprite(sf::Vector2f(0.1, 0.1), sf::Vector2f(200, 200), enemy);
	Unique::Renderer2D::DrawCirclue(20, sf::Vector2f(20, 20), sf::Color::Green);
	
	m_GameFlowStateMachine->Update();
}

void GameLayer::OnImGuiRender()
{
	ImGui::Begin("Window");
	ImGui::Text("Window text!");
	ImGui::End();
}

void GameLayer::OnEvent(Unique::Event& e)
{
	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<WindowResizeEvent>(UQ_BIND_EVENT_FN(GameLayer::OnWindowResize));
	dispatcher.Dispatch<MouseButtonPressedEvent>(UQ_BIND_EVENT_FN(GameLayer::OnMouseButtonPressed));
}

bool GameLayer::OnMouseButtonPressed(Unique::MouseButtonPressedEvent& e)
{
	if (m_State == GameState::GameOver)


	m_State = GameState::Play;
	return false;
}

bool GameLayer::OnWindowResize(Unique::WindowResizeEvent& e)
{
	return false;
}

