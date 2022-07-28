#pragma once

#ifdef LN_PLATFORM_WINDOWS

extern Launch::Application* Launch::CreateApplication();

int main(int argc, char** argv)
{
	LN_CORE_PRINT("Initializing Log...\n");
	Launch::Log::Init();

	LN_CORE_INFO("Launching application...");
	Launch::Application* app = Launch::CreateApplication();
	app->Run();
	delete app;
}

#endif // LN_PLATFORM_WINDOWS
