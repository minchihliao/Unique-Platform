
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
		//ImGui::SFML::Init(*m_Window);
		m_Window->setFramerateLimit(60);
		//ImGui::SFML::Init(*m_Window);
		//m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		//glfwMakeContextCurrent(m_Window);
		//glfwSetWindowUserPointer(m_Window, &m_Data);
		//auto circle = std::make_shared<sf::CircleShape>(50);
		//circle->setFillColor(sf::Color::Green);
		//AddGameObject(circle);
		
	}

	void SFMLWindow::Shutdown()
	{
		ImGui::SFML::Shutdown();
		m_Window->close();
	}

	

	void SFMLWindow::OnUpdate()
	{
		sf::Clock deltaClock;
		if (m_Window->isOpen())
		{
			OnEvent();
			/*ImGui::SFML::Update(*m_Window, deltaClock.restart());
			ImGui::Begin("Window title");
			ImGui::Text("Window text!");
			ImGui::End();*/
			
			
			/*ImGui::SFML::Render(*m_Window);*/
			
		}

	}

	void SFMLWindow::BegineUpdate()
	{
		if (m_Window->isOpen())
		{
			OnEvent();
			m_Window->clear();
		}
	}

	void SFMLWindow::Render()
	{
		if (m_Window->isOpen())
		{
			if (!m_Objs.empty()) {
				for (auto& obj : m_Objs)
				{
					m_Window->draw(*obj);
				}
			}
		}
	}

	void SFMLWindow::EndUpdate()
	{
		m_Window->display();
	}

	void SFMLWindow::OnEvent()
	{
		sf::Event event;
		while (m_Window->pollEvent(event))
		{
			/*ImGui::SFML::ProcessEvent(event);*/
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

	void SFMLWindow::SetBackgroundColor(sf::Color color)
	{
		m_Background = color;
	}

	void SFMLWindow::AddGameObject(const std::shared_ptr<sf::Drawable>& drawable)
	{
		m_Objs.push_back(drawable);
	}

	void SFMLWindow::SetVSync(bool enabled)
	{
	}

	bool SFMLWindow::IsVSync() const
	{
		return m_Data.VSync;
	}





}