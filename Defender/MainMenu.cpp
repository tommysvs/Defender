#include <stdlib.h>
#include "Global.h"
#include "MainMenu.h"

static GAMESTATE game_state;

MainMenu::MainMenu() {
	logo = IMG_LoadTexture(window.getRender(), "Images/logo_large.jpg");
	rectLogo.x = 238; rectLogo.y = 160;

	play = IMG_LoadTexture(window.getRender(), "Images/play_text.png");
	rectPlay.x = 397; rectPlay.y = 500;
	score = IMG_LoadTexture(window.getRender(), "Images/score_text.png");
	rectScore.x = 386; rectScore.y = 600;

	play_over = IMG_LoadTexture(window.getRender(), "Images/play_text2.png");
	score_over = IMG_LoadTexture(window.getRender(), "Images/score_text2.png");
	arrow = IMG_LoadTexture(window.getRender(), "Images/arrow.png");

	option = 1;
}

void MainMenu::draw() {
	bool quit = false;
	while (!quit) {
		int  ticks = SDL_GetTicks();
		int  sprite = (ticks / 50) % 3;

		srcrect = { sprite * 400, 0, 400, rectLogo.h };
		dstrect = { rectLogo.x, rectLogo.y, 400, rectLogo.h };

		while (SDL_PollEvent(&event) != NULL)
		{
			switch (event.type) {
			case SDL_QUIT:
				quit = true;
				break;
			}
		}

		SDL_QueryTexture(logo, NULL, NULL, &rectLogo.w, &rectLogo.h);
		SDL_RenderCopy(window.getRender(), logo, &srcrect, &dstrect);

		break;
	}

	SDL_QueryTexture(play, NULL, NULL, &rectPlay.w, &rectPlay.h);
	SDL_RenderCopy(window.getRender(), play, NULL, &rectPlay);

	SDL_QueryTexture(score, NULL, NULL, &rectScore.w, &rectScore.h);
	SDL_RenderCopy(window.getRender(), score, NULL, &rectScore);

	SDL_QueryTexture(play_over, NULL, NULL, &rectPlay_over.w, &rectPlay_over.h);
	SDL_RenderCopy(window.getRender(), play_over, NULL, &rectPlay_over);

	SDL_QueryTexture(score_over, NULL, NULL, &rectScore_over.w, &rectScore_over.h);
	SDL_RenderCopy(window.getRender(), score_over, NULL, &rectScore_over);

	SDL_QueryTexture(arrow, NULL, NULL, &rectArrow.w, &rectArrow.h);
	SDL_RenderCopy(window.getRender(), arrow, NULL, &rectArrow);

	if (option == 1)
	{
		rectPlay_over.x = rectPlay.x;
		rectPlay_over.y = rectPlay.y;

		rectArrow.x = rectPlay_over.x - 30;
		rectArrow.y = rectPlay_over.y + 3;

		rectScore_over.x = -500; rectScore_over.y = -500;
	}
	else if (option == 2)
	{
		rectScore_over.x = rectScore.x;
		rectScore_over.y = rectScore.y;

		rectArrow.x = rectScore_over.x - 30;
		rectArrow.y = rectScore_over.y + 3;

		rectPlay_over.x = -500;	rectPlay_over.y = -500;
	}
}

void MainMenu::update() {
	SceneManager manager;
	Keyboard keyboard;

	if (keyboard.isPressed(ENTER) && option == 1) {
		manager.setScene(LEVEL1);
		game_state = INTROLEVEL;
	}
	else if (keyboard.isPressed(ENTER) && option == 2)
		manager.setScene(SCORE);

	if (keyboard.isPressed(UP))
	{
		if (option == 1)
			option = 2;
		else
			option -= 1;
		keyboard.stopKey(UP);
	}
	else if (keyboard.isPressed(DOWN))
	{
		if (option == 2)
			option = 1;
		else
			option += 1;
		keyboard.stopKey(DOWN);
	}
}