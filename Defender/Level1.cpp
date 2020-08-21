#include "Global.h"
#include "Level1.h"

static GAMESTATE game_state;

SDL_Color lightblue = { 0, 240, 255, 255 };

Level1::Level1() {
	TTF_Init();
	srand(time(0));

	level1_top = new Image("Images/level1_top.png", 0, 0);
	level1_text = new Text("", "Fonts/defender.ttf", 20, lightblue, 370, 350);

	string score_str = to_string(score);
	score_display = new Text(score_str.c_str(), "Fonts/defender.ttf", 20, lightblue, 220, 70);

	life = IMG_LoadTexture(window.getRender(), "Images/life.png");
	life2 = IMG_LoadTexture(window.getRender(), "Images/life.png");
	life3 = IMG_LoadTexture(window.getRender(), "Images/life.png");
	rectLife.x = 20; rectLife.y = 30;
	rectLife2.x = rectLife.x + 45; rectLife2.y = rectLife.y;
	rectLife3.x = rectLife2.x + 45; rectLife3.y = rectLife.y;

	ground = IMG_LoadTexture(window.getRender(), "Images/ground.png");
	stars = IMG_LoadTexture(window.getRender(), "Images/stars.png");
	rectGround.x = 0; rectGround.y = 0;
	rectStars.x = 0; rectStars.y = 0;

	lander_life = 8;
	lander = IMG_LoadTexture(window.getRender(), "Images/lander.png");
	rectLander.x = 300; rectLander.y = 300;

	ship_right = IMG_LoadTexture(window.getRender(), "Images/ship_right.png");
	ship_left = IMG_LoadTexture(window.getRender(), "Images/ship_left.png");
	shoot = IMG_LoadTexture(window.getRender(), "Images/shoot.png");
	rectShip.x = 30; rectShip.y = 400;

	game_state = GAMESTATE::INTROLEVEL;
}

void Level1::draw() {
	level1_top->render();
	level1_text->render();

	score_display->render();

	SDL_QueryTexture(ground, NULL, NULL, &rectGround.w, &rectGround.h);
	SDL_RenderCopy(window.getRender(), ground, NULL, &rectGround);

	if (game_state == GAMESTATE::RUNNING) {
		while (game_state == GAMESTATE::RUNNING) {
			int  ticks = SDL_GetTicks();
			int  sprite = (ticks / 500) % 3;

			SDL_Rect srcrect = { sprite * 876, 0, 876, rectStars.h };
			SDL_Rect dstrect = { rectStars.x, rectStars.y, 876, rectStars.h };

			SDL_QueryTexture(stars, NULL, NULL, &rectStars.w, &rectStars.h);
			SDL_RenderCopy(window.getRender(), stars, &srcrect, &dstrect);

			break;
		}
	}
	else if (game_state == GAMESTATE::PAUSED) {
		SDL_QueryTexture(stars, NULL, NULL, &rectStars.w, &rectStars.h);
		SDL_RenderCopy(window.getRender(), stars, NULL, &rectStars);
	}

	right = true;
	if (right) {
		SDL_QueryTexture(ship_right, NULL, NULL, &rectShip.w, &rectShip.h);
		SDL_RenderCopy(window.getRender(), ship_right, NULL, &rectShip);
	}
	else {
		SDL_QueryTexture(ship_left, NULL, NULL, &rectShip.w, &rectShip.h);
		SDL_RenderCopy(window.getRender(), ship_left, NULL, &rectShip);
	}

	SDL_QueryTexture(life, NULL, NULL, &rectLife.w, &rectLife.h);
	SDL_RenderCopy(window.getRender(), life, NULL, &rectLife);

	SDL_QueryTexture(life2, NULL, NULL, &rectLife2.w, &rectLife2.h);
	SDL_RenderCopy(window.getRender(), life2, NULL, &rectLife2);

	SDL_QueryTexture(life3, NULL, NULL, &rectLife3.w, &rectLife3.h);
	SDL_RenderCopy(window.getRender(), life3, NULL, &rectLife3);

	SDL_QueryTexture(lander, NULL, NULL, &rectLander.w, &rectLander.h);
	SDL_RenderCopy(window.getRender(), lander, NULL, &rectLander);
}

void Level1::update() {
	Keyboard keyboard;
	
	if (game_state == GAMESTATE::INTROLEVEL) {
		level1_text->setText("Level 1");
		level1_text->render();

		game_state = GAMESTATE::RUNNING;
	}
	else if (game_state == GAMESTATE::RUNNING) {
		gameLogic();
		enemyLogic();

		if (keyboard.isPressed(ESC)) {
			level1_text->setText("Paused");
			level1_text->render();

			game_state = GAMESTATE::PAUSED;
		}

		keyboard.stopKey(ESC);
	}
	else if (game_state == GAMESTATE::PAUSED) {
		if (keyboard.isPressed(ESC)) {
			game_state = GAMESTATE::RUNNING;
			gameLogic();
		}

		keyboard.stopKey(ESC);
	}
}

