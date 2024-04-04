#include "PlatformFlowMenuState.h"

void PlatformFlowMenuState::Enter(PlatformLayer* layer)
{
	UQ_INFO("Begining Menu State : Game Library State");
	GameBlock* spaceShooter = new GameBlock(std::string("SpaceShooter"), sf::Vector2f(-175, -275));
	spaceShooter->SetScore(layer->GetPlayerData()->GetScore(spaceShooter->GetName()));
	m_GameBlockVector.push_back(spaceShooter);
	GameBlock* Shooter = new GameBlock(std::string("Shooter"), sf::Vector2f(225, -275));
	m_GameBlockVector.push_back(Shooter);
	GameBlock* Test1 = new GameBlock(std::string("Test1"), sf::Vector2f(-175, -50));
	m_GameBlockVector.push_back(Test1);
	GameBlock* Test2 = new GameBlock(std::string("Test2"), sf::Vector2f(225, -50));
	m_GameBlockVector.push_back(Test2);
	GameBlock* Test3 = new GameBlock(std::string("Test3"), sf::Vector2f(-175, 175));
	m_GameBlockVector.push_back(Test3);
	GameBlock* Test4 = new GameBlock(std::string("Test4"), sf::Vector2f(225, 175));
	m_GameBlockVector.push_back(Test4);
	Unique::Application::Get().GetWindow().SetBackgroundColor(42, 43, 43);

	m_Buttons.push_back(ButtonInfo("Your Game", ImVec2(270, 65), ImVec2(30, 125), MenuState::GameLibrary));
	m_Buttons.push_back(ButtonInfo("Reward", ImVec2(270, 65), ImVec2(30, 215), MenuState::Reward));

	
}

void PlatformFlowMenuState::OnUpdate(PlatformLayer* layer, Unique::Timestep ts)
{
	m_Time += ts;
	if (m_Time > m_PlayerDataNextCheckTime) 
	{
		m_PlayerDataNextCheckTime = m_Time + m_PlayerDataInterval;
		layer->GetPlayerData()->CheckAndReload();
		for (size_t i = 0; i < m_GameBlockVector.size(); i++)
		{
			m_GameBlockVector[i]->SetScore(layer->GetPlayerData()->GetScore(m_GameBlockVector[i]->GetName()));
		}
	}

	for (size_t i = 0; i < m_GameBlockVector.size(); i++)
	{
		m_GameBlockVector[i]->OnUpdate(ts);
	}
}

void PlatformFlowMenuState::OnRender(PlatformLayer* layer)
{
	for (size_t i = 0; i < m_GameBlockVector.size(); i++)
	{
		m_GameBlockVector[i]->OnRender();
	}
}

void PlatformFlowMenuState::OnImGuiRender(PlatformLayer* layer)
{


	// Left Plane

	auto window = static_cast<sf::RenderWindow*>(Unique::Application::Get().GetWindow().GetNativeWindow());
	ImVec2 windowSize = window->getSize();
	ImVec2 windowCenterPos = window->getSize();
	windowCenterPos.x /= 2.f;
	windowCenterPos.y /= 2.f;

	ImVec2 leftblockPos = ImVec2(0, 0);
	ImVec2 leftblockSize = ImVec2(windowSize.x * 0.25f, windowSize.y);
	ImVec4 squareColor = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
	ImGui::GetWindowDrawList()->AddRectFilled(leftblockPos,
		ImVec2(leftblockPos.x + leftblockSize.x, leftblockPos.y + leftblockSize.y), ImGui::ColorConvertFloat4ToU32(squareColor));
	auto titleTextPos = leftblockPos;
	titleTextPos.x += 45.f;
	titleTextPos.y += 20.f;
	ImGui::GetForegroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[0], 90.0f, titleTextPos, 0xffffffff, "Unique");


	ImGuiStyle& style = ImGui::GetStyle();
	ImVec4 originalButtonColor = style.Colors[ImGuiCol_Button];
	ImVec4 originalButtonHoveredColor = style.Colors[ImGuiCol_ButtonHovered];
	ImVec4 originalButtonActiveColor = style.Colors[ImGuiCol_ButtonActive];


	//  Buttons
	for (size_t i = 0; i < m_Buttons.size(); i++)
	{
		ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[1]);
		ImGui::SetCursorPos(m_Buttons[i].pos);
		if (m_Buttons[i].targetState == m_CurrentMenuState) 
		{
			style.Colors[ImGuiCol_Button] = ImVec4(0.1647f, 0.1686f, 0.1686f, 1.0f);
			style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.1647f, 0.1686f, 0.1686f, 1.0f);
			style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.1647f, 0.1686f, 0.1686f, 1.0f);
		}
		else
		{
			style.Colors[ImGuiCol_Button] = ImVec4(0.f, 0.f, 0.f, 1.0f);
			style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.f, 0.f, 0.f, 1.0f);
			style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.f, 0.f, 0.f, 1.0f);
		}

		if (ImGui::Button(m_Buttons[i].label.c_str(), m_Buttons[i].size)) {
			m_CurrentMenuState= m_Buttons[i].targetState;
			UQ_INFO("Change Menu State : {0}", m_Buttons[i].stateString);
		}
		
		ImGui::PopFont();
	}
	style.Colors[ImGuiCol_Button] = originalButtonColor;
	style.Colors[ImGuiCol_ButtonHovered] = originalButtonHoveredColor;
	style.Colors[ImGuiCol_ButtonActive] = originalButtonActiveColor;

	auto textPos = windowCenterPos;
	switch (m_CurrentMenuState)
	{
	case GameLibrary:
		for (size_t i = 0; i < m_GameBlockVector.size(); i++)
		{
			m_GameBlockVector[i]->OnImGuiRender();
		}
		break;
	case Reward:
		textPos.x -= 30.f;
		textPos.y -= 45.f;
		ImGui::GetForegroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[0], 90.0f, textPos, 0xffffffff, "Coming Soon...");
		break;
	default:
		break;
	}


}

void PlatformFlowMenuState::OnEvent(Event& e)
{
	for (size_t i = 0; i < m_GameBlockVector.size(); i++)
	{
		m_GameBlockVector[i]->OnEvent(e);
	}
}

void PlatformFlowMenuState::Exit(PlatformLayer* layer)
{
}
