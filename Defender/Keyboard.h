#pragma once
#include <SDL.h>

#ifndef KEYBOARD_H
#define KEYBOARD_H

enum KEYS {
	LEFT, RIGHT, UP, DOWN, ESC, SPACE, ENTER, F
};

class Keyboard {
public:
	Keyboard();

	void controlEvent(SDL_Event);
	bool isPressed(KEYS);
	void stopKey(KEYS);
};

#endif 