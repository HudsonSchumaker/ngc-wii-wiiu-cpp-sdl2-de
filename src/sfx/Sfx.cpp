/**
* @file Sfx.cpp
* @author Hudson Schumaker
* @brief Defines the Sfx class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "Sfx.h"

Mix_Chunk* Sfx::loadSound(const uint8_t* data, const size_t size) {
    SDL_RWops* rw = SDL_RWFromMem((void*)data, size);
    Mix_Chunk* chunk = Mix_LoadWAV_RW(rw, 1);
    return chunk;
}

Mix_Music* Sfx::loadMusic(const uint8_t* data, const size_t size) {
    SDL_RWops* rw = SDL_RWFromMem((void*)data, size);
    Mix_Music* music = Mix_LoadMUS_RW(rw, 1);
    return music;
}

int Sfx::playSound(Mix_Chunk* sound) {
    return Mix_PlayChannel(-1, sound, 0);
}

int Sfx::playMusic(Mix_Music* music, int loops) {
    return Mix_PlayMusic(music, loops);
}

void Sfx::pauseMusic() {
	Mix_PauseMusic();
}

void Sfx::unPauseMusic() {
	Mix_ResumeMusic();
}
