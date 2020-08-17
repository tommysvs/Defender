#pragma once

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL.h>
#include "Window.h"

class Graphics {
public:
	Graphics();

	void render();
	void setPosition(int, int);
	void setTexture(SDL_Texture*);
	void setRect(SDL_Rect);

	SDL_Rect getRect();
	Window window;
private:
	SDL_Texture* texture;
	SDL_Rect rect;
};

#endif