#include "alpch.h"

#include "April/Renderer/VertexArray.h"

#include "April/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace April {

    Ref<VertexArray> VertexArray::Create()
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::API::None:    AL_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case RendererAPI::API::OpenGL:  return CreateRef<OpenGLVertexArray>();
        }

        AL_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

}