
#include "uqpch.h"
#include "SFMLWindow.h"


#include "Unique/Events/ApplicationEvent.h"
#include "Unique/Events/MouseEvent.h"
#include "Unique/Events/KeyEvent.h"

namespace Unique
{

	Window* Window::Create(const WindowProps& props)
	{
		return new SFMLWindow(props);
	}

	SFMLWindow::SFMLWindow(const WindowProps& props)
	{
		Init(props);
	}

	SFMLWindow::~SFMLWindow()
	{
		Shutdown();
	}



	void SFMLWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		UQ_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);


		m_Window = new sf::RenderWindow(sf::VideoMode((int)props.Width, (int)props.Height), m_Data.Title);
		m_Window->setFramerateLimit(60);
		
	}

	void SFMLWindow::Shutdown()
	{
		m_Window->close();
	}

	

	void SFMLWindow::OnUpdate()
	{
		if (m_Window->isOpen())
		{
			OnEvent();
		}

	}

	void SFMLWindow::OnEvent()
	{
		if (m_Window->isOpen())
		{
			onEvent();
			
		}
	}

	void SFMLWindow::Render()
	{
		if (m_Window->isOpen())
		{
			m_Window->clear(m_Background);
		}
	}


	void SFMLWindow::EndUpdate()
	{
		if (m_Window->isOpen())
		{
			m_Window->display();
		}
	}

	void SFMLWindow::onEvent()
	{
		sf::Event event;
		while (m_Window->pollEvent(event))
		{
			if (event.type == sf::Event::Resized) {
				m_Data.Width = event.size.width;
				m_Data.Height = event.size.height;
				WindowResizeEvent event(m_Data.Width, m_Data.Height);
				m_Data.EventCallback(event);
			}

			if (event.type == sf::Event::Closed) {
				WindowCloseEvent event;
				m_Data.EventCallback(event);
			}

			//Keyboard
			if (event.type == sf::Event::KeyPressed) 
			{
				KeyPressedEvent event(event.key.code, 0);
				m_Data.EventCallback(event);
			}

			if (event.type == sf::Event::KeyReleased)
			{
				KeyReleasedEvent  event(event.key.code);
				m_Data.EventCallback(event);
			}

			//Mouse
			if (event.type == sf::Event::MouseButtonPressed)
			{
				MouseButtonPressedEvent event(event.mouseButton.button);
				m_Data.EventCallback(event);
			}

			if (event.type == sf::Event::MouseButtonReleased)
			{
				MouseButtonReleasedEvent event(event.mouseButton.button);
				m_Data.EventCallback(event);
			}

			if (event.type == sf::Event::MouseWheelScrolled)
			{
				MouseScrolledEvent event(0, (float)event.mouseWheelScroll.delta);
				m_Data.EventCallback(event);
			}

			//Cursor
			if (event.type == sf::Event::MouseMoved)
			{
				MouseMovedEvent event((float)event.mouseMove.x, (float)event.mouseMove.y);
				m_Data.EventCallback(event);
			}


		}
	}

	void SFMLWindow::SetBackgroundColor(float r, float g, float b)
	{
		m_Background = sf::Color(r,g,b);
	}


	void SFMLWindow::SetVSync(bool enabled)
	{
	}

	bool SFMLWindow::IsVSync() const
	{
		return m_Data.VSync;
	}





}