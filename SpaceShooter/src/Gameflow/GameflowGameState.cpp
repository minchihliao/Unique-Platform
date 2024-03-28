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

void GameflowGameState::OnUpdate(GameLayer* layer, Unique::Timestep ts)
{
	m_Time += ts;
	UQ_INFO(m_Time);
	//Player
	m_Player.OnUpdate(ts);

	//Enemy
	if (m_Time > m_EnemyNextSpawnTime && m_Enemies.size() < 50) {
		m_EnemyNextSpawnTime += m_EnemySpawnInterval;
		Enemy* enemy = new Enemy();
		enemy->LoadAssets();
		enemy->Reset();
		m_Enemies.push_back(enemy);
	}
	for (size_t i = 0; i < m_Enemies.size(); i++ )
	{
		m_Enemies[i]->OnUpdate(ts);
		
		if (m_Enemies[i]->ShouldBeRemoved()) {
			m_Enemies.erase(m_Enemies.begin() + i);
			break;
		}
		if (m_Enemies[i]->GetGlobalBounds().intersects(m_Player.GetGlobalBounds())) {
			m_Enemies.erase(m_Enemies.begin() + i);
			//player.Hp--; //Player Take damage.
			break;
		}
	}

	//Bullte Collision
	auto& bullets = m_Player.GetBullets();
	for (size_t i = 0; i < bullets.size(); i++)
	{
		bullets[i]->OnUpdate(ts);

		if (bullets[i]->ShouldBeRemoved()) 
		{
			bullets.erase(bullets.begin() + i);
			break;
		}
		else
		{
			//Enemy Collision
			for (int j = 0; j < m_Enemies.size(); j++)
			{
				if (bullets[i]->GetGlobalBounds().intersects(m_Enemies[j]->GetGlobalBounds()))
				{
					if (m_Enemies[j]->GetHp() <= 1)
					{
						m_Score += m_Enemies[j]->GetMaxHp();
						m_Enemies.erase(m_Enemies.begin() + j);

					}
					else
					{
						int val = m_Enemies[j]->GetHp();
						val--;
						m_Enemies[j]->SetHp(val);
					}
					bullets.erase(bullets.begin() + i);

					break;
				}
			}
		}
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
