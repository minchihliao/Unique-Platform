#pragma once
#include "Unique.h"
#include "../GameLayer.h"


class GameflowEndGameState : public Unique::State<GameLayer, GameFlowState>
{
public:
    void Enter(GameLayer* layer) override;
    void Update(GameLayer* layer) override;
    void Exit(GameLayer* layer) override;

private:

};