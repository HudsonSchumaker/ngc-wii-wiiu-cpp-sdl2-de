/**
* @file Context.h
* @author Hudson Schumaker
* @brief Defines the Context class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
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
