/**
* @file ParallaxVertical.h
* @author Hudson Schumaker
* @brief Defines the ParallaxVertical class.
* @version 1.0.0
*
* Dodoi Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../Pch.h"

class ParallaxVertical final {
private:
	SDL_Texture* background = nullptr;
	SDL_Texture* texture = nullptr;
	SDL_Rect bgRect = { 0, 0, 0, 0 };
	SDL_Rect rectA = { 0, 0, 0, 0 };
	SDL_Rect rectB = { 0, 0, 0, 0 };
	SDL_Point size = { 0, 0 };

public:
	/**
	 * @brief Construct a new ParallaxVertical object.
     * 
	 * @param parallaxData The parallax image data.
	 * @param parallaxSize The size of the parallax image data.
	 */
	ParallaxVertical(const uint8_t* parallaxData, const size_t parallaxSize);

	/**
	 * @brief Construct a new ParallaxVertical object.
     * 
	 * @param bgData The background image data.
	 * @param bgSize The size of the background image data.
	 * @param parallaxData The parallax image data.
	 * @param parallaxSize The size of the parallax image data.
	 */
	ParallaxVertical(const uint8_t* bgData, const size_t bgSize, const uint8_t* parallaxData, const size_t parallaxSize);
	~ParallaxVertical();

	void update();
	void render();
};
