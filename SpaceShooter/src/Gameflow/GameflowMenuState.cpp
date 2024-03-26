#include "GameflowMenuState.h"

void GameflowMenuState::Enter(GameLayer* layer)
{
	UQ_INFO("Game Menu");
	layer->GetFlowStateMachine()->ChangeState(GameFlowState::Game);
}

void GameflowMenuState::Update(GameLayer* layer)
{
}

void GameflowMenuState::Exit(GameLayer* layer)
{
}
