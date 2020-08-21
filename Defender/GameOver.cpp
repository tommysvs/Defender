#include "Global.h"
#include "GameOver.h"

static GAMESTATE game_state;

SDL_Color yellow = { 252, 216, 0, 255 };
SDL_Color lightblue4 = { 0, 240, 255, 255 };

GameOver::GameOver() {
	TTF_Init();

	string score_str = "Final score: " + to_string(score);
	score_display = new Text(score_str.c_str(), "Fonts/defender.ttf", 14, lightblue4, 345, 50);

	game_over = new Text("", "Fonts/defender.ttf", 20, yellow, 343, 355);

	press_enter = new Text("Press   ESC   to   continue", "Fonts/defender.ttf", 14, lightblue4, 263, 650);
}

void GameOver::draw() {
	if (game_state == GAMESTATE::WIN) {
		game_over->setText("NICE WORK");
		game_over->render();
	}
	else if (game_state == GAMESTATE::LOSE) {
		game_over->setText("GAME OVER");
		game_over->render();
	}

	score_display->render();
	press_enter->render();
}

void GameOver::update() {
	SceneManager manager;
	Keyboard keyboard;

	if (keyboard.isPressed(ESC)) {
		manager.setScene(MAINMENU);
		game_state = GAMESTATE::ONMENU;
		keyboard.stopKey(ESC);
	}
}