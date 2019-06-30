#pragma once
#include <stdint.h>
#include "DERenderer.h"

/* The DisasterEngine Window. Opens up a display using SDL2 that renders things on-screen.
*/
class __declspec(dllexport) DEWindow
{
	//TODO: rule of 5

public:
	uint32_t eventID = 0; //flag representing the current window event. if its 256, the user hit the X or alt-f4

private:
	DERenderer renderer;
	struct SDL_Window* window;
	union SDL_Event* event;
public:

	/* Create a new SDL2, OpenGL Window in the center of the screen with the specified width, height, in pixels, and window title.
	*/
	DEWindow(int width, int height, char* title);
	virtual ~DEWindow();

	/* Run in a loop to capture SDL window events (like exiting out of the window). This returns 1 if there is an active event, or 0 otherwise.
	   This function changes the eventID member of this class.
	*/
	void Update();
};

