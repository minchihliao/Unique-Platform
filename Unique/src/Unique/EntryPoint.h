#pragma once

#ifdef UQ_PLAFORM_WINDOWS

extern Unique::Application* Unique::CreateApplication();

int main(int arg,char** argv) {
	printf("Unique Engine");
	auto app = Unique::CreateApplication();
	app->Run();
	delete app;
}


#else
	#error Unique only supports Windos!
#endif // UQ_PLAFORM_WINDOWS
