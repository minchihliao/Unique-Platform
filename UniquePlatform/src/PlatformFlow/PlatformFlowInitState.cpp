#include "PlatformFlowInitState.h"

void PlatformFlowInitState::Enter(PlatformLayer* layer)
{
	UQ_INFO("Platform Init");
}

void PlatformFlowInitState::OnUpdate(PlatformLayer* layer, Unique::Timestep ts)
{
	m_Time += ts;

	if (m_Time > m_WaitingTime && m_Start == false) 
	{
		m_Start = true;
		layer->GetFlowStateMachine()->ChangeState(PlatformState::Menu);
	
	}
}

void PlatformFlowInitState::OnRender(PlatformLayer* layer)
{
}

void PlatformFlowInitState::OnImGuiRender(PlatformLayer* layer)
{
	if (m_Start)
		return;

	auto window = static_cast<sf::RenderWindow*>(Unique::Application::Get().GetWindow().GetNativeWindow());
	ImVec2 windowCenterPos = window->getSize();
	windowCenterPos.x /= 2.f;
	windowCenterPos.y /= 2.f;

	auto logoTextPos = windowCenterPos;
	logoTextPos.x -= 500.f;
	logoTextPos.y -= 100.f;
	ImGui::GetForegroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[0], 180.f, logoTextPos, 0xffffffff, "Unique Platform");

	auto madeTextPos = windowCenterPos;
	madeTextPos.x += 250.f;
	madeTextPos.y += 325.f;
	ImGui::GetForegroundDrawList()->AddText(ImGui::GetIO().Fonts->Fonts[0], 50.f, madeTextPos, 0xffffffff, "Made By Richard Liao");
}

void PlatformFlowInitState::Exit(PlatformLayer* layer)
{
}