void Level1::gameLogic() {
	SceneManager manager;
	Keyboard keyboard;
	Global global;

	frameDelay = 80 / FPS;
	if (frameDelay > frameTime)
		SDL_Delay(frameDelay - frameTime);

	level1_text->setText("");
	level1_text->render();

	if (keyboard.isPressed(LEFT)) {
		SDL_QueryTexture(ship_left, NULL, NULL, &rectShip.w, &rectShip.h);
		SDL_RenderCopy(window.getRender(), ship_left, NULL, &rectShip);

		rectShip.x -= 1;
		rectGround.x -= -1;
		rectStars.x -= -1;

		right = false;
	}

	if (keyboard.isPressed(RIGHT)) {
		SDL_QueryTexture(ship_right, NULL, NULL, &rectShip.w, &rectShip.h);
		SDL_RenderCopy(window.getRender(), ship_right, NULL, &rectShip);

		rectShip.x += 1;
		rectGround.x += -1;
		rectStars.x += -1;

		right = true;
	}

	if (keyboard.isPressed(UP))
		rectShip.y -= 1;

	if (keyboard.isPressed(DOWN))
		rectShip.y += 1;

	if (rectShip.x < 0)
		rectShip.x = 0;
	else if (rectShip.x > SCREEN_WIDTH - rectShip.w)
		rectShip.x = SCREEN_WIDTH - rectShip.w;

	if (rectShip.y < 120)
		rectShip.y = 120;
	else if (rectShip.y > 650 - rectShip.w)
		rectShip.y = 650 - rectShip.w;

	if (keyboard.isPressed(SPACE)) {
		if (right) {
			rectShoot.y = rectShip.y + 19;
			rectShoot.x = rectShip.x + rectShip.w + 20;

			SDL_QueryTexture(shoot, NULL, NULL, &rectShoot.w, &rectShoot.h);
			SDL_RenderCopy(window.getRender(), shoot, NULL, &rectShoot);
		}
		else {
			rectShoot.y = rectShip.y + 19;
			rectShoot.x = rectShip.x - (rectShip.w * 2) - 62;

			SDL_QueryTexture(shoot, NULL, NULL, &rectShoot.w, &rectShoot.h);
			SDL_RenderCopy(window.getRender(), shoot, NULL, &rectShoot);
		}

		if ((rectShoot.x + rectShoot.w) == rectLander.x) {
			updateScore();
			lander_life--;
		}
	}

	if (keyboard.isPressed(F)) {
		updateLives();
	}

	if (score >= 1400) {
		manager.setScene(LEVEL2);
		game_state = GAMESTATE::INTROLEVEL;
	}

	if (lives == 0) {
		manager.setScene(GAMEOVER);
		global.saveScores(score);
		game_state = GAMESTATE::LOSE;
	}
}

void Level1::enemyLogic() {
	Keyboard keyboard;

	if (rectLander.x - rectLander.w != rectShip.x) {
		SDL_QueryTexture(lander, NULL, NULL, &rectLander.w, &rectLander.h);
		SDL_RenderCopy(window.getRender(), lander, NULL, &rectLander);

		rectLander.x += (rand() % 2);
		rectLander.y += (rand() % 2);

		if (rectLander.x < 0)
			rectLander.x = 0;
		else if (rectLander.x == 0) {
			rectLander.x += (rand() % 2);
			rectLander.y += (rand() % 2);
		}
		else if (rectLander.x > SCREEN_WIDTH - rectLander.w)
			rectLander.x = SCREEN_WIDTH - rectLander.w;
		else if (rectLander.x == SCREEN_WIDTH - rectLander.w) {
			rectLander.x += (rand() % 2);
			rectLander.y += (rand() % 2);
		}

		if (rectLander.y < 120)
			rectLander.y = 120;
		else if (rectLander.y == 120) {
			rectLander.x += (rand() % 2);
			rectLander.y += (rand() % 2);
		}
		else if (rectLander.y > 550 - rectLander.w)
			rectLander.y = 550 - rectLander.w;
		else if (rectLander.y == 550 - rectLander.w) {
			rectLander.x += (rand() % 2);
			rectLander.y += (rand() % 2);
		}
	}
}

void Level1::updateScore() {
	int xPos = 0;

	score = score + 150;
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

	score_display = new Text(score_str.c_str(), "Fonts/defender.ttf", 20, lightblue, xPos, 70);
}

void Level1::updateLives() {
	if (lives == 3)
		SDL_DestroyTexture(life3);
	else if (lives == 2)
		SDL_DestroyTexture(life2);
	else if (lives == 1)
		SDL_DestroyTexture(life);

	lives--;
}