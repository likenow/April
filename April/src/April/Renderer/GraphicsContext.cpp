#include "alpch.h"
#include "April/Renderer/GraphicsContext.h"

#include "April/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace April {

    Scope<GraphicsContext> GraphicsContext::Create(void* window)
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::API::None:    AL_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
        }

        AL_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

}