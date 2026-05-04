/**
* @file ParallaxHorizontal.cpp
* @author Hudson Schumaker
* @brief Implements the ParallaxHorizontal class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/

#include "Gfx.h"
#include "../core/Context.h"
#include "ParallaxHorizontal.h"

ParallaxHorizontal::ParallaxHorizontal(const uint8_t* parallaxData, const size_t parallaxSize) {
    texture = Gfx::loadTexture(parallaxData, parallaxSize);
	SDL_QueryTexture(texture, NULL, NULL, &size.x, &size.y);

	rectA = { 0, 0, size.x, size.y };
	rectB = { -size.x, 0, size.x, size.y };
}

ParallaxHorizontal::ParallaxHorizontal(const uint8_t* bgData, const size_t bgSize, const uint8_t* parallaxData, const size_t parallaxSize) {
	background = Gfx::loadTexture(bgData, bgSize);
	bgRect = Gfx::getTextureSize(background);

	texture = Gfx::loadTexture(parallaxData, parallaxSize);
	SDL_QueryTexture(texture, NULL, NULL, &size.x, &size.y);

	rectA = { 0, 0, size.x, size.y };
	rectB = { -size.x, 0, size.x, size.y };
}

ParallaxHorizontal::~ParallaxHorizontal() {
	background = nullptr;
	texture = nullptr;
	SDL_DestroyTexture(background);
	SDL_DestroyTexture(texture);
}

void ParallaxHorizontal::update() {
	if (rectA.x >= size.x) {
		rectA = { 0, 0, size.x, size.y };
		rectB = { -size.x, 0, size.x, size.y };
	}

	rectA.x += 1;
	rectB.x += 1;
}

void ParallaxHorizontal::render() {
    SDL_Renderer* renderer = Context::getInstance().getRenderer();
	if (background != nullptr) {
		SDL_RenderCopy(renderer, background, NULL, &bgRect);
	}
	SDL_RenderCopy(renderer, texture, NULL, &rectA);
	SDL_RenderCopy(renderer, texture, NULL, &rectB);
}
