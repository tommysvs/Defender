#include "SceneManager.h"
#include <iostream>

static Scenes actualScene;
static Scene* scenes[1];

SceneManager::SceneManager() {}

void SceneManager::setScene(Scenes nuevaEscena) {
	actualScene = nuevaEscena;
}

void SceneManager::draw() {
	scenes[actualScene]->draw();
}

void SceneManager::update() {
	scenes[actualScene]->update();
}

void SceneManager::initScenes() {
	scenes[MAINMENU] = new MainMenu();

	actualScene = MAINMENU;
}