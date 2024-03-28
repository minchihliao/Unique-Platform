#pragma once
#include "Unique.h"
using namespace Unique;


class Enemy
{
public:
	Enemy();
	void LoadAssets();

	void OnUpdate(Timestep ts);
	void OnRender();

	void OnImGuiRender();

	void Reset();

	float GetRotation() { return m_Velocity.y * 4.0f - 90.0f; }

	 sf::Vector2f& GetPosition()  { return m_Position; }

	 bool ShouldBeRemoved() const {
		 return m_Dead;
	 }
	 sf::FloatRect GetGlobalBounds() { return m_Sprite.GetGlobalBounds(); }

	 void SetHp (int val) {  m_Hp = val; }
	 int GetHp() { return m_Hp; }
	 int GetMaxHp() { return m_HpMax; }
	

private:
	void collision();
	bool IsOutofBounds();
	sf::Vector2f m_Position = { 100.0f, 100.0f };
	sf::Vector2f m_Velocity = { 5.0f, 0.0f };
	int m_Hp;
	int m_HpMax;

	bool m_Dead = false; 

	Sprite m_Sprite;


	float m_Time = 0.0f;


//	Unique::Ref<Unique::Texture2D> m_ShipTexture;
};
