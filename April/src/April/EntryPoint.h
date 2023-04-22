#pragma once

#ifdef AL_PLATFORM_WINDOWS

extern April::Application* April::CreateApplication();

int main(int argc, char** argv)
{
	auto app = April::CreateApplication();
	app->Run();
	delete app;
}

#endif // AL_PLATFORM_WINDOWS
