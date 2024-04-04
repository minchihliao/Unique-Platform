#include "PlatformLayer.h"



PlatformLayer::PlatformLayer()
	:Layer("PlatformLayer")
{
	m_PlatformStateMachine = new PlatformStateMachine(this);
	char path[MAX_PATH] = { 0 };
	GetModuleFileNameA(nullptr, path, MAX_PATH);
	std::filesystem::path execPath = std::string(path);
	std::filesystem::path saveDir = execPath.parent_path() / "PlayerData.json";
	m_PlayerData = new Unique::PlayerData(saveDir.string());
}

void PlatformLayer::OnAttach()
{
	m_PlatformStateMachine->Init();
	m_PlatformStateMachine->ChangeState(PlatformState::Init);
}

void PlatformLayer::OnDetach()
{
	
}

void PlatformLayer::OnUpdate(Unique::Timestep ts)
{
	m_PlatformStateMachine->OnUpdate(ts);
}

void PlatformLayer::OnRender(Unique::Timestep ts)
{
	m_PlatformStateMachine->OnRender();
	
}

void PlatformLayer::OnImGuiRender()
{
	m_PlatformStateMachine->OnImGuiRender();
}

void PlatformLayer::OnEvent(Unique::Event& e)
{
	m_PlatformStateMachine->OnEvent(e);
}

bool PlatformLayer::OnMouseButtonPressed(Unique::MouseButtonPressedEvent& e)
{
	return false;
}

bool PlatformLayer::OnWindowResize(Unique::WindowResizeEvent& e)
{
	return false;
}

