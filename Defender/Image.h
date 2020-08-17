#pragma once

#ifndef IMAGE_H
#define IMAGE_H

#include<SDL.h>
#include <SDL_image.h>
#include "Graphics.h"

class Image : public Graphics {
public:
	Image(const char*);
	Image(const char*, int, int);
};

#endif