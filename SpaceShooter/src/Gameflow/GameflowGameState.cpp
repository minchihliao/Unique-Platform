#include "GameflowGameState.h"

GameflowGameState::GameflowGameState()
{
}

void GameflowGameState::Enter(GameLayer* layer)
{
	UQ_INFO("Gameflow : Game");
	m_Player.Reset();
	m_GameOver = false;
	m_Score = 0;
	m_Enemies.clear();
	enemySpawnTimder = 25;
	m_Time = 0.0f;
	m_EnemySpawnInterval = 0.2f;
	m_EnemyNextSpawnTime = m_EnemySpawnInterval;
}

void GameflowGameState::OnUpdate(GameLayer* layer, Unique::Timestep ts)
{
	m_Time += ts;
	if (isGameOver()) 
	{
		layer->GetFlowStateMachine()->ChangeState(GameFlowState::EndGame);
		return;
	}

	if (m_Player.GetHP() <= 0)
		m_GameOver = true;

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
			int val = m_Player.GetHP();
			val--;
			m_Player.SetHP(val);
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
	auto window = static_cast<sf::RenderWindow*>(Application::Get().GetWindow().GetNativeWindow());
	ImVec2 windowCenterPos = window->getSize();
	windowCenterPos.x /= 2.f;
	windowCenterPos.y /= 2.f;

	uint32_t playerScore = m_Score;
	ImVec2 pos;
	pos.x = 30.f;
	pos.y = 20.f;
	std::string scoreStr = std::string("Score: ") + std::to_string(playerScore);
	ImGui::GetForegroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[0], 48.0f, pos, 0xffffffff, scoreStr.c_str());

	m_Player.OnImGuiRender();
	for (auto enemy : m_Enemies)
	{
		enemy->OnImGuiRender();
	}
}

void GameflowGameState::Exit(GameLayer* layer)
{
	m_Enemies.clear();
}
