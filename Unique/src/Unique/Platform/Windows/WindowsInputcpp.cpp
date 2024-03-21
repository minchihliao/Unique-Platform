#include "uqpch.h"
#include "WindowsInput.h"

#include "Unique/Application.h"
#include "SFML/Window/Window.hpp"
#include "SFML/Graphics.hpp"

namespace Unique {

	Input* Input::s_Instance = new WindowsInput();

	bool WindowsInput::IsKeyPressedImpl(sf::Keyboard::Key keycode)
	{
		return sf::Keyboard::isKeyPressed(keycode);
	}

	bool WindowsInput::IsMouseButtonPressedImpl(sf::Mouse::Button button)
	{
		return  sf::Mouse::isButtonPressed(button);
	}

	std::pair<float, float> WindowsInput::GetMousePositionImpl()
	{
		auto window = static_cast<sf::RenderWindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto [x, y] = sf::Mouse::getPosition();

		return { (float)x, (float)y };
	}

	float WindowsInput::GetMouseXImpl()
	{
		auto window = static_cast<sf::RenderWindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto [x, y] = sf::Mouse::getPosition();
		return x;
	}

	float WindowsInput::GetMouseYImpl()
	{
		auto window = static_cast<sf::RenderWindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto [x, y] = sf::Mouse::getPosition();
		return y;
	}

}