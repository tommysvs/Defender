#pragma once

#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "Window.h"

class Background {
private:
	Window window;

	SDL_Texture* ground;
	SDL_Texture* stars;
	SDL_Rect rectGround;
	SDL_Rect rectStars;
public:
	Background();

	void draw();
	void update();
};

#endif