#pragma once
#include "Unique/Input.h"

namespace Unique {

	class WindowsInput : public Input
	{
	protected:
		virtual bool IsKeyPressedImpl(sf::Keyboard::Key keycode) override;

		virtual bool IsMouseButtonPressedImpl(sf::Mouse::Button button) override;
		virtual std::pair<float, float> GetMousePositionImpl() override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;
	};

}