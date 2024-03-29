#pragma once

#include "Unique/Core.h"
#include "Unique/Events/Event.h"
#include "Unique/LayerStack.h"
#include "Unique/ImGui/ImGuiLayer.h"
#include "Unique/Window.h"
#include "Unique/Events/ApplicationEvent.h"
#include "Unique/Timestep.h"


namespace Unique
{
	class UNIQUE_API Application
	{
		public:
			Application();
			virtual ~Application();
			void Run();

			void OnEvent(Event& e);
			void PushLayer(Layer* layer);
			void PushOverlay(Layer* layer);

			inline Window& GetWindow() { return *m_Window; }

			inline static Application& Get() { return *s_Instance; }
		private:
			bool OnWindowClose(WindowCloseEvent& e);
			bool OnWindowResize(WindowResizeEvent& e);
		private:
			std::unique_ptr<Window> m_Window;
			ImGuiLayer* m_ImGuiLayer;
			bool m_Running = true;
			bool m_Minimized = false;
			LayerStack m_LayerStack;
			float m_LastFrameTime = 0.0f;
			sf::Clock m_Clock; 
		private:
			static Application* s_Instance;
	};

	//To be define in CLIENT
	Application* CreateApplication();
}

