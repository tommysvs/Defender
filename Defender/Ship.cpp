#include "Global.h"
#include "Ship.h"
#include "Enemy.h"
#include "Background.h"

static GAMESTATE game_state;

Ship::Ship() {
	ship_right = IMG_LoadTexture(window.getRender(), "Images/ship_right.png");
	ship_left = IMG_LoadTexture(window.getRender(), "Images/ship_left.png");
	shoot = IMG_LoadTexture(window.getRender(), "Images/shoot.png");
	rectShip.x = 30; rectShip.y = 400;
}

void Ship::draw() {
	right = true;
	if (right) {
		SDL_QueryTexture(ship_right, NULL, NULL, &rectShip.w, &rectShip.h);
		SDL_RenderCopy(window.getRender(), ship_right, NULL, &rectShip);
	}
	else {
		SDL_QueryTexture(ship_left, NULL, NULL, &rectShip.w, &rectShip.h);
		SDL_RenderCopy(window.getRender(), ship_left, NULL, &rectShip);
	}
}

void Ship::update() {
	shipLogic();
}

void Ship::shipLogic() {
	Keyboard keyboard;

	if (keyboard.isPressed(LEFT)) {
		SDL_QueryTexture(ship_left, NULL, NULL, &rectShip.w, &rectShip.h);
		SDL_RenderCopy(window.getRender(), ship_left, NULL, &rectShip);

		rectShip.x -= 1;

		right = false;
	}

	if (keyboard.isPressed(RIGHT)) {
		SDL_QueryTexture(ship_right, NULL, NULL, &rectShip.w, &rectShip.h);
		SDL_RenderCopy(window.getRender(), ship_right, NULL, &rectShip);

		rectShip.x += 1;

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
			rectShoot.x = rectShip.x + rectShip.w + 18;

			SDL_QueryTexture(shoot, NULL, NULL, &rectShoot.w, &rectShoot.h);
			SDL_RenderCopy(window.getRender(), shoot, NULL, &rectShoot);
		}
		else {
			rectShoot.y = rectShip.y + 19;
			rectShoot.x = rectShip.x - (rectShip.w * 2) - 62;

			SDL_QueryTexture(shoot, NULL, NULL, &rectShoot.w, &rectShoot.h);
			SDL_RenderCopy(window.getRender(), shoot, NULL, &rectShoot);
		}
	}
}