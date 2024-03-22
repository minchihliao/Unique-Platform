#include "uqpch.h"
#include "ImGuiLayer.h"

#include "Unique/Application.h"
#include "Unique/Platform/Windows/SFMLWindow.h"




namespace Unique {

	ImGuiLayer::ImGuiLayer()
		: Layer("ImGuiLayer")
	{
	}

	ImGuiLayer::~ImGuiLayer()
	{
		ImGui::SFML::Shutdown();
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

	void ImGuiLayer::OnUpdate()
	{
		auto window = static_cast<sf::RenderWindow*>(Application::Get().GetWindow().GetNativeWindow());
		ImGui::SFML::Update(*window, deltaClock.restart());
		//Render ----
		ImGui::Begin("Window title");
		ImGui::Text("Window text!");
		ImGui::End();
		//---------
		ImGui::SFML::Render(*window);
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