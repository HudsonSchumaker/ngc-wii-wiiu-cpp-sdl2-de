/**
* @file TitleScreen.cpp
* @author Hudson Schumaker
* @brief Implements the TitleScreen class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "../gfx/Gfx.h"
#include "TitleScreen.h"
#include "../core/Context.h"

#include "ans_png.h"
#include "title-screen1_png.h"
#include "title-screen2_png.h"

TitleScreen::TitleScreen() : Scene() {}

TitleScreen::~TitleScreen() {
	unload();
}

void TitleScreen::load() {
	nextScene = "MenuScreen";
	background1 = Gfx::loadTexture(title_screen1_png, title_screen1_png_size);
	background2 = Gfx::loadTexture(title_screen2_png, title_screen2_png_size);
	rect = Gfx::getTextureFSize(background1);

	buttonA = Gfx::loadTexture(ans_png, ans_png_size);
	rectButton = Gfx::getTextureFSize(buttonA);

	isRunning = true;
}

short TitleScreen::run() {
	while (isRunning) {
		input();
		update();
		render();
	}
	return exit;
}

void TitleScreen::input() {
    PAD_ScanPads();
    u16 buttonsDown = PAD_ButtonsDown(0);
    if (buttonsDown & PAD_BUTTON_A) {
        isRunning = false;
        exit = NEXT;
    }
}

void TitleScreen::update() {
	static float elapsed = 0.0f;
	elapsed += calculateDeltaTime();

	if (elapsed > 0.49f) {
		std::swap(background1, background2);
		elapsed = 0.0f;
	}
}

void TitleScreen::render() {
	beginRender();
	{
		SDL_RenderCopyF(renderer, background1, NULL, &rect);
		rectButton = {
			500.0f,
			400.0f + speed * SDL_sinf(SDL_GetTicks() * (Def::PI / 1500.0f)),
			rectButton.w,
			rectButton.h
		};
		SDL_RenderCopyF(renderer, buttonA, NULL, &rectButton);
	}
	endRender();
}

void TitleScreen::unload() {
	isLoaded = false;

	SDL_DestroyTexture(buttonA);
	SDL_DestroyTexture(background1);
	SDL_DestroyTexture(background2);

	buttonA = nullptr;
	background1 = nullptr;
	background2 = nullptr;
}
