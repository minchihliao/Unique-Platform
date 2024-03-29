#pragma once
#include "Unique.h"
#include "Bullet.h"
using namespace Unique;


class Player
{
public:
	Player();

	void LoadAssets();

	void OnUpdate(Timestep ts);
	void OnRender();

	void OnImGuiRender();

	void Reset();

	float GetRotation() { return m_Velocity.y * 4.0f - 90.0f; }

	const sf::Vector2f& GetPosition() const { return m_Position; }

	sf::FloatRect GetGlobalBounds() { return m_Sprite.GetGlobalBounds(); }
	std::vector<Bullet*>& GetBullets() { return m_Bullets; }
	uint32_t GetScore() const { return (uint32_t)(m_Position.x + 10.0f) / 10.0f; }
	uint32_t GetHP() const { return m_Hp; }
	void SetHP(uint32_t val) { m_Hp = val; }
private:
	void collision();
private:
	Sprite m_Sprite;
	sf::Vector2f m_Position = { 100.0f, 100.0f };
	sf::Vector2f m_Velocity = { 5.0f, 0.0f };
	float m_Time = 0.0f;
	float m_BullteInterval = 0.2f;
	float m_BullteNextShootTime = m_BullteInterval;
	uint32_t m_Hp ;
	uint32_t m_HpMax;
private:
	std::vector<Bullet*> m_Bullets;

};