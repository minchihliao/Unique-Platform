#include <Unique.h>
//--- Entry Point ---------------------
#include "Unique/EntryPoint.h"
//-------------------------------------

#include "PlatformLayer.h"



class UniquePlatform : public Unique::Application
{
public:
	UniquePlatform(Unique::WindowProps windowProps)
		:Application(windowProps)
	{
		PushLayer(new PlatformLayer());
	}
	~UniquePlatform() 
	{
	
	}

};

Unique::Application* Unique::CreateApplication()
{
	return new UniquePlatform(Unique::WindowProps("Unique Platform", 1280,800));
}

