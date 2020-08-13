#include "Graphics.h"

Graphics::Graphics() {
	rect = { 0,0,0,0 };
}

void Graphics::setTexture(SDL_Texture* t) {
	texture = t;
}

void Graphics::setRect(SDL_Rect rec) {
	rect = rec;
}

void Graphics::render() {
	SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
	SDL_RenderCopy(window.getRender(), texture, NULL, &rect);
}

void Graphics::setPosition(int x, int y) {
	rect.x = x;
	rect.y = y;
}

SDL_Rect Graphics::getRect() {
	return rect;
}