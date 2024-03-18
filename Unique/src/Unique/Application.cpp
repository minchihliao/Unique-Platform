#include "uqpch.h"
#include "Application.h"
#include "Unique/Events/ApplicationEvent.h"
#include "Unique/Log.h"

namespace Unique 
{
	Application::Application() 
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}
	Application::~Application()
	{
	
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
			while (m_Running)
			{
				UQ_TRACE(e);
				m_Window->OnUpdate();	
			}
		if (e.IsInCategory(EventCategoryInput))
		{
			UQ_TRACE(e);
		}

		while (true);

	}

}