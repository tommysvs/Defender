#include "Score.h"

SDL_Color white = { 255, 255, 255, 255 };
SDL_Color green = { 0, 255, 78, 255 };

int scores[5];

Score::Score() {
	logo = IMG_LoadTexture(window.getRender(), "Images/logo.jpg");
	rectLogo.x = 238; rectLogo.y = 110;
	
	high_scores = new Text("Hall of Fame", "Fonts/defender.ttf", 18, green, 328, 230);
	press_enter = new Text("Press   ESC   to   exit", "Fonts/defender.ttf", 14, white, 305, 650);
}

void Score::draw() {
	Global global;

	SDL_QueryTexture(logo, NULL, NULL, &rectLogo.w, &rectLogo.h);
	SDL_RenderCopy(window.getRender(), logo, NULL, &rectLogo);

	high_scores->render();
	press_enter->render();

	global.readScores();

	int y = 310;
	const char* outScore[5];
	string strS;
	for (int i = 0; i <= 4; i++) {
		strS = to_string(i + 1) + ". " + to_string(scores[i]);
		outScore[i] = strS.c_str();
		arScore = new Text(outScore[i], "Fonts/defender.ttf", 18, white, 380, y);
		arScore->render();
		y += 50;
	}
}

void Score::update() {
	SceneManager manager;
	Keyboard keyboard;

	if (keyboard.isPressed(ESC))
		manager.setScene(MAINMENU);
}