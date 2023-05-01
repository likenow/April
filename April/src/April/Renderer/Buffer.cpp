#include "alpch.h"
#include "April/Renderer/Buffer.h"

#include "April/Renderer/Renderer.h"

#include "Platform/OpenGL/OpenGLBuffer.h"

namespace April {

    Ref<VertexBuffer> VertexBuffer::Create(float* vertices, uint32_t size)
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::API::None:    AL_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case RendererAPI::API::OpenGL:  return CreateRef<OpenGLVertexBuffer>(vertices, size);
        }

        AL_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

    Ref<IndexBuffer> IndexBuffer::Create(uint32_t* indices, uint32_t size)
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::API::None:    AL_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case RendererAPI::API::OpenGL:  return  CreateRef<OpenGLIndexBuffer>(indices, size);
        }

        AL_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

}