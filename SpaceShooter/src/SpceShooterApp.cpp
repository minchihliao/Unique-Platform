#include <Unique.h>

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
glm::mat4 camera(float Translate, glm::vec2 const& Rotate)
{
	glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.f);
	glm::mat4 View = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -Translate));
	View = glm::rotate(View, Rotate.y, glm::vec3(-1.0f, 0.0f, 0.0f));
	View = glm::rotate(View, Rotate.x, glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 Model = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
	return Projection * View * Model;
}



class ExampleLayer : public Unique::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
		auto cam = camera(5.0f, { 0.5f,0.5f });

	}

	void OnUpdate() override
	{
		//UQ_INFO("ExampleLayer::Update");
		if (Unique::Input::IsKeyPressed(UQ_KEY_Tab))
			UQ_TRACE("Tab key is pressed (poll)!");
	}

	void OnEvent(Unique::Event& event) override
	{
		//UQ_TRACE("{0}", event);

		if (event.GetEventType() == Unique::EventType::KeyPressed)
		{
	
			Unique::KeyPressedEvent& e = (Unique::KeyPressedEvent&)event;
			if (e.GetKeyCode() == UQ_KEY_Tab)
				UQ_TRACE("Tab key is pressed (event)!");
			UQ_TRACE("{0}", e.GetKeyCode());
		}
	}

};

class SpaceShooter : public Unique::Application
{
public:
	SpaceShooter() 
	{
		PushLayer(new ExampleLayer());
		PushLayer(new Unique::ImGuiLayer());
	}
	~SpaceShooter() 
	{

	}

};


Unique::Application* Unique::CreateApplication()
{
	return new SpaceShooter();
}

