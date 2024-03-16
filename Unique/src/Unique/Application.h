#pragma once

#include "Core.h"


namespace Unique
{
	class UNQIUE_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	//To be define in CLIENT
	Application* CreateApplication();
}

