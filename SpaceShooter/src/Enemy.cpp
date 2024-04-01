#include "Enemy.h"

Enemy::Enemy()
{
	int randonHp = rand() % 5;
	this->m_Hp = randonHp == 0 ? 5: randonHp;
	this->m_HpMax = this->m_Hp;
}

void Enemy::LoadAssets()
{
	m_Sprite.SetTexture(Unique::Texture2D::Create("assets/textures/enemy.png"));
	m_Sprite.SetScale(sf::Vector2f(0.1, 0.1));
}

void Enemy::OnUpdate(Timestep ts)
{
	if (!m_Dead)
	{
		m_Position += sf::Vector2f(0, 5.f);
		m_Sprite.SetPosition(m_Position);
		collision();
	}

}

void Enemy::OnRender()
{
	Unique::Renderer2D::DrawSprite(m_Sprite, GetPosition());
}

void Enemy::OnImGuiRender()
{

	auto hpOverTextPos = m_Position;
	hpOverTextPos.x -= 15.f;
	hpOverTextPos.y -= 10.f;
	std::string hpString = std::to_string(m_Hp) + "/" + std::to_string(m_HpMax);
	std::vector<char> charVector(hpString.begin(), hpString.end());
	charVector.push_back('\0');

	ImGui::GetForegroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[0], 18.f, hpOverTextPos, 0xffffffff, charVector.data());
}

void Enemy::Reset()
{
	auto window = static_cast<sf::RenderWindow*>(Application::Get().GetWindow().GetNativeWindow());
	m_Position = sf::Vector2f(rand() % (int)(window->getSize().x - m_Sprite.GetGlobalBounds().width), 10);
	m_Sprite.SetPosition(m_Position);
	
}
void Enemy::collision()
{
	if (IsOutofBounds()) {
		m_Dead = true;
	}

}

bool Enemy::IsOutofBounds()
{
	auto window = static_cast<sf::RenderWindow*>(Application::Get().GetWindow().GetNativeWindow());
	if (GetPosition().y >= window->getSize().y - m_Sprite.GetGlobalBounds().height)
	{
		return true;
	}
	return false;
}


