#include "uqpch.h"
#include "Application.h"
#include "Unique/Events/ApplicationEvent.h"
#include "Unique/Log.h"

namespace Unique 
{
	Application::Application() 
	{
	
	}
	Application::~Application()
	{
	
	}

	void Application::Run()
	{
        sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
        sf::CircleShape shape(100.f);
        shape.setFillColor(sf::Color::Red);

        while (true)
        {

            window.clear();
            window.draw(shape);
            window.display();
        }

	}

}