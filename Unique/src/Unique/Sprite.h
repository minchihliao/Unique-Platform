#pragma once
#include "Unique/Core.h"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "Platform/SFML/SFMLTexture2D.h"


namespace Unique
{

	class Sprite
	{
	public:
		Sprite() {}
		void SetTexture(std::shared_ptr<Texture2D> texture, bool resetRect = false);
		void SetColor(const sf::Color& color);
		sf::FloatRect GetGlobalBounds();
		void SetScale(float factorX, float factorY);
		void SetScale(const sf::Vector2f& factors);
		void SetPosition(const sf::Vector2f& position);
		void SetPosition(float x, float y);
		sf::Sprite GetSFMLSprit() { return m_Sprite; }
		~Sprite() {}

	private:
		sf::Sprite m_Sprite;
		Ref<SFMLTexture> m_Texture;
	};


}