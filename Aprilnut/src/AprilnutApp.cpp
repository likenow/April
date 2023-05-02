#include <April.h>
// Entry point
#include <April/Core/EntryPoint.h>
#include "EditorLayer.h"

class Aprilnut : public April::Application
{
public:
    Aprilnut()
        : Application("April Editor")
    {
        PushLayer(new April::EditorLayer());
    }
    ~Aprilnut()
    {}
};

April::Application* April::CreateApplication()
{
    return new Aprilnut();
}