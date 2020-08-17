#include "Keyboard.h"

bool keyboard[6];

Keyboard::Keyboard() { }

void Keyboard::controlEvent(SDL_Event event)
{
	bool state = true;
	switch (event.type) {
		case SDL_KEYDOWN:
			state = true;
			break;
		case SDL_KEYUP:
			state = false;
			break;
	}

	switch (event.key.keysym.sym) {
		case SDLK_LEFT:
			keyboard[LEFT] = state;
			break;
		case SDLK_RIGHT:
			keyboard[RIGHT] = state;
			break;
		case SDLK_UP:
			keyboard[UP] = state;
			break;
		case SDLK_DOWN:
			keyboard[DOWN] = state;
			break;
		case SDLK_ESCAPE:
			keyboard[ESC] = state;
			break;
		case SDLK_SPACE:
			keyboard[SPACE] = state;
			break;
		case SDLK_RETURN:
			keyboard[ENTER] = state;
			break;
	}
}

bool Keyboard::isPressed(KEYS key) {
	return keyboard[key];
}

void Keyboard::stopKey(KEYS key) {
	keyboard[key] = false;
}