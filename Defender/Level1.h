#pragma once

#ifndef LEVEL1_H
#define LEVEL1_H

#include <string>
#include <time.h>
#include "Global.h"
#include "Scene.h"
#include "SceneManager.h"
#include "Window.h"

using namespace std;

class Level1 : public Scene, public Global {
public:
	Level1();

	virtual void draw();
	virtual void update();

	void updateScore();
	void updateLives();
	void gameLogic();
	void enemyLogic();
private:
	Window window;

	Image* level1_top;
	Text* level1_text;

	Text* score_display;
	SDL_Texture* life;
	SDL_Texture* life2;
	SDL_Texture* life3;
	SDL_Rect rectLife;
	SDL_Rect rectLife2;
	SDL_Rect rectLife3;

	SDL_Texture* ground;
	SDL_Texture* stars;
	SDL_Rect rectGround;
	SDL_Rect rectStars;

	SDL_Texture* ship_right;
	SDL_Texture* ship_left;
	SDL_Rect rectShip;
	SDL_Texture* shoot;
	SDL_Rect rectShoot;

	SDL_Texture* lander;
	SDL_Rect rectLander;
};

#endif 