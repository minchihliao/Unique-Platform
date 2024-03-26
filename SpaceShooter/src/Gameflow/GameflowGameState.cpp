#include "GameflowGameState.h"

void GameflowGameState::Enter(GameLayer* layer)
{
	UQ_INFO("Game Game");
	layer->GetFlowStateMachine()->ChangeState(GameFlowState::EndGame);
}

void GameflowGameState::Update(GameLayer* layer)
{
}

void GameflowGameState::Exit(GameLayer* layer)
{
}
