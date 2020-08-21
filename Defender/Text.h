#pragma once

#ifndef TEXT_H
#define TEXT_H

#include <SDL_ttf.h>
#include "Graphics.h"

class Text : public Graphics {
private:
	TTF_Font* font;
	SDL_Color color;
public:
	Text(const char*, const char*, int, SDL_Color);
	Text(const char*, const char*, int, SDL_Color, int, int);
	void setText(const char*);
};

#endif