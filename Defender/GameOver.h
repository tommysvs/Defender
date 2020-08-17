#pragma once

#ifndef GAME_OVER_H
#define GAME_OVER_H

#include <string>
#include "Scene.h"
#include "SceneManager.h"
#include "Window.h"
#include "Mouse.h"

class GameOver : public Scene {
public:
	GameOver();

	virtual void draw();
	virtual void update();
private:
	Text* score_display;
	Text* game_over;
	Text* press_enter;
};

#endif