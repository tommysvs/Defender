#pragma once

#ifndef SCENE_H
#define SCENE_H

#include <SDL.h>;
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "Image.h"
#include "Text.h"

//Enum para controlar de manera mas facil las escenas
enum Scenes {
	MAINMENU, LEVEL1, LEVEL2, LEVEL3, SCORE, GAMEOVER
};

class Scene {
public:
	Scene();
	~Scene() {};

	virtual void draw();
	virtual void update();
};

#endif