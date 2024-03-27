#include "GameflowMenuState.h"

void GameflowMenuState::Enter(GameLayer* layer)
{
	UQ_INFO("Game Menu");
	layer->GetFlowStateMachine()->ChangeState(GameFlowState::Game);
}

void GameflowMenuState::OnUpdate(GameLayer* layer)
{
}

void GameflowMenuState::OnRender(GameLayer* layer)
{
}

void GameflowMenuState::OnImGuiRender(GameLayer* layer)
{
}

void GameflowMenuState::Exit(GameLayer* layer)
{
}
