#pragma once

#ifndef MOUSE_H
#define MOUSE_H

#include <SDL.h>

class Mouse {
public:
	Mouse();

	void setXY(int, int);
	void controlMotion(int, int);
	bool isPressed(SDL_Rect);
	bool mouseMotion(SDL_Rect);
};

#endif