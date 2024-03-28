#include "Bullet.h"

Bullet::Bullet()
{
}



void Bullet::LoadAssets()
{
	m_Sprite.SetTexture(Unique::Texture2D::Create("assets/textures/enemy.png"));
	m_Sprite.SetScale(sf::Vector2f(0.1, 0.1));
}

void Bullet::OnUpdate()
{
	if (!m_Dead) 
	{
		m_Position -= sf::Vector2f(0, 20.f);
		m_Sprite.SetPosition(m_Position);
		collision();
	}
	
}

void Bullet::OnRender()
{
	Unique::Renderer2D::DrawSprite(m_Sprite, GetPosition());
}

void Bullet::OnImGuiRender()
{
}



void Bullet::collision()
{
	if (IsOutofBounds()) {
		m_Dead = true;
	}
}

bool Bullet::IsOutofBounds()
{
	auto window = static_cast<sf::RenderWindow*>(Application::Get().GetWindow().GetNativeWindow());
	if (GetPosition().x < 0 || GetPosition().x > window->getSize().x
		|| GetPosition().y < 0 || GetPosition().y > window->getSize().y)
	{
		return true;
	}
	return false;
}
