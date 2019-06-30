#include "GL/glew.h"
#include "DERenderer.h"
#include "SDL.h"
#include "SDL_opengl.h"

#include <iostream>

struct DEGLData
{
	SDL_GLContext context = NULL; //shallow copy is intentional

	GLuint glProgramID = 0;
	GLuint glVertexPos2DLocation = -1;
	GLuint gVBO = 0;
	GLuint gIBO = 0;
};

DERenderer::DERenderer()
{
	glData = new DEGLData();
}


DERenderer::~DERenderer()
{
	delete glData;
}

bool DERenderer::Init(SDL_GLContext glContext)
{
	glData->context = glContext;
	if (glData->context == nullptr)
	{
		//TODO: sdl couldnt get a gl context
		std::cout << "ERROR: GLCONTEXT IS NULL";

		return false;
	}
	else
	{
		glewExperimental = GL_TRUE;
		GLenum glewError = glewInit();

		if (glewError != GLEW_OK)
		{
			//TODO: glew error
			std::cout << "ERROR: GLEW ERROR THREW code " + glewError;

			return false;
		}

		if (SDL_GL_SetSwapInterval(1) < 0) //TODO: vsync, turn it off later
		{
			//TODO: error setting vsync
			std::cout << "ERROR: COULDN'T GET VSYNC TO ENABLE";

			return false;
		}

		if (!InitOpenGL())
		{
			//TODO: error initializing opengl
			std::cout << "ERROR: COULDN'T INITIALIZE OPENGL";

			return false;
		}
	}
	return true;
}

bool DERenderer::InitOpenGL()
{
	return true;
}
