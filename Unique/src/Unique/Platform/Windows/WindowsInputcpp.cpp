#include "uqpch.h"
#include "WindowsInput.h"

#include "Unique/Application.h"
#include "SFML/Window/Window.hpp"
#include "SFML/Graphics.hpp"

namespace Unique {

	Input* Input::s_Instance = new WindowsInput();

	bool WindowsInput::IsKeyPressedImpl(int keycode)
	{
		
		return sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(keycode));
	}

	bool WindowsInput::IsMouseButtonPressedImpl(int button)
	{
		//UQ_CORE_INFO("{0}",button);
		//UQ_CORE_INFO("{0}", static_cast<sf::Mouse::Button>(button));
		return  sf::Mouse::isButtonPressed(static_cast<sf::Mouse::Button>(button));
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