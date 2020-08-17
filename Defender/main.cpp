#include <iostream>
#include <SDL.h>;
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "SceneManager.h"
#include "Window.h"

int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	
	Mouse mouse;
	Window window;
	window.mainMenu();
	SceneManager manager;
	manager.initScenes();
	SDL_Event event;
	Keyboard keyboard;

	while (window.isRunning()) {
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_QUIT:
					window.close();
					break;
				case SDL_MOUSEBUTTONDOWN:
					mouse.setXY(event.button.x, event.button.y);
					break;
				case SDL_MOUSEMOTION:
					mouse.controlMotion(event.button.x, event.button.y);
					break;
				case SDL_KEYDOWN:
				case SDL_KEYUP:
					keyboard.controlEvent(event);
					break;
			}
		}

		SDL_RenderClear(window.getRender());
		manager.draw();
		manager.update();
		SDL_RenderPresent(window.getRender());
	}

	SDL_QUIT;

	return 0;
}