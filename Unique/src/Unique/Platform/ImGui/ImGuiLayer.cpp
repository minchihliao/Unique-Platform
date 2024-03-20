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
	}

	void ImGuiLayer::OnAttach()
	{
		UQ_CORE_INFO("Attach ImGuiLayer");
	
		auto window = dynamic_cast<SFMLWindow*>(&Application::Get().GetWindow());
		ImGui::SFML::Init(window->GetSFMLWindow());
		
	}

	void ImGuiLayer::OnDetach()
	{

	}

	void ImGuiLayer::OnUpdate()
	{
		UQ_CORE_INFO("ImGuiLayer Update");
		auto window = dynamic_cast<SFMLWindow*>(&Application::Get().GetWindow());
		ImGui::SFML::Update(window->GetSFMLWindow(), deltaClock.restart());
		//Render ----
		ImGui::Begin("Window title");
		ImGui::Text("Window text!");
		ImGui::End();
		//---------
		ImGui::SFML::Render(window->GetSFMLWindow());
	}

	void ImGuiLayer::OnEvent(Event& event)
	{
		sf::Event e;
		auto window = dynamic_cast<SFMLWindow*>(&Application::Get().GetWindow());
		while (window->GetSFMLWindow().pollEvent(e))
		{
			ImGui::SFML::ProcessEvent(e);
		}
	}

}