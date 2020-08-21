#pragma once

#ifndef ENEMY_H
#define ENEMY_H

#include <time.h>
#include "Global.h"
#include "Scene.h"
#include "SceneManager.h"
#include "Window.h"

extern int lander_life;
extern int mutant_life;
extern int baiter_life;

class Enemy {
private:
	Window window;

	SDL_Texture* lander;
	SDL_Rect rectLander;
public:
	Enemy();

	virtual void draw();
	virtual void update();

	void enemyLogic();
};

#endif