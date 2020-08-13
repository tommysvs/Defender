#include <iostream>
#include "Image.h"

Image::Image(const char* file) {
	SDL_Texture* tex = IMG_LoadTexture(window.getRender(), file);
	SDL_Rect rect;
	rect.x = rect.y = 0;
	setTexture(tex);
	setRect(rect);
}

Image::Image(const char* file, int x, int y) {
	SDL_Texture* tex = IMG_LoadTexture(window.getRender(), file);
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	setTexture(tex);
	setRect(rect);
}
