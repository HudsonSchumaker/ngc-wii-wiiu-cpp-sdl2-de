/**
* @file Sprite.h
* @author Hudson Schumaker
* @brief Defines Sprite class.
* @version 1.0.0
* 
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "Pch.h"

class Sprite final {
private:
    int x = 0;
    int y = 0;
    float angle = 0.0f;
    SDL_Rect bounds;
    SDL_Texture* texture = nullptr;

    void loadTexture(const uint8_t* data, const size_t size);
    void updateBounds();

public:
    Sprite(const uint8_t* data, const size_t size);
    ~Sprite();

    void render();
    SDL_Texture* getTexture() const;
    SDL_Rect getBounds();
    void setPosition(int x, int y);
    void setX(int x);
    void setY(int y);
    int getX() const;
    int getY() const;
    void setAngle(float angle);
    float getAngle() const;
};
