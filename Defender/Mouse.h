#pragma once

#include <SDL.h>

class Mouse {
public:
	Mouse();

	void setXY(int, int);
	void controlMotion(int, int);
	bool wasPressed(SDL_Rect);
	bool mouseMotion(SDL_Rect);
};