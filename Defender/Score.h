#pragma once

#ifndef SCORE_H
#define SCORE_H

#include "Scene.h"
#include "SceneManager.h"
#include "Window.h"
#include "Mouse.h"

class Score : public Scene {
public:
	Score();

	virtual void draw();
	virtual void update();
private:
	Window window;

	Text* high_scores;
};

#endif 