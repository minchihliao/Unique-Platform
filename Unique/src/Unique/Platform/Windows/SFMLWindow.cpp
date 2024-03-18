
#include "uqpch.h"
#include "SFMLWindow.h"
#include <SFML/Graphics.hpp>


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
		//m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		//glfwMakeContextCurrent(m_Window);
		//glfwSetWindowUserPointer(m_Window, &m_Data);
		auto circle = std::make_shared<sf::CircleShape>(50);
		circle->setFillColor(sf::Color::Green);
		AddGameObject(circle);
		
	}

	void SFMLWindow::Shutdown()
	{
		m_Window->close();
	}

	void SFMLWindow::OnUpdate()
	{
		if (m_Window->isOpen())
		{
			m_Window->clear();
			if (!m_Objs.empty()) {
				for (auto& obj : m_Objs)
				{
					m_Window->draw(*obj);
				}
			}
			m_Window->display();
		}

		/*sf::Event event;
		if(m_Window->pollEvent(event))
		{
		}*/
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