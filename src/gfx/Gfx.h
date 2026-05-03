/**
* @file Gfx.h
* @author Hudson Schumaker
* @brief Defines the Gfx class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../Pch.h"
#include "Color.h"

class Gfx final {
private:
    static void drawBox(const float x, const float y, const float w, const float h, const int r, const int g, const int b, const int a);
    static void drawFillBox(const float x, const float y, const float w, const float h, const int r, const int g, const int b, const int a);

public:
    Gfx() = default;
    ~Gfx() = default;

    static SDL_Rect getTextureBounds(SDL_Texture& texture);
    static SDL_FRect getTextureFBounds(SDL_Texture& texture);
    
    static void drawLine(const int x0, const int y0, const int x1, const int y1, const Color& color);
    static void drawCircle(const int centerX, const int centerY, const int radius, const Color& color);
    static void drawFillCircle(const int centerX, const int centerY, const int radius, const Color& color);
    static void drawDashedCircle(const int centerX, const int centerY, const int radius, const int dashLength, const Color& color);

    static void drawBox(const SDL_Rect& rect, const Color& color);
    static void drawBox(const SDL_FRect& rect, const Color& color);
    static void drawFillBox(const SDL_Rect& rect, const Color& color);
    static void drawFillBox(const SDL_FRect& rect, const Color& color);
};
