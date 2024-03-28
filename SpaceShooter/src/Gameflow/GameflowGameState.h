#pragma once
#include "Unique.h"
#include "../GameLayer.h"
#include "../Player.h"
#include "../Enemy.h"


class GameflowGameState : public Unique::State<GameLayer, GameFlowState>
{
public:
    void Enter(GameLayer* layer) override;
    void OnUpdate(GameLayer* layer) override;
    void OnRender(GameLayer* layer) override;
    void OnImGuiRender(GameLayer* layer) override;
    void Exit(GameLayer* layer) override;

private:
    uint32_t m_Score = 0;
    Player m_Player;
    std::vector<Enemy*> m_Enemies;
    int enemySpawnTimder = 25;
};