#include "Player.h"
#include "Unique/Application.h"
#include "Unique/Platform/Windows/SFMLWindow.h"



Player::Player()
{
	this->m_Hp = 3;
	this->m_HpMax = this->m_Hp;
	LoadAssets();
}

void Player::LoadAssets()
{
	m_Sprite.SetTexture(Unique::Texture2D::Create("assets/textures/enemy.png"));
	m_Sprite.SetScale(sf::Vector2f(0.1, 0.1));
}

void Player::Reset()
{
	auto window = static_cast<sf::RenderWindow*>(Application::Get().GetWindow().GetNativeWindow());
	m_Position = sf::Vector2f(window->getSize().x / 2 - m_Sprite.GetGlobalBounds().width / 2,
		window->getSize().y - m_Sprite.GetGlobalBounds().height);
	m_Sprite.SetPosition(m_Position);
	this->m_Hp = 3;
	this->m_HpMax = this->m_Hp;
	m_Bullets.clear();
	m_Time = 0.0f;
	m_BullteInterval = 0.2f;
	m_BullteNextShootTime = m_BullteInterval;
}

void Player::OnUpdate(Timestep ts)
{
	m_Time += ts;

	if (Input::IsKeyPressed(UQ_KEY_A))
	{
		m_Position += sf::Vector2f(-10.f, 0.f);
		m_Sprite.SetPosition(m_Position);
	}
	if (Input::IsKeyPressed(UQ_KEY_D))
	{
		m_Position += sf::Vector2f(10.f, 0.f);
		m_Sprite.SetPosition(m_Position);
	}
	if (Input::IsKeyPressed(UQ_KEY_W))
	{
		m_Position += sf::Vector2f(0.f, -10.f);
		m_Sprite.SetPosition(m_Position);
	}
	if (Input::IsKeyPressed(UQ_KEY_S))
	{
		m_Position += sf::Vector2f(0.f, 10.f);
		m_Sprite.SetPosition(m_Position);
	}

	collision();
	

	//Shooting
	if (Input::IsMouseButtonPressed(UQ_MOUSE_BUTTON_Left)&& m_Time > m_BullteNextShootTime)
	{
		m_BullteNextShootTime = m_Time+ m_BullteInterval;
		sf::Vector2f bulletPosition = sf::Vector2(GetPosition().x
			, GetPosition().y);
		Bullet* bullet = new Bullet();
		bullet->LoadAssets();
		bullet->SetPosition(bulletPosition);
		m_Bullets.push_back(bullet);
	}

}




void Player::OnRender()
{
	Unique::Renderer2D::DrawSprite(m_Sprite, GetPosition());
	for (auto bullet: m_Bullets)
	{
		bullet->OnRender();
	}
}

void Player::OnImGuiRender()
{

	auto hpOverTextPos = m_Position;
	hpOverTextPos.x -= 15.f;
	hpOverTextPos.y -= 10.f;
	std::string hpString = std::to_string(m_Hp)+"/"+std::to_string(m_HpMax);
	std::vector<char> charVector(hpString.begin(), hpString.end());
	charVector.push_back('\0'); 

	ImGui::GetForegroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[0], 18.f, hpOverTextPos, 0xffffffff, charVector.data());

	for (auto bullet : m_Bullets)
	{
		bullet->OnImGuiRender();
	}
}



void Player::collision()
{
	auto window = static_cast<sf::RenderWindow*>(Application::Get().GetWindow().GetNativeWindow());
	//Collision with window
	if (m_Position.x <= 0)	// left
	{
		m_Position = sf::Vector2f(0.f, m_Position.y);
		m_Sprite.SetPosition(m_Position);
	}
	if (m_Position.x >= window->getSize().x - m_Sprite.GetGlobalBounds().width)	//Right
	{
		m_Position = sf::Vector2f(window->getSize().x - m_Sprite.GetGlobalBounds().width, m_Position.y);
		m_Sprite.SetPosition(m_Position);
	}
	if (m_Position.y <= 0) // TOP
	{
		m_Position = sf::Vector2f(m_Position.x, 0.f);
		m_Sprite.SetPosition(m_Position);
	}
	if (m_Position.y >= window->getSize().y - m_Sprite.GetGlobalBounds().height) //Bottom
	{
		m_Position = sf::Vector2f(m_Position.x, window->getSize().y - m_Sprite.GetGlobalBounds().height);
		m_Sprite.SetPosition(m_Position);
	}
}