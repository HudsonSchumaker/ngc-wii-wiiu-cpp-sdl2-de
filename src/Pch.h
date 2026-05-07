/**
* @file Pch.h
* @author Hudson Schumaker
* @brief Pch includes and definitions for the Dodoi-Engine.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include <set>
#include <map>
#include <list>
#include <array>
#include <cmath>
#include <limits>
#include <vector>
#include <random>
#include <chrono>
#include <future>
#include <string>
#include <thread>
#include <cstdint>
#include <variant>
#include <utility>
#include <fstream>
#include <iostream>
#include <typeindex>
#include <algorithm>
#include <filesystem>
#include <functional>
#include <unordered_map>
#include <unordered_set>

// Console-specific includes
#include <gccore.h>

// SDL2 includes
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

// Navigation Definitions
#define QUIT (-2)
#define EXIT (-1)
#define NADA 0
#define NEXT 1
#define BACK 2
#define PLAY 3
#define PAUSE 4
#define RESUME 5
#define RESTART 6
#define CONTINUE 7
#define GAME_OVER 8
#define RELOAD 9

class Def final {
public:
    static const int SCREEN_WIDTH = 640;
    static const int SCREEN_HEIGHT = 480;

    static constexpr float FPS = 60.0f;
    static constexpr float MILLISECS_PER_FRAME = 1000.0f / FPS;

    constexpr static const float PI = 3.14159265358979323846f;
    constexpr static const float TWO_PI = 2.0f * PI;
};
