#include "uqpch.h"
#include "ImGuiLayer.h"
#include "imgui.h"
//#include "imgui-SFML.h"
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
	
		//auto window = dynamic_cast<SFMLWindow*>(&Application::Get().GetWindow());

		//ImGui::SFML::Init(window->GetSFMLWindow());
	}

	void ImGuiLayer::OnDetach()
	{

	}

	void ImGuiLayer::OnUpdate()
	{
		//auto window = dynamic_cast<SFMLWindow*>(&Application::Get().GetWindow());
		//ImGui::SFML::Update(window->GetSFMLWindow(), deltaClock.restart());
		//float color[3] = { 0.f, 0.f, 0.f };
		//sf::Color bgColor;
		//// begin window
		//	ImGui::Begin("Sample window");
		//// Background color edit
		//if (ImGui::ColorEdit3("Background color", color)) {

		//	bgColor.r = static_cast<sf::Uint8>(color[0] * 255.f);
		//	bgColor.g = static_cast<sf::Uint8>(color[1] * 255.f);
		//	bgColor.b = static_cast<sf::Uint8>(color[2] * 255.f);
		//}

		//ImGui::End(); // end window
		//ImGui::SFML::Render(window->GetSFMLWindow());
	}

	void ImGuiLayer::OnEvent(Event& event)
	{

	}

}