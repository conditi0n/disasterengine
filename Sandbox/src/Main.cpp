#include "DEWindow.h"

int main(int argc, char* args[])
{
	char title[] = "Sandbox";
	DEWindow display(800, 640, title);
	bool quit = false;
	while (display.eventID != 256)
	{
		display.Update();
	}
	return 0;
}