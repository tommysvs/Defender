#include "Keyboard.h"

bool keyboard[6];

Keyboard::Keyboard() { }

void Keyboard::controlEvent(SDL_Event evento)
{
	bool estado = true;
	switch (evento.type) {
		case SDL_KEYDOWN:
			estado = true;
			break;
		case SDL_KEYUP:
			estado = false;
			break;
	}

	switch (evento.key.keysym.sym) {
		case SDLK_RIGHT:
			keyboard[RIGHT] = estado;
			break;
		case SDLK_LEFT:
			keyboard[LEFT] = estado;
			break;
		case SDLK_SPACE:
			keyboard[SPACE] = estado;
			break;
		case SDLK_ESCAPE:
			keyboard[ESC] = estado;
			break;
	}

}

bool Keyboard::isPressed(KEYS key) {
	return keyboard[key];
}

void Keyboard::stopKey(KEYS key) {
	keyboard[key] = false;
}