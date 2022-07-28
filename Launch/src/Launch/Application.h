#pragma once

#include "Core.h"

namespace Launch
{
	class LAUNCH_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client
	Application* CreateApplication();
}

