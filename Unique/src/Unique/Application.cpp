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
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			UQ_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			UQ_TRACE(e);
		}

		while (true);
	}

}