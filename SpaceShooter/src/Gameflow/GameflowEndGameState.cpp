#include "GameflowEndGameState.h"

void GameflowEndGameState::Enter(GameLayer* layer)
{
	UQ_INFO("Game EndGame");
	//layer->GetFlowStateMachine()->ChangeState(GameFlowState::EndGame);
}

void GameflowEndGameState::Update(GameLayer* layer)
{
}

void GameflowEndGameState::Exit(GameLayer* layer)
{
}
