#pragma once
#include "../Pch.h"

class Context final {
private:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    bool sdlInitialized = false;
    bool imageInitialized = false;
    bool mixerInitialized = false;
    bool ttfInitialized = false;
    bool started = false;

    Context();
    void shutdown();

public:
    ~Context();

	int start();
    static Context& getInstance();
    SDL_Window* getWindow();
    SDL_Renderer* getRenderer();
};
