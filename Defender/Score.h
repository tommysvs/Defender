#pragma once

#ifndef SCORE_H
#define SCORE_H

#include "Scene.h"
#include "SceneManager.h"
#include "Global.h"
#include "Window.h"

class Score : public Scene, public Global {
public:
	Score();

	virtual void draw();
	virtual void update();
private:
	Window window;

	SDL_Texture* logo;
	SDL_Rect rectLogo;

	Text* high_scores;
	Text* press_enter;

	Text* arScore;
};

#endif 