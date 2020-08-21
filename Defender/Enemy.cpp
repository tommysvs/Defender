#include "Global.h"
#include "Enemy.h"

int lander_life;

Enemy::Enemy() {
	srand(time(0));

	lander_life = 8;
	lander = IMG_LoadTexture(window.getRender(), "Images/lander.png");
	rectLander.x = 300; rectLander.y = 300;
}

void Enemy::draw() {
	SDL_QueryTexture(lander, NULL, NULL, &rectLander.w, &rectLander.h);
	SDL_RenderCopy(window.getRender(), lander, NULL, &rectLander);
}

void Enemy::update() {
	enemyLogic();
}

void Enemy::enemyLogic() {
	Keyboard keyboard;

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