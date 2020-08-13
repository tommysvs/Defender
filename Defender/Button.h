#pragma once

#include "Image.h"
#include "Mouse.h"

class Button : public Image {
public:
	Button(const char*);
	Button(const char*, int, int);

	Mouse mouse;
	bool pressed();
};