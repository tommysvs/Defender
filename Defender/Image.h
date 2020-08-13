#pragma once

#include<SDL.h>
#include <SDL_image.h>
#include "Graphics.h"

class Image : public Graphics {
public:
	Image(const char*);
	Image(const char*, int, int);
};