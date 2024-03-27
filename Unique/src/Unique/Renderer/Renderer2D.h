#pragma once
#include "SFML/Window/Window.hpp"
#include "SFML/Graphics.hpp"
#include "Unique/Renderer/Texture.h"
#include "Unique/Platform/SFML/SFMLTexture2D.h"
#include "Unique/Sprite.h"

namespace Unique 
{

	class Renderer2D
	{
	public:
		
		static void DrawCirclue(float size, sf::Vector2f position,sf::Color color);
		static void DrawRectangle(sf::Vector2f size, sf::Vector2f position,sf::Color color);
		static void DrawConvex(std::vector<sf::Vector2f>& vertexs, sf::Vector2f position,sf::Color color);
		static void DrawSprite(sf::Vector2f size,sf::Vector2f position,Ref<Unique::Texture2D> texture);
		static void DrawSprite(Sprite sprite,sf::Vector2f position);
	};

}