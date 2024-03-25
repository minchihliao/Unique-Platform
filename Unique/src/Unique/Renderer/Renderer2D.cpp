#include "uqpch.h"
#include "Renderer2D.h"

#include "Unique/Application.h"

void Unique::Renderer2D::DrawCirclue(float size, sf::Vector2f position, sf::Color color)
{
	auto window = static_cast<sf::RenderWindow*>(Application::Get().GetWindow().GetNativeWindow());
	sf::CircleShape circle;
	circle.setRadius(size);
	circle.setPosition(position);
	circle.setFillColor(color);
	window->draw(circle);
}

void Unique::Renderer2D::DrawRectangle(sf::Vector2f size, sf::Vector2f position, sf::Color color)
{
	auto window = static_cast<sf::RenderWindow*>(Application::Get().GetWindow().GetNativeWindow());
	sf::RectangleShape rectangle;
	rectangle.setSize(size);
	rectangle.setFillColor(color);
	rectangle.setPosition(position);
	window->draw(rectangle);
}

void Unique::Renderer2D::DrawConvex(std::vector<sf::Vector2f>& vertexs, sf::Vector2f position, sf::Color color)
{
	auto window = static_cast<sf::RenderWindow*>(Application::Get().GetWindow().GetNativeWindow());
	sf::ConvexShape polygon;
	polygon.setPointCount(vertexs.size());
	for (auto vertex : vertexs)
	{
		polygon.setPosition(vertex);
	}
	polygon.setFillColor(color);
	polygon.setPosition(position);
	window->draw(polygon);
}



void Unique::Renderer2D::DrawSprite(sf::Vector2f size, sf::Vector2f position, Ref<Unique::SFMLTexture> texture)
{
	auto window = static_cast<sf::RenderWindow*>(Application::Get().GetWindow().GetNativeWindow());
	sf::Sprite sprite;
	sf::Texture* data = static_cast<sf::Texture*>(texture->GetData());
	sprite.setTexture(*data);
	sprite.setScale(size);
	sprite.setPosition(position);
	window->draw(sprite);
}
