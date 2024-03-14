#include <Unique.h>


class SpaceShooter : public Unique::Application
{
public:
	SpaceShooter() 
	{

	}
	~SpaceShooter() 
	{

	}

};


Unique::Application* Unique::CreateApplication()
{
	return new SpaceShooter();
}

