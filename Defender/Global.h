#pragma once

#ifndef GLOBAL_H
#define GLOBAL_H

#include <string>
#include <SDL_image.h>

using namespace std;

//Lander = 150
//Mutant = 200
//Baiter = 250

enum class GAMESTATE {
	INTROLEVEL, RUNNING, PAUSED, LOSE, WIN, ONMENU
};

//screen size
const int SCREEN_WIDTH = 876;
const int SCREEN_HEIGHT = 720;

//control when the ships attacks or when it is attacked
extern int score;
extern int lives;
extern bool right;
extern int scores[5];

//control enemy stuff
extern int lander_life;

//fps
extern int FPS;
extern int frameDelay;
extern Uint32 frameStart;
extern int frameTime;

class Global {
public:
	static void saveScores(int);
	static void readScores();

	static void fps();
};

#endif