#pragma once

#include "Player.h"

class Level
{
public:
	void Init();

	void OnUpdate();
	void OnRender();

	void OnImGuiRender();

	bool IsGameOver() const { return m_GameOver; }
	void Reset();

	Player& GetPlayer() { return m_Player; }
private:

	bool CollisionTest();

	void GameOver();
private:
	Player m_Player;

	bool m_GameOver = false;

	float m_PillarTarget = 30.0f;
	int m_PillarIndex = 0;
	sf::Vector3f m_PillarHSV = { 0.0f, 0.8f, 0.8f };

	//std::vector<Pillar> m_Pillars;

	Unique::Ref<sf::Texture> m_TriangleTexture;

};