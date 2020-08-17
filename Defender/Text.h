#pragma once

#ifndef TEXT_H
#define TEXT_H

#include <SDL_ttf.h>
#include "Graphics.h"

class Text : public Graphics {
public:
	Text(const char*, const char*, int, SDL_Color);
	Text(const char*, const char*, int, SDL_Color, int, int);
};

#endif