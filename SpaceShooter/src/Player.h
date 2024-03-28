#pragma once
#include "Unique.h"
#include "Bullet.h"
using namespace Unique;


class Player
{
public:
	Player();

	void LoadAssets();

	void OnUpdate();
	void OnRender();

	void OnImGuiRender();

	void Reset();

	float GetRotation() { return m_Velocity.y * 4.0f - 90.0f; }

	const sf::Vector2f& GetPosition() const { return m_Position; }

	sf::FloatRect GetGlobalBounds() { return m_Sprite.GetGlobalBounds(); }
	std::vector<Bullet*>& GetBullets() { return m_Bullets; }


	uint32_t GetScore() const { return (uint32_t)(m_Position.x + 10.0f) / 10.0f; }
private:
	sf::Vector2f m_Position = { 100.0f, 100.0f };
	sf::Vector2f m_Velocity = { 5.0f, 0.0f };
	std::vector<Bullet*> m_Bullets;
	int m_ShootTimer = 100;

	int m_Hp = 10;
	int m_HpMax =10;

	void collision();


	Sprite m_Sprite;


	float m_Time = 0.0f;

	//Bullets object

};