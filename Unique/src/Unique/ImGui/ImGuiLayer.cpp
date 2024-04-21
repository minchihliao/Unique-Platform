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
		auto window = static_cast<sf::RenderWindow*>(Application::Get().GetWindow().GetNativeWindow());
		ImGui::SFML::Init(*window,false);
		ImGuiIO& IO = ImGui::GetIO();
		IO.Fonts->Clear(); 
		IO.Fonts->AddFontFromFileTTF("assets/OpenSans-Regular.ttf",120.0f);
		IO.Fonts->AddFontFromFileTTF("assets/OpenSans-Regular.ttf", 60.0f);
		ImGui::SFML::UpdateFontTexture(); // important call: updates font texture
	}

	void ImGuiLayer::OnDetach()
	{
	}

	void ImGuiLayer::Begin()
	{
		auto window = static_cast<sf::RenderWindow*>(Application::Get().GetWindow().GetNativeWindow());
		ImGui::SFML::Update(*window, deltaClock.restart());
		ImGui::SetNextWindowPos(ImVec2(0, 0));
		ImGui::SetNextWindowSize(ImVec2(window->getSize()));
		ImGui::Begin("##TransparentWindow", nullptr, ImGuiWindowFlags_NoDecoration |ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize
			| ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse 
			| ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoBackground );
	}

	void ImGuiLayer::End()
	{
		ImGui::End();
	}

	void ImGuiLayer::Render()
	{
		auto window = static_cast<sf::RenderWindow*>(Application::Get().GetWindow().GetNativeWindow());
		ImGui::SFML::Render(*window);
	}


	void ImGuiLayer::OnImGuiRender()
	{
		//Render ----
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