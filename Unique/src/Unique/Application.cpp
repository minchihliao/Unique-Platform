#include "uqpch.h"
#include "Application.h"
#include "Unique/Events/ApplicationEvent.h"
#include "Unique/Log.h"
#include "Input.h"



namespace Unique 
{
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

	Application::Application() 
	{
		UQ_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);
	}
	Application::~Application()
	{
	
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();

	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(Application::OnWindowResize));

		//UQ_CORE_TRACE("{0}", e);

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}


	void Application::Run()
	{
		
		while (m_Running)
		{
			float time = m_Clock.getElapsedTime().asSeconds();
			Timestep timestep = time - m_LastFrameTime;
			m_LastFrameTime = time;

			m_Window->OnEvent();

			for (Layer* layer : m_LayerStack) {
				layer->OnUpdate(timestep);
			}
			
			m_Window->Render();
			for (Layer* layer : m_LayerStack) {
				layer->OnRender(timestep);
			}


			m_ImGuiLayer->Begin();
			for (Layer* layer : m_LayerStack)
				layer->OnImGuiRender();
			m_ImGuiLayer->End();
			m_ImGuiLayer->Render();

			m_Window->EndUpdate();
		}
		
	}

	void Application::End()
	{
		ImGui::SFML::Shutdown();
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
	bool Application::OnWindowResize(WindowResizeEvent& e)
	{
		if (e.GetWidth() == 0 || e.GetHeight() == 0)
		{
			m_Minimized = true;
			return false;
		}

		m_Minimized = false;
		//Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());

		return false;
	}

}