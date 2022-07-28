#include "Application.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Logging/Log.h"

namespace Launch
{
	Application::Application()
	{
	}
	Application::~Application()
	{
	}
	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
			LN_TRACE(e);
		if (e.IsInCategory(EventCategoryInput))
			LN_TRACE(e);

		while (true);
	}
}