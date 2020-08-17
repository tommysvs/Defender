#include "Window.h"

static SDL_Window* window;
static SDL_Renderer* renderer;
static bool running = true;

Window::Window() {}

bool Window::isRunning() {
	return running;
}

void Window::close() {
	running = false;
}

SDL_Renderer* Window::getRender() {
	return renderer;
}

void Window::mainMenu() {
	window = SDL_CreateWindow("Defender", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 876, 720, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	SDL_Surface* icon = IMG_Load("Images/favicon.png");
	SDL_SetWindowIcon(window, icon);
}