#include "GameflowGameState.h"

void GameflowGameState::Enter(GameLayer* layer)
{
	UQ_INFO("Gameflow : Game");
	m_Player.LoadAssets();
	m_Player.Reset();
	for (auto enemy: m_Enemies)
	{
		enemy->LoadAssets();
		enemy->Reset();
	}
	
}

void GameflowGameState::OnUpdate(GameLayer* layer)
{
	m_Player.OnUpdate();
	if (enemySpawnTimder < 25)
		enemySpawnTimder++;
	if (enemySpawnTimder >= 25 && m_Enemies.size() < 50) {
		enemySpawnTimder = 0;
		Enemy* enemy = new Enemy();
		enemy->LoadAssets();
		enemy->Reset();
		m_Enemies.push_back(enemy);
	}
	for (size_t i = 0; i < m_Enemies.size(); i++ )
	{
		m_Enemies[i]->OnUpdate();
		
		if(m_Enemies[i]->ShouldBeRemoved())
			m_Enemies.erase(m_Enemies.begin() + i);
	}
}

void GameflowGameState::OnRender(GameLayer* layer)
{
	m_Player.OnRender();
	for (auto enemy : m_Enemies)
	{
		enemy->OnRender();
	}
}

void GameflowGameState::OnImGuiRender(GameLayer* layer)
{
	m_Player.OnImGuiRender();
	for (auto enemy : m_Enemies)
	{
		enemy->OnImGuiRender();
	}
}

void GameflowGameState::Exit(GameLayer* layer)
{
}
