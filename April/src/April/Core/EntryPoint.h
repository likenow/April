#pragma once

#ifdef AL_PLATFORM_WINDOWS

extern April::Application* April::CreateApplication();

int main(int argc, char** argv)
{
    April::Log::Init();

    AL_PROFILE_BEGIN_SESSION("Startup", "AprilProfile-Startup.json");
    auto app = April::CreateApplication();
    AL_PROFILE_END_SESSION();

    AL_PROFILE_BEGIN_SESSION("Runtime", "AprilProfile-Runtime.json");
    app->Run();
    AL_PROFILE_END_SESSION();

    AL_PROFILE_BEGIN_SESSION("Startup", "AprilProfile-Shutdown.json");
    delete app;
    AL_PROFILE_END_SESSION();
}

#endif // AL_PLATFORM_WINDOWS
