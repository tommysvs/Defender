#pragma once

#ifndef LEVEL2_H
#define LEVEL2_H

#include <string>
#include "Scene.h"
#include "SceneManager.h"
#include "Window.h"
#include "Mouse.h"

using namespace std;

class Level2 : public Scene {
public:
	Level2();

	virtual void draw();
	virtual void update();

private:
	Window window;

	Image* level2_top;
	Image* ground;
	Text* score_display;
	SDL_Texture* life;
	SDL_Texture* life2;
	SDL_Texture* life3;
	SDL_Rect rectLife;
	SDL_Rect rectLife2;
	SDL_Rect rectLife3;

	//enemies
	SDL_Texture* lander;
	SDL_Rect rectLander;

	void updateScore();
	void updateLives();
};

#endif #pragma once
