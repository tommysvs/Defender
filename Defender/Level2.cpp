#include "Level2.h"
#include "Global.h"

SDL_Color lightblue2 = { 0, 240, 255, 255 };

Level2::Level2() {
	TTF_Init();

	level2_top = new Image("Images/level2_top.png", 0, 0);
	ground = new Image("Images/ground.png", 0, 0);

	string score_str = to_string(score);
	score_display = new Text(score_str.c_str(), "Fonts/defender.ttf", 20, lightblue2, 220, 70);

	lives = 3;
	life = IMG_LoadTexture(window.getRender(), "Images/life.png");
	life2 = IMG_LoadTexture(window.getRender(), "Images/life.png");
	life3 = IMG_LoadTexture(window.getRender(), "Images/life.png");
	rectLife.x = 20; rectLife.y = 30;
	rectLife2.x = rectLife.x + 45; rectLife2.y = rectLife.y;
	rectLife3.x = rectLife2.x + 45; rectLife3.y = rectLife.y;

	lander = IMG_LoadTexture(window.getRender(), "Images/lander.png");
	rectLander.x = 400; rectLander.y = 300;
}


void Level2::draw() {
	level2_top->render();
	score_display->render();

	SDL_QueryTexture(life, NULL, NULL, &rectLife.w, &rectLife.h);
	SDL_RenderCopy(window.getRender(), life, NULL, &rectLife);

	SDL_QueryTexture(life2, NULL, NULL, &rectLife2.w, &rectLife2.h);
	SDL_RenderCopy(window.getRender(), life2, NULL, &rectLife2);

	SDL_QueryTexture(life3, NULL, NULL, &rectLife3.w, &rectLife3.h);
	SDL_RenderCopy(window.getRender(), life3, NULL, &rectLife3);

	SDL_QueryTexture(lander, NULL, NULL, &rectLander.w, &rectLander.h);
	SDL_RenderCopy(window.getRender(), lander, NULL, &rectLander);
}

void Level2::update() {
	SceneManager manager;
	Mouse mouse;
	Keyboard keyboard;

	if (keyboard.isPressed(SPACE))
		updateScore();

	if (mouse.isPressed(rectLander))
		updateLives();

	if (score > 2200)
		manager.setScene(LEVEL3);

	if (lives == 0)
		manager.setScene(GAMEOVER);
}

void Level2::updateScore() {
	int xPos = 0;

	score++;
	string score_str = to_string(score);

	if (score <= 9)
		xPos = 220;
	else if (score >= 10 && score <= 99)
		xPos = 198;
	else if (score >= 100 && score <= 999)
		xPos = 175;
	else if (score >= 1000 && score <= 9999)
		xPos = 151;
	else
		xPos = 128;

	score_display = new Text(score_str.c_str(), "Fonts/defender.ttf", 20, lightblue2, xPos, 70);
}

void Level2::updateLives() {
	if (lives == 3)
		SDL_DestroyTexture(life3);
	else if (lives == 2)
		SDL_DestroyTexture(life2);
	else if (lives == 1)
		SDL_DestroyTexture(life);

	lives--;
}