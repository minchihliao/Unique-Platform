#pragma once
#include "Unique/Window.h"
#include "SFML/Window/Window.hpp"
#include "SFML/Graphics.hpp"

namespace Unique {



	class SFMLWindow : public Window
	{
	public:
		SFMLWindow(const WindowProps& props);

		virtual ~SFMLWindow();

		void OnUpdate() override;

		void OnEvent() override;
		void Render() override;
		void EndUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		inline virtual void* GetNativeWindow() const { return m_Window; }

		// Window attributes
		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		void SetBackgroundColor(sf::Color color);


	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
		
		void onEvent();

	private:

		sf::RenderWindow* m_Window;

		sf::Color m_Background = sf::Color::Black;


		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};
		WindowData m_Data;
	};





}