/**
* @file Sfx.h
* @author Hudson Schumaker
* @brief Defines the Sfx class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../Pch.h"

class Sfx final {
public:
    Sfx() = default;
    ~Sfx() = default;

    static Mix_Chunk* loadSound(const uint8_t* data, const size_t size);
    static Mix_Music* loadMusic(const uint8_t* data, const size_t size);

    static int playSound(Mix_Chunk* sound);
    static int playMusic(Mix_Music* music, int loops = -1);

    static void pauseMusic();
    static void unPauseMusic();
};
