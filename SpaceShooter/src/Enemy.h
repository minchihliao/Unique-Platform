#pragma once
#include "Unique.h"
using namespace Unique;


class Enemy
{
public:
	Enemy();
	void LoadAssets();

	void OnUpdate();
	void OnRender();

	void OnImGuiRender();

	void Reset();

	float GetRotation() { return m_Velocity.y * 4.0f - 90.0f; }

	 sf::Vector2f& GetPosition()  { return m_Position; }

	 bool ShouldBeRemoved() const {
		 return m_Dead;
	 }


	uint32_t GetScore() const { return (uint32_t)(m_Position.x + 10.0f) / 10.0f; }
private:
	void collision();
	bool IsOutofBounds();
	sf::Vector2f m_Position = { 100.0f, 100.0f };
	sf::Vector2f m_Velocity = { 5.0f, 0.0f };
	int m_Hp = 10;
	int m_HpMax = 10;

	bool m_Dead = false; 

	Sprite m_Sprite;


	float m_Time = 0.0f;


//	Unique::Ref<Unique::Texture2D> m_ShipTexture;
};
