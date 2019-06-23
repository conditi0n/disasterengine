#include "GL/glew.h"
#include "DERenderer.h"
#include "SDL.h"
#include "SDL_opengl.h"

struct DEGLData
{
	SDL_GLContext context = NULL;

	GLuint glProgramID = 0;
	GLuint glVertexPos2DLocation = -1;
	GLuint gVBO = 0;
	GLuint gIBO = 0;

	//TODO: rule of 5
};

DERenderer::DERenderer() : glData()
{
}


DERenderer::~DERenderer()
{
}

bool DERenderer::Init(SDL_GLContext glContext)
{
	glData->context = glContext;
	if (glData->context == nullptr)
	{
		//sdl couldnt get a gl context
		return false;
	}
	else
	{
		glewExperimental = GL_TRUE;
		GLenum glewError = glewInit();

		if (glewError != GLEW_OK)
		{
			//glew error
			return false;
		}

		if (SDL_GL_SetSwapInterval(1) < 0) //TODO: vsync, turn it off later
		{
			//error setting vsync
			return false;
		}

		if (!InitOpenGL())
		{
			//error initializing opengl
			return false;
		}
	}
	return true;
}

bool DERenderer::InitOpenGL()
{
	return false;
}
