#include "SceneManager.h"

static Scenes actualScene;
static Scene* scenes[6];

SceneManager::SceneManager() {}

void SceneManager::setScene(Scenes newScene) {
	actualScene = newScene;
}

void SceneManager::draw() {
	scenes[actualScene]->draw();
}

void SceneManager::update() {
	scenes[actualScene]->update();
}

void SceneManager::initScenes() {
	scenes[MAINMENU] = new MainMenu();
	scenes[LEVEL1] = new Level1();
	scenes[LEVEL2] = new Level2();
	scenes[LEVEL3] = new Level3();
	scenes[SCORE] = new Score();
	scenes[GAMEOVER] = new GameOver();

	actualScene = MAINMENU;
}