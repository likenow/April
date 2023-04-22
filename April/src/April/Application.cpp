#include "alpch.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"
#include"April/Log.h"

namespace April {
	Application::Application ()
	{}

	Application::~Application()
	{}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			AL_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			AL_TRACE(e);
		}
		while (true);
	}
}