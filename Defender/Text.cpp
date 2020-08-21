#include "Text.h"

Text::Text(const char* text, const char* file, int size, SDL_Color color) {
	TTF_Font* font = TTF_OpenFont(file, size);
	SDL_Surface* sf = TTF_RenderText_Solid(font, text, color);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(window.getRender(), sf);
	SDL_Rect rect;
	rect.x = rect.y = 0;
	setTexture(tex);
	setRect(rect);
}

Text::Text(const char* text, const char* file, int size, SDL_Color _color, int x, int y) {
	font = TTF_OpenFont(file, size);
	color = _color;
	TTF_Font* font = TTF_OpenFont(file, size);
	SDL_Surface* sf = TTF_RenderText_Solid(font, text, color);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(window.getRender(), sf);
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	setTexture(tex);
	setRect(rect);
}

void Text::setText(const char* text)
{
	SDL_Surface* sf = TTF_RenderText_Solid(font, text, color);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(window.getRender(), sf);
	setTexture(tex);
}