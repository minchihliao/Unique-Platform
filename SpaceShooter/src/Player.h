#pragma once
#include <Unique.h>



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

	uint32_t GetScore() const { return (uint32_t)(m_Position.x + 10.0f) / 10.0f; }
private:
	sf::Vector2f m_Position = { -10.0f, 0.0f };
	sf::Vector2f m_Velocity = { 5.0f, 0.0f };

	float m_EnginePower = 0.5f;
	float m_Gravity = 0.4f;

	float m_Time = 0.0f;
	float m_SmokeEmitInterval = 0.4f;
	float m_SmokeNextEmitTime = m_SmokeEmitInterval;

	//ParticleProps m_SmokeParticle, m_EngineParticle;
	//ParticleSystem m_ParticleSystem;

	Unique::Ref<sf::Texture> m_ShipTexture;
};