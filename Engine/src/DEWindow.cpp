#include "DEWindow.h"
#include "SDL.h"

DEWindow::DEWindow(int width, int height, char* title) : window(NULL), renderer()
{

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		//sdl error
	}
	else
	{
		//set the openGL version to 3.3 core profile
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
		if (window == NULL)
		{
			//window creation error
		}
		else
		{
			renderer.Init(SDL_GL_CreateContext(window));
		}
		SDL_Delay(2000);
	}
}


DEWindow::~DEWindow()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}

