/**
* @file TitleScreen.h
* @author Hudson Schumaker
* @brief Defines the TitleScreen class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../core/Scene.h"

class TitleScreen final : public Scene {
private:
	SDL_Texture* background1 = nullptr;
	SDL_Texture* background2 = nullptr;
	SDL_FRect rect = { 0.0f, 0.0f, 0.0f, 0.0f };

	short speed = 8;
	SDL_Texture* buttonA = nullptr;
	SDL_FRect rectButton = { 0.0f, 0.0f, 0.0f, 0.0f };

	void load() override;
	void input() override;
	void update() override;
	void render() override;
	void unload() override;

public:
	TitleScreen();
	~TitleScreen();
	short run() override;
};
