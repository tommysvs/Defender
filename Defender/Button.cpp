#include "Button.h"

Button::Button(const char* file) : Image(file) {}

Button::Button(const char* file, int x, int y) : Image(file, x, y) {}

bool Button::pressed() {
	return mouse.isPressed(this->getRect());
}