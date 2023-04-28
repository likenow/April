#include "alpch.h"

#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace April {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}