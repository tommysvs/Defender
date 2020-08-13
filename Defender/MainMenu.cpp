#include <iostream>
#include <SDL.h>;
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "MainMenu.h"

MainMenu::MainMenu() {
	IMG_INIT_JPG;
	TTF_Init();

	logo = new Image("Images/logo.jpg", 238, 100);

	SDL_Color color = { 252, 216, 0, 255 };
	option1 = new Text("New game", "Fonts/defender.ttf", 18, color, 360, 400);
	option2 = new Text("Scores", "Fonts/defender.ttf", 18, color, 374, 500);
}


void MainMenu::draw() {
	logo->render();
	option1->render();
	option2->render();
}

void MainMenu::update() {
	SceneManager manager;
}