#pragma once

#ifdef UQ_PLAFORM_WINDOWS

extern Unique::Application* Unique::CreateApplication();

int main(int arg,char** argv) {
	Unique::Log::Init();
	UQ_CORE_WARN("Initialize Log!");
	UQ_INFO("Hello!");
	
	auto app = Unique::CreateApplication();
	app->Run();
	app->End();
	delete app;
}


#else
	#error Unique only supports Windos!
#endif // UQ_PLAFORM_WINDOWS
