#pragma once

#include <SDL.h>;
#include <SDL_ttf.h>
#include <SDL_image.h>

class Window {
public:
	Window();
	void winInit();

	bool isRunning();
	void close();

	SDL_Renderer* getRender();
};