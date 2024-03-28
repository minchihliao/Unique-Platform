#include <Unique.h>
//--- Entry Point ---------------------
#include "Unique/EntryPoint.h"
//-------------------------------------

#include "GameLayer.h"

class ExampleLayer : public Unique::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate(Unique::Timestep ts) override
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
		PushLayer(new GameLayer());
	}
	~SpaceShooter() 
	{

	}

};


Unique::Application* Unique::CreateApplication()
{
	return new SpaceShooter();
}

