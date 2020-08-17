#pragma once

#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "Scene.h"
#include "SceneManager.h"
#include "Window.h"
#include "Mouse.h"
#include "Keyboard.h"

class MainMenu : public Scene {
public:
	MainMenu();

	virtual void draw();
	virtual void update();
private:
	Window window;

	Image* logo;
	Image* logo2;

	SDL_Texture* play;
	SDL_Texture* score;
	SDL_Texture* play_over;
	SDL_Texture* score_over;
	SDL_Texture* arrow;
	SDL_Rect rectPlay;
	SDL_Rect rectScore;
	SDL_Rect rectPlay_over;
	SDL_Rect rectScore_over;
	SDL_Rect rectArrow;

	int option;

	bool whileRunning();
};

#endif 
