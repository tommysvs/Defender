#pragma once

#include "Scene.h"
#include "MainMenu.h"

class SceneManager{
public:
	SceneManager();

	void initScenes();
	void setScene(Scenes);
	void initMap();

	void draw();
	void update();
};