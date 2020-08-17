#pragma once

#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "Scene.h"
#include "MainMenu.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "Score.h"
#include "GameOver.h"

class SceneManager{
public:
	SceneManager();

	void initScenes();
	void setScene(Scenes);

	void draw();
	void update();
};

#endif