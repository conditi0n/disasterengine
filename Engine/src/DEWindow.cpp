#include "DEWindow.h"
#include "SDL.h"
#include "SDL_events.h"
#include <iostream>

DEWindow::DEWindow(int width, int height, char* title) : renderer(), window(NULL), event(new SDL_Event())
{

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		//TODO: sdl error
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
			//TODO: window creation error
			std::cout << "ERROR";
		}
		else
		{
			renderer.Init(SDL_GL_CreateContext(window));
		}
	}
	
}


DEWindow::~DEWindow()
{
	delete event;
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void DEWindow::Update()
{
	while (SDL_PollEvent(event) != 0)
	{
		eventID = event->type;
	}
}
