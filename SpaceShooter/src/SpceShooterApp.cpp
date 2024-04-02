#include <Unique.h>
//--- Entry Point ---------------------
#include "Unique/EntryPoint.h"
//-------------------------------------

#include "GameLayer.h"


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

