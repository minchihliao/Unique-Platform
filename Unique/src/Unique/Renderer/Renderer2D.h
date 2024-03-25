#pragma once
#include "SFML/Window/Window.hpp"
#include "SFML/Graphics.hpp"

namespace Unique 
{

	class Renderer2D
	{
	public:
		
		static void Draw(sf::Shape& shape, sf::Vector2f size, sf::Vector2f position,sf::Color color);
		static void Draw(sf::Text& text, sf::Vector2f size, sf::Vector2f position,sf::Color color);
		static void Draw(sf::Sprite& shape, sf::Vector2f size,sf::Vector2f position,Ref<sf::Texture>& texture);
	};

}