#pragma once

#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>;
#include <SDL_ttf.h>
#include <SDL_image.h>

class Window {
public:
	Window();
	void mainMenu();
	void level1();
	void level2();
	void level3();
	void score();

	bool isRunning();
	void close();

	SDL_Renderer* getRender();
};

#endif