/**
* @file ParallaxVertical.cpp
* @author Hudson Schumaker
* @brief Implements the ParallaxVertical class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "Gfx.h"
#include "../core/Context.h"
#include "ParallaxVertical.h"

ParallaxVertical::ParallaxVertical(const uint8_t* parallaxData, const size_t parallaxSize) {
    texture = Gfx::loadTexture(parallaxData, parallaxSize);
	size = { 0, 0 };
	SDL_QueryTexture(texture, NULL, NULL, &size.x, &size.y);

	rectA = { 0, 0, size.x, size.y };
	rectB = { -size.x, 0, size.x, size.y };
}

ParallaxVertical::ParallaxVertical(const uint8_t* bgData, const size_t bgSize, const uint8_t* parallaxData, const size_t parallaxSize) {
	background = Gfx::loadTexture(bgData, bgSize);
	bgRect = Gfx::getTextureSize(background);

	texture = Gfx::loadTexture(parallaxData, parallaxSize);
	size = { 0, 0 };
	SDL_QueryTexture(texture, NULL, NULL, &size.x, &size.y);

	rectA = { 0, 0, size.x, size.y };
	rectB = { 0, -size.y, size.x, size.y };
}

ParallaxVertical::~ParallaxVertical() {
	background = nullptr;
	texture = nullptr;
	SDL_DestroyTexture(background);
	SDL_DestroyTexture(texture);
}

void ParallaxVertical::update() {
	if (rectA.y >= size.y) {
		rectA = { 0, 0, size.x, size.y };
		rectB = { 0, -size.y, size.x, size.y };
	}

	rectA.y += 1;
	rectB.y += 1;
}

void ParallaxVertical::render() {
    SDL_Renderer* renderer = Context::getInstance().getRenderer();

	if (background != nullptr) {
		SDL_RenderCopy(renderer, background, NULL, &bgRect);
	}
	SDL_RenderCopy(renderer, texture, NULL, &rectA);
	SDL_RenderCopy(renderer, texture, NULL, &rectB);
}
