#include <Unique.h>
//--- Entry Point ---------------------
#include "Unique/EntryPoint.h"
//-------------------------------------

#include "GameLayer.h"


class SpaceShooter : public Unique::Application
{
public:
	SpaceShooter(Unique::WindowProps windowProps)
		:Application(windowProps)
	{
		PushLayer(new GameLayer());
	}
	~SpaceShooter() 
	{

	}

};


Unique::Application* Unique::CreateApplication()
{
	return new SpaceShooter(Unique::WindowProps("Space Shooter", 1280, 800));
}

