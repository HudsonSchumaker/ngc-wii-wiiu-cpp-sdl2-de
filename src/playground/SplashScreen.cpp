/**
* @file SplashScreen.cpp
* @author Hudson Schumaker
* @brief Implements the SplashScreen class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "logo_png.h"
#include "../gfx/Gfx.h"
#include "SplashScreen.h"
#include "../core/Context.h"

SplashScreen::SplashScreen() : Scene() {}

SplashScreen::~SplashScreen() {
	unload();
}

void SplashScreen::load() {
	nextScene = "TitleScreen";
	logoTexture = Gfx::loadTexture(logo_png, logo_png_size);
	rect = Gfx::getTextureSize(logoTexture);
	rect.x = (Def::SCREEN_WIDTH - rect.w) / 2;
	rect.y = (Def::SCREEN_HEIGHT - rect.h) / 2;
	isRunning = true;
}

short SplashScreen::run() {
	while (isRunning) {
		input();
		update();
		render();
	}
	return NEXT;
}

void SplashScreen::input() {
	SDL_Event sdlEvent;
	while (SDL_PollEvent(&sdlEvent)) {
		switch (sdlEvent.type) {
		}
	}
}

void SplashScreen::update() {
	static float elapsed = 0.0f;
    
	elapsed += calculateDeltaTime();
	if (elapsed > 2.99f) {
		isRunning = false;
	}
}

void SplashScreen::render() {
	beginRender();
	{
		SDL_RenderCopy(renderer, logoTexture, NULL, &rect);
	}
	endRender();
}

void SplashScreen::unload() {
	isLoaded = false;

	SDL_DestroyTexture(logoTexture);
	logoTexture = nullptr;
}
