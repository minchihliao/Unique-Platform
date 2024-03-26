#pragma once
#include "Unique.h"
#include "../GameLayer.h"

class GameflowInitState : public Unique::State<GameLayer, GameFlowState>
{
public:
    GameflowInitState() {}
    void Enter(GameLayer* layer) override;
    void Update(GameLayer* layer) override {}
    void Exit(GameLayer* layer) override {}

private:

};