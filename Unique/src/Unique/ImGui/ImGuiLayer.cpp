#include "uqpch.h"
#include "ImGuiLayer.h"

#include "Unique/Application.h"
#include "Unique/Platform/Windows/SFMLWindow.h"



namespace Unique {

	ImGuiLayer::ImGuiLayer()
		: Layer("ImGuiLayer")
	{
	}


	void ImGuiLayer::OnAttach()
	{
		UQ_CORE_INFO("Attach ImGuiLayer");
		auto window = static_cast<sf::RenderWindow*>(Application::Get().GetWindow().GetNativeWindow());
		ImGui::SFML::Init(*window);
		
	}

	void ImGuiLayer::OnDetach()
	{
	}

	void ImGuiLayer::Begin()
	{
		auto window = static_cast<sf::RenderWindow*>(Application::Get().GetWindow().GetNativeWindow());
		ImGui::SFML::Update(*window, deltaClock.restart());
	}

	void ImGuiLayer::End()
	{
		auto window = static_cast<sf::RenderWindow*>(Application::Get().GetWindow().GetNativeWindow());
		ImGui::SFML::Render(*window);
	}


	void ImGuiLayer::OnImGuiRender()
	{
		//Render ----
		ImGui::Begin("Window title");
		ImGui::Text("Window text!");
		ImGui::End();
		//---------
		
	}

	void ImGuiLayer::OnEvent(Event& event)
	{
		sf::Event e;
		auto window = static_cast<sf::RenderWindow*>(Application::Get().GetWindow().GetNativeWindow());
		while (window->pollEvent(e))
		{
			ImGui::SFML::ProcessEvent(e);
		}
	}

}