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
	void OnRender(Unique::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Unique::Event& e) override;

	GameFlowStateMachine* GetFlowStateMachine() { return m_GameFlowStateMachine; }
	void SetScore(uint32_t score) { m_Score = score; }
	uint32_t GetScore() const { return m_Score; }
	Unique::PlayerData* GetPlayerData() { return m_PlayerData; }

private:
	bool OnMouseButtonPressed(Unique::MouseButtonPressedEvent& e);
	bool OnWindowResize(Unique::WindowResizeEvent& e);
private:
	GameFlowStateMachine* m_GameFlowStateMachine;
	Unique::PlayerData* m_PlayerData;
	uint32_t m_Score;

};