#pragma once
#include "Core.h"

namespace April {
	class APRIL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in Client
	Application* CreateApplication();
}