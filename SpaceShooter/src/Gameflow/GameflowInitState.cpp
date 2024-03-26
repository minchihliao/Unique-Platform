#include "GameflowInitState.h"

void GameflowInitState::Enter(GameLayer* layer)
{
	UQ_INFO("Game Init");
	layer->GetFlowStateMachine()->ChangeState(GameFlowState::Menu);
}
