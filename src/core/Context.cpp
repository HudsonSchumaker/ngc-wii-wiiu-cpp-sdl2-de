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

Context& Context::getInstance() {
    static Context instance;
    return instance;
}

Context::~Context() {
    shutdown();
}

int Context::start() {
    if (started) {
        return 0;
    }

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_JOYSTICK) < 0) {
        return 1;
    }
    sdlInitialized = true;

    window = SDL_CreateWindow(
        "dodoi-engine",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        Def::SCREEN_WIDTH,
        Def::SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN
    );

    if (window == nullptr) {
        shutdown();
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        shutdown();
        return 1;
    }

    if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) {
        shutdown();
        return 1;
    }
    imageInitialized = true;

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        shutdown();
        return 1;
    }
    mixerInitialized = true;

    if (TTF_Init() == -1) {
        shutdown();
        return 1;
    }
    ttfInitialized = true;

    started = true;
    return 0;
}

SDL_Window* Context::getWindow() {
	return window;
}

SDL_Renderer* Context::getRenderer() {
	return renderer;
}

void Context::shutdown() {
    if (renderer != nullptr) {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }

    if (window != nullptr) {
        SDL_DestroyWindow(window);
        window = nullptr;
    }

    if (mixerInitialized) {
        Mix_HaltChannel(-1);
        Mix_CloseAudio();
        Mix_Quit();
        mixerInitialized = false;
    }

    if (imageInitialized) {
        IMG_Quit();
        imageInitialized = false;
    }

    if (ttfInitialized) {
        TTF_Quit();
        ttfInitialized = false;
    }

    if (sdlInitialized) {
        SDL_Quit();
        sdlInitialized = false;
    }

    started = false;
}
