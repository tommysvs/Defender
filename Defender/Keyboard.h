#pragma once
#include <SDL.h>

enum KEYS {
	LEFT, RIGHT, UP, DOWN, ESC, SPACE
};

class Keyboard {
public:
	Keyboard();
	void controlEvent(SDL_Event);
	bool isPressed(KEYS);
	void stopKey(KEYS);
};