#include <Unique.h>


class ExampleLayer : public Unique::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		UQ_INFO("ExampleLayer::Update");
	}

	void OnEvent(Unique::Event& event) override
	{
		UQ_TRACE("{0}", event);
	}

};

class SpaceShooter : public Unique::Application
{
public:
	SpaceShooter() 
	{
		//PushLayer(new ExampleLayer());
		//PushLayer(new Unique::ImGuiLayer());
	}
	~SpaceShooter() 
	{

	}

};


Unique::Application* Unique::CreateApplication()
{
	return new SpaceShooter();
}

