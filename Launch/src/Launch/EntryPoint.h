#pragma once

#ifdef LN_PLATFORM_WINDOWS

extern Launch::Application* Launch::CreateApplication();

int main(int argc, char** argv)
{
	Launch::Application* app = Launch::CreateApplication();
	app->Run();
	delete app;
}

#endif // LN_PLATFORM_WINDOWS
