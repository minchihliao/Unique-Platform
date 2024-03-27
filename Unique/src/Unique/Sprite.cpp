#include "uqpch.h"
#include "Sprite.h"

namespace Unique 
{
	void Sprite::SetTexture(std::shared_ptr<Texture2D> refTexture, bool resetRect)
	{
		m_Texture = std::static_pointer_cast<SFMLTexture>(refTexture);
		sf::Texture* data = static_cast<sf::Texture*>(m_Texture->GetData());
		m_Sprite.setTexture(*data);
	}

	void Sprite::SetColor(const sf::Color& color)
	{
		m_Sprite.setColor(color);
	}

	sf::FloatRect Sprite::GetGlobalBounds()
	{
		return m_Sprite.getGlobalBounds();
	}

	void Sprite::SetScale(float factorX, float factorY)
	{
		m_Sprite.setScale(factorX, factorY);
	}


	void Sprite::SetScale(const sf::Vector2f& factors)
	{
		m_Sprite.setScale(factors);
	}

	void Sprite::SetPosition(const sf::Vector2f& position)
	{
		m_Sprite.setPosition(position);
	}

	void Sprite::SetPosition(float x, float y)
	{
		m_Sprite.setPosition(x, y);
	}



}

