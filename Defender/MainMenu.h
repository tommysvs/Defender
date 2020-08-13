#pragma once

#include "Scene.h"
#include "SceneManager.h"
#include "Window.h"
#include "Mouse.h"

class MainMenu : public Scene {
public:
	MainMenu();

	virtual void draw();
	virtual void update();
private:
	Window window;
	Image* logo;
	Text* option1;
	Text* option2;
};