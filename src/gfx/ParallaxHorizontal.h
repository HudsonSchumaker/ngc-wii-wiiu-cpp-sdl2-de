/**
* @file ParallaxHorizontal.h
* @author Hudson Schumaker
* @brief Defines the ParallaxHorizontal class.
* @version 1.0.0
*
* Dodoi Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../Pch.h"

class ParallaxHorizontal final {
private:
	SDL_Texture* background = nullptr;
	SDL_Texture* texture = nullptr;
	SDL_Rect bgRect = { 0, 0, 0, 0 };
	SDL_Rect rectA = { 0, 0, 0, 0 };
	SDL_Rect rectB = { 0, 0, 0, 0 };
	SDL_Point size = { 0, 0 };

public:
	/**
	 * @brief Construct a new ParallaxHorizontal object.
     * 
	 * @param parallaxData The data of the parallax image.
	 * @param parallaxSize The size of the parallax image data.
	 */
	ParallaxHorizontal(const uint8_t* parallaxData, const size_t parallaxSize);

	/**
	 * @brief Construct a new ParallaxHorizontal object.
     * 
	 * @param bgData The data of the background image.
	 * @param bgSize The size of the background image data.
	 * @param parallaxData The data of the parallax image.
	 * @param parallaxSize The size of the parallax image data.
	 */
	ParallaxHorizontal(const uint8_t* bgData, const size_t bgSize, const uint8_t* parallaxData, const size_t parallaxSize);
	~ParallaxHorizontal();

	void update();
	void render();
};
