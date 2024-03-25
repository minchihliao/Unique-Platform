#include "uqpch.h"
#include "Renderer2D.h"
#include "Unique/Application.h"

void Unique::Renderer2D::Draw(sf::Shape& shape, sf::Vector2f size, sf::Vector2f position, sf::Color color)
{
	auto window = static_cast<sf::RenderWindow*>(Application::Get().GetWindow().GetNativeWindow());
	shape.setScale(size);
	shape.setPosition(position);
	shape.setFillColor(color);
	window->draw(shape);
}

void Unique::Renderer2D::Draw(sf::Text& text, sf::Vector2f size, sf::Vector2f position, sf::Color color)
{
	auto window = static_cast<sf::RenderWindow*>(Application::Get().GetWindow().GetNativeWindow());
	text.setScale(size);
	text.setPosition(position);
	text.setFillColor(color);
	window->draw(text);
}

void Unique::Renderer2D::Draw(sf::Sprite& shape, sf::Vector2f size, sf::Vector2f position, Ref<sf::Texture>& texture)
{
	auto window = static_cast<sf::RenderWindow*>(Application::Get().GetWindow().GetNativeWindow());
	shape.setTexture(*texture);
	shape.setScale(size);
	shape.setPosition(position);
	window->draw(shape);
}
