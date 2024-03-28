#pragma once
#include "Unique.h"
#include "Gameflow/GameFlowStateMachine.h"

class GameLayer : public Unique::Layer
{
public:
	GameLayer();
	virtual ~GameLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Unique::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Unique::Event& e) override;

	GameFlowStateMachine* GetFlowStateMachine() { return m_GameFlowStateMachine; }

	bool OnMouseButtonPressed(Unique::MouseButtonPressedEvent& e);
	bool OnWindowResize(Unique::WindowResizeEvent& e);
private:

	float m_Time = 0.0f;
	bool m_Blink = false;
	GameFlowStateMachine* m_GameFlowStateMachine;
	enum class GameState
	{
		Play = 0, MainMenu = 1, GameOver = 2
	};

	GameState m_State = GameState::MainMenu;

};