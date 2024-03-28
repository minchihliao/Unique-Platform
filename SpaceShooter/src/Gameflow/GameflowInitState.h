#pragma once
#include "Unique.h"
#include "../GameLayer.h"

class GameflowInitState : public Unique::State<GameLayer, GameFlowState>
{
public:
    GameflowInitState() {}
    void Enter(GameLayer* layer) override;
    void OnUpdate(GameLayer* layer, Unique::Timestep ts) override {}
    void OnRender(GameLayer* layer) override {}
    void Exit(GameLayer* layer) override {}

private:

};