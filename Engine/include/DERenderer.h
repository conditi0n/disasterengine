#pragma once

/* Originally declared in SDL.h, this is an opaque handle to a GL context, created by SDL. */
typedef void* SDL_GLContext;

struct __declspec(dllexport) DERenderer
{
private:
	struct DEGLData* glData; //pimpl

public:
	DERenderer();
	~DERenderer();

	/*Initialize the SDL_GLContext, OpenGL, and GLEW. */
	bool Init(SDL_GLContext context);

private:
	bool InitOpenGL();
};

