#pragma once

#ifdef AL_PLATFORM_WINDOWS

extern April::Application* April::CreateApplication();

int main(int argc, char** argv)
{
	April::Log::Init();
	AL_CORE_WARN("Initialized Log!");
	AL_CORE_INFO("Hello Log!");

	auto app = April::CreateApplication();
	app->Run();
	delete app;
}

#endif // AL_PLATFORM_WINDOWS
