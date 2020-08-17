#include <iostream>
#include "Mouse.h"

static int x;
static int y;
static int motionX;
static int motionY;

Mouse::Mouse() {}

void Mouse::setXY(int _x, int _y) {
	x = _x;
	y = _y;
}

void Mouse::controlMotion(int _x, int _y) {
	motionX = _x;
	motionY = _y;
}

bool Mouse::isPressed(SDL_Rect rect) {
	if (x >= rect.x && x <= rect.x + rect.w && y >= rect.y && y <= rect.y + rect.h) 	{
		setXY(0, 0);
		return true;
	}

	return false;
}

bool Mouse::mouseMotion(SDL_Rect rect) {
	if (motionX >= rect.x && motionX <= rect.x + rect.w && motionY >= rect.y && motionY <= rect.y + rect.h) 	{
		controlMotion(0, 0);
		return true;
	}

	return false;
}