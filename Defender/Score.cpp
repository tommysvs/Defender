#include "Score.h"

Score::Score() {
	SDL_Color color = { 252, 216, 0, 255 };
	high_scores = new Text("High scores", "Fonts/defender.ttf", 18, color, 360, 50);
}

void Score::draw() {
	high_scores->render();
}

void Score::update() {
	SceneManager manager;
	Mouse mouse;
	Keyboard keyboard;

	if (keyboard.isPressed(ESC))
		manager.setScene(MAINMENU);
}