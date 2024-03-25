#include "GameLayer.h"

using namespace Unique;

GameLayer::GameLayer()
	: Layer("GameLayer")
{
	auto& window = Application::Get().GetWindow();
}

void GameLayer::OnAttach()
{
	//ImGuiIO io = ImGui::GetIO();
	//m_Font = io.Fonts->AddFontFromFileTTF("assets/OpenSans-Regular.ttf", 120.0f);
}

void GameLayer::OnDetach()
{
}

void GameLayer::OnUpdate()
{
	/*m_Time += ts;
	if ((int)(m_Time * 10.0f) % 8 > 4)
		m_Blink = !m_Blink;

	if (m_Level.IsGameOver())
		m_State = GameState::GameOver;

	const auto& playerPos = m_Level.GetPlayer().GetPosition();
	m_Camera->SetPosition({ playerPos.x, playerPos.y, 0.0f });*/

	//switch (m_State)
	//{
	//case GameState::Play:
	//{
	//	m_Level.OnUpdate(ts);
	//	break;
	//}
	//}

	//// Render
	//Hazel::RenderCommand::SetClearColor({ 0.0f, 0.0f, 0.0f, 1 });
	//Hazel::RenderCommand::Clear();

	//Hazel::Renderer2D::BeginScene(*m_Camera);
	//m_Level.OnRender();
	//Hazel::Renderer2D::EndScene();

	Unique::Ref<Unique::Texture2D> enemy = Unique::SFMLTexture::Create("assets/textures/enemy.png");
	Unique::Renderer2D::DrawSprite(sf::Vector2f(0.1, 0.1), sf::Vector2f(200, 200), enemy);
	Unique::Renderer2D::DrawCirclue(20, sf::Vector2f(20, 20), sf::Color::Green);

}

void GameLayer::OnImGuiRender()
{
	ImGui::Begin("Window");
	ImGui::Text("Window text!");
	ImGui::End();
	/*switch (m_State)
	{
	case GameState::Play:
	{
		uint32_t playerScore = m_Level.GetPlayer().GetScore();
		std::string scoreStr = std::string("Score: ") + std::to_string(playerScore);
		ImGui::GetForegroundDrawList()->AddText(m_Font, 48.0f, ImGui::GetWindowPos(), 0xffffffff, scoreStr.c_str());
		break;
	}
	case GameState::MainMenu:
	{
		auto pos = ImGui::GetWindowPos();
		auto width = Application::Get().GetWindow().GetWidth();
		auto height = Application::Get().GetWindow().GetHeight();
		pos.x += width * 0.5f - 300.0f;
		pos.y += 50.0f;
		if (m_Blink)
			ImGui::GetForegroundDrawList()->AddText(m_Font, 120.0f, pos, 0xffffffff, "Click to Play!");
		break;
	}
	case GameState::GameOver:
	{
		auto pos = ImGui::GetWindowPos();
		auto width = Application::Get().GetWindow().GetWidth();
		auto height = Application::Get().GetWindow().GetHeight();
		pos.x += width * 0.5f - 300.0f;
		pos.y += 50.0f;
		if (m_Blink)
			ImGui::GetForegroundDrawList()->AddText(m_Font, 120.0f, pos, 0xffffffff, "Click to Play!");

		pos.x += 200.0f;
		pos.y += 150.0f;
		uint32_t playerScore = m_Level.GetPlayer().GetScore();
		std::string scoreStr = std::string("Score: ") + std::to_string(playerScore);
		ImGui::GetForegroundDrawList()->AddText(m_Font, 48.0f, pos, 0xffffffff, scoreStr.c_str());
		break;
	}
	}*/
}

void GameLayer::OnEvent(Unique::Event& e)
{
	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<WindowResizeEvent>(UQ_BIND_EVENT_FN(GameLayer::OnWindowResize));
	dispatcher.Dispatch<MouseButtonPressedEvent>(UQ_BIND_EVENT_FN(GameLayer::OnMouseButtonPressed));
}

bool GameLayer::OnMouseButtonPressed(Unique::MouseButtonPressedEvent& e)
{
	if (m_State == GameState::GameOver)
		//m_Level.Reset();

	m_State = GameState::Play;
	return false;
}

bool GameLayer::OnWindowResize(Unique::WindowResizeEvent& e)
{
	//CreateCamera(e.GetWidth(), e.GetHeight());
	return false;
}

