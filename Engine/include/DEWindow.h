#pragma once
#include "DERenderer.h"

/* The DisasterEngine Window. Opens up a display using SDL2 that renders things on-screen.
*/
class __declspec(dllexport) DEWindow
{
	DERenderer renderer;
	struct SDL_Window* window;
public:

	/* Create a new SDL2, OpenGL Window in the center of the screen with the specified width, height, and window title.
	*/
	DEWindow(int width, int height, char* title);
	virtual ~DEWindow();
	//TODO: rule of 5
};

