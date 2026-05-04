/**
* @file Camera.h
* @author Hudson Schumaker
* @brief Defines the Camera class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../Pch.h"
#include "../gfx/Color.h"

class Camera final {
public:
	int	x, y, w, h;
	Color color = Color::Black;

	Camera() : Camera(0, 0, 640, 480) {}
	Camera(int x, int y, int w, int h) {
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
	}

	~Camera() = default;
};
