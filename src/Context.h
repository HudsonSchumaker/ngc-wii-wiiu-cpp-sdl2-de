#pragma once
#include "Pch.h"

class Context final {
private:
    inline static Context* instance = nullptr;
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    Context();

public:
    ~Context();

    static Context* getInstance();
	int start();
    SDL_Window* getWindow();
    SDL_Renderer* getRenderer();
};
