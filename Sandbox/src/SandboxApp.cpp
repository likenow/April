#include <April.h>

class Sandbox : public April::Application
{
public:
    Sandbox()
    {}
    ~Sandbox()
    {}
};

April::Application* April::CreateApplication()
{
    return new Sandbox();
}