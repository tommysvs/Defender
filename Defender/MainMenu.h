#pragma once

#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "Global.h"
#include "Scene.h"
#include "SceneManager.h"
#include "Window.h"
#include "Keyboard.h"

class MainMenu : public Scene, public Global {
public:
	MainMenu();

	virtual void draw();
	virtual void update();
private:
	Window window;
	SDL_Event event;

	SDL_Texture* logo;
	SDL_Rect rectLogo;

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
	SDL_Rect dstrect;
	SDL_Rect srcrect;

	int option;

	bool whileRunning();
};

#endif 
