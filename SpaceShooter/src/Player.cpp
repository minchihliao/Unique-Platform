#include "Player.h"
#include "Unique/Application.h"
#include "Unique/Platform/Windows/SFMLWindow.h"



Player::Player()
{
	

}

void Player::LoadAssets()
{
	m_Sprite.SetTexture(Unique::Texture2D::Create("assets/textures/enemy.png"));
	m_Sprite.SetScale(sf::Vector2f(0.1, 0.1));
}

void Player::OnUpdate()
{
	if (Input::IsKeyPressed(UQ_KEY_A))
		m_Position += sf::Vector2f(-10.f, 0.f);
	if (Input::IsKeyPressed(UQ_KEY_D))
		m_Position += sf::Vector2f(10.f, 0.f);
	if (Input::IsKeyPressed(UQ_KEY_W))
		m_Position += sf::Vector2f(0.f, -10.f);
	if (Input::IsKeyPressed(UQ_KEY_S))
		m_Position += sf::Vector2f(0.f, 10.f);

	collision();
	

	//Shooting
}




void Player::OnRender()
{
	Unique::Renderer2D::DrawSprite(m_Sprite, GetPosition());
}

void Player::OnImGuiRender()
{
}

void Player::Reset()
{
	auto window = static_cast<sf::RenderWindow*>(Application::Get().GetWindow().GetNativeWindow());
	UQ_INFO("{0},{1},{2},{3}", window->getSize().x / 2, m_Sprite.GetGlobalBounds().width / 2,
		window->getSize().y, m_Sprite.GetGlobalBounds().height / 2);

	m_Position = sf::Vector2f(window->getSize().x / 2 - m_Sprite.GetGlobalBounds().width / 2,
		window->getSize().y - m_Sprite.GetGlobalBounds().height );
}

void Player::collision()
{
	auto window = static_cast<sf::RenderWindow*>(Application::Get().GetWindow().GetNativeWindow());
	//Collision with window
	if (m_Position.x <= 0)	// left
		m_Position = sf::Vector2f(0.f, m_Position.y);
	if (m_Position.x >= window->getSize().x - m_Sprite.GetGlobalBounds().width)	//Right
		m_Position = sf::Vector2f(window->getSize().x - m_Sprite.GetGlobalBounds().width, m_Position.y);
	if (m_Position.y <= 0) // TOP
		m_Position = sf::Vector2f(m_Position.x, 0.f);
	if (m_Position.y >= window->getSize().y - m_Sprite.GetGlobalBounds().height) //Bottom
		m_Position = sf::Vector2f(m_Position.x, window->getSize().y - m_Sprite.GetGlobalBounds().height);
}