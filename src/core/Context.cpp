/**
* @file Context.cpp
* @author Hudson Schumaker
* @brief Context class implementation.
* @version 1.0.0
* 
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "Context.h"

Context::Context() {}

Context* Context::getInstance() {
	if (instance == nullptr) {
		instance = new Context();
	}
	return instance;
}

Context::~Context() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	Mix_HaltChannel(-1);
	Mix_CloseAudio();
	Mix_Quit();
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}

int Context::start() {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_JOYSTICK) < 0) {
		return 1;
	}
	
	window = SDL_CreateWindow(
        "dodoi-engine",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED, 
        Def::SCREEN_WIDTH,
        Def::SCREEN_HEIGHT, 
        SDL_WINDOW_SHOWN
    );

    if (window == nullptr) {
        SDL_Quit();
        return 1;
    }

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) { 
        SDL_DestroyWindow(window);
		SDL_Quit();
        return 1;
    }

    if (!IMG_Init(IMG_INIT_PNG)) {
		SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
		Mix_Quit();
        SDL_Quit();
        return 1;
    }

	if (TTF_Init() == -1) {
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		Mix_Quit();
		SDL_Quit();
        return 1;
    }
    
	return 0;
}

SDL_Window* Context::getWindow() {
	return window;
}

SDL_Renderer* Context::getRenderer() {
	return renderer;
}
