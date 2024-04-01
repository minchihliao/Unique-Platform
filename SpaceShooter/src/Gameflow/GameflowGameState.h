#pragma once
#include "Unique.h"
#include "../GameLayer.h"
#include "../Player.h"
#include "../Enemy.h"


class GameflowGameState : public Unique::State<GameLayer, GameFlowState>
{
public:
    GameflowGameState();
    void Enter(GameLayer* layer) override;
    void OnUpdate(GameLayer* layer, Unique::Timestep ts) override;
    void OnRender(GameLayer* layer) override;
    void OnImGuiRender(GameLayer* layer) override;
    void Exit(GameLayer* layer) override;

private:
    bool isGameOver() { return m_GameOver; }
private:
    bool m_GameOver = false;
    Player m_Player;
    std::vector<Enemy*> m_Enemies;
    int enemySpawnTimder = 25;
    float m_Time = 0.0f;
    float m_EnemySpawnInterval = 0.2f;
    float m_EnemyNextSpawnTime = m_EnemySpawnInterval;
};