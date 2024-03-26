#pragma once
#include "Unique.h"

class GameLayer; // 前向聲明

 enum class GameFlowState
{
	Init,
	Menu,
	Game,
	EndGame
};


 class GameFlowStateMachine : public Unique::StateMachine<GameLayer,GameFlowState>
 {
	 
 public:
	 explicit GameFlowStateMachine(GameLayer* owner)
		 : Unique::StateMachine<GameLayer, GameFlowState>(owner) {}
	 void Init();
	 //~GameFlowStateMachine();
	 virtual std::string ConditionToString(GameFlowState condition) override;

 private:

 };

 