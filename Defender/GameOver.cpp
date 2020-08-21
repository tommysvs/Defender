#include "Global.h"
#include "GameOver.h"

GAMESTATE game_state;

SDL_Color yellow = { 252, 216, 0, 255 };
SDL_Color lightblue4 = { 0, 240, 255, 255 };

GameOver::GameOver() {
	TTF_Init();

	string score_str = "Final score: " + to_string(score);
	score_display = new Text(score_str.c_str(), "Fonts/defender.ttf", 14, lightblue4, 345, 50);

	game_over = new Text("", "Fonts/defender.ttf", 20, yellow, 343, 355);

	press_enter = new Text("Press   ENTER   to   continue", "Fonts/defender.ttf", 14, lightblue4, 262, 650);
}

void GameOver::draw() {
	game_over->render();
	score_display->render();
	press_enter->render();
}

void GameOver::update() {
	SceneManager manager;
	Keyboard keyboard;

	if (game_state == WIN)
		game_over->setText("NICE WORK");
	else if (game_state == LOSE)
		game_over->setText("GAME OVER");

	if (keyboard.isPressed(ENTER)) {
		manager.setScene(MAINMENU);
		keyboard.stopKey(ENTER);
	}
}