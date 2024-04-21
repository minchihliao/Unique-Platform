#include "GameFlowStateMachine.h"
#include "GameflowState.h"


void GameFlowStateMachine::Init()
{
	SetTransition(GameFlowState::Init, new GameflowInitState());
	SetTransition(GameFlowState::Menu, new GameflowMenuState());
	SetTransition(GameFlowState::Game, new GameflowGameState());
	SetTransition(GameFlowState::EndGame, new GameflowEndGameState());
}

std::string GameFlowStateMachine::ConditionToString(GameFlowState condition)
{
	switch (condition) {
		case GameFlowState::Init: return "Init";
		case GameFlowState::Menu: return "Menu";
		case GameFlowState::Game: return "Game";
		case GameFlowState::EndGame: return "EndGame";
	default: return "Unknown";
	}

}
