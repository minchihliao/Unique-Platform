#pragma once
#include "Unique.h"
using namespace Unique;

class Bullet
{
public:
	Bullet();
	void LoadAssets();

	void OnUpdate(Timestep ts);
	void OnRender();

	void OnImGuiRender();

	void SetPosition(sf::Vector2f position) { m_Position = position;}

	sf::Vector2f& GetPosition() { return m_Position; }

	sf::FloatRect GetGlobalBounds() { return m_Sprite.GetGlobalBounds(); }

	bool ShouldBeRemoved() const {
		return m_Dead;
	}

private:
	void collision();
	bool IsOutofBounds();
	sf::Vector2f m_Position = { 0.0f, 0.0f };
	int m_Hp = 10;
	int m_HpMax = 10;

	bool m_Dead = false;
	Sprite m_Sprite;


	float m_Time = 0.0f;

};
