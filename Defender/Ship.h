#pragma once

#ifndef SHIP_H
#define SHIP_H

#include "Window.h"

class Ship {
private:
	Window window;

	SDL_Texture* ship_right;
	SDL_Texture* ship_left;
	SDL_Rect rectShip;
	SDL_Texture* shoot;
	SDL_Rect rectShoot;
public:
	Ship();

	void draw();
	void update();

	void shipLogic();
};

#endif