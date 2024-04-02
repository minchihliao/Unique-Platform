#include "PlatformLayer.h"



PlatformLayer::PlatformLayer()
{
	
}

void PlatformLayer::OnAttach()
{
	GameBlock* spaceShooter = new GameBlock(std::string("SpaceShooter"),sf::Vector2f(-350,-300));
	m_GameBlockVector.push_back(spaceShooter);
	GameBlock* Shooter = new GameBlock(std::string("Shooter"), sf::Vector2f(225, -300));
	m_GameBlockVector.push_back(Shooter);
	GameBlock* Test1 = new GameBlock(std::string("Test1"), sf::Vector2f(-350, 100));
	m_GameBlockVector.push_back(Test1);
	GameBlock* Test2 = new GameBlock(std::string("Test2"), sf::Vector2f(225, 100));
	m_GameBlockVector.push_back(Test2);
	for (size_t i = 0; i < m_GameBlockVector.size(); i++)
	{
		m_GameBlockVector[i]->OnAttach();
	}
}

void PlatformLayer::OnDetach()
{
	for (size_t i = 0; i < m_GameBlockVector.size(); i++)
	{
		m_GameBlockVector[i]->OnDetach();
	}
}

void PlatformLayer::OnUpdate(Unique::Timestep ts)
{
	for (size_t i = 0; i < m_GameBlockVector.size(); i++)
	{
		m_GameBlockVector[i]->OnUpdate(ts);
	}
}

void PlatformLayer::OnRender(Unique::Timestep ts)
{
	for (size_t i = 0; i < m_GameBlockVector.size(); i++)
	{
		m_GameBlockVector[i]->OnRender(ts);
	}
}

void PlatformLayer::OnImGuiRender()
{
	for (size_t i = 0; i < m_GameBlockVector.size(); i++)
	{
		m_GameBlockVector[i]->OnImGuiRender();
	}
}

void PlatformLayer::OnEvent(Unique::Event& e)
{
	for (size_t i = 0; i < m_GameBlockVector.size(); i++)
	{
		m_GameBlockVector[i]->OnEvent(e);
	}
}

bool PlatformLayer::OnMouseButtonPressed(Unique::MouseButtonPressedEvent& e)
{
	return false;
}

bool PlatformLayer::OnWindowResize(Unique::WindowResizeEvent& e)
{
	return false;
}

