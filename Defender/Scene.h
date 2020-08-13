#pragma once

#include<SDL.h>;
#include<SDL_ttf.h>
#include<SDL_image.h>
#include "Image.h"
#include "Button.h"
#include "Text.h"

//Enum para controlar de manera mas facil las escenas
enum Scenes {
	MAINMENU
};

class Scene {
public:
	Scene();
	~Scene() {};

	virtual void draw();
	virtual void update();
};