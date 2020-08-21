#include "Global.h"
#include "Background.h"
#include "Ship.h"
#include "Enemy.h"

static GAMESTATE game_state;

Background::Background() {
	ground = IMG_LoadTexture(window.getRender(), "Images/ground.png");
	stars = IMG_LoadTexture(window.getRender(), "Images/stars.png");
	rectGround.x = 0; rectGround.y = 0;
	rectStars.x = 0; rectStars.y = 0;
}

void Background::draw() {
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
}

void Background::update() {

}