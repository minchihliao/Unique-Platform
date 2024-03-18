#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"
#include "Unique/Events/ApplicationEvent.h"

namespace Unique
{
	class UNQIUE_API Application
	{
		public:
			Application();
			virtual ~Application();
			void Run();

			void OnEvent(Event& e);
		private:
			bool OnWindowClose(WindowCloseEvent& e);

			std::unique_ptr<Window> m_Window;
			bool m_Running = true;
	};

	//To be define in CLIENT
	Application* CreateApplication();
}

