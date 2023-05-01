#include "alpch.h"

#include "April/Renderer/RenderCommand.h"

namespace April {

    Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

}