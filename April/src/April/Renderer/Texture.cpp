#include "alpch.h"
#include "April/Renderer/Texture.h"

#include "April/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLTexture.h"

namespace April {

    Ref<Texture2D> Texture2D::Create(uint32_t width, uint32_t height)
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::API::None:    AL_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case RendererAPI::API::OpenGL:  return CreateRef<OpenGLTexture2D>(width, height);
        }

        AL_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

    Ref<Texture2D> Texture2D::Create(const std::string& path)
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::API::None:    AL_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case RendererAPI::API::OpenGL:  return CreateRef<OpenGLTexture2D>(path);
        }

        AL_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

}