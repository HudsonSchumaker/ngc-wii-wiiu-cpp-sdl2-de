/**
* @file Sprite.cpp
* @author Hudson Schumaker
* @brief Sprite class implementation.
* @version 1.0.0
* 
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "Sprite.h"
#include "Context.h"

Sprite::Sprite(const uint8_t* data, const size_t size) {
    loadTexture(data, size);
}

Sprite::~Sprite() {
    SDL_DestroyTexture(texture);
    texture = nullptr;
}

void Sprite::render() {
    SDL_Point center{bounds.w / 2, bounds.h / 2};
    SDL_RenderCopyEx(
        Context::getInstance()->getRenderer(),
        texture,
        NULL,
        &bounds, 
        angle,
        &center,
        SDL_FLIP_NONE
    );
}

SDL_Texture* Sprite::getTexture() const { 
    return texture;
}

void Sprite::loadTexture(const uint8_t* data, const size_t size) {
    SDL_RWops* rw = SDL_RWFromMem((void*)data, size);
    SDL_Renderer* renderer = Context::getInstance()->getRenderer();
    texture = IMG_LoadTexture_RW(renderer, rw, 1);
    updateBounds();
}

void Sprite::updateBounds() {
    SDL_QueryTexture(texture, NULL, NULL, &bounds.w, &bounds.h);
    bounds.x = x;
    bounds.y = y;
}

SDL_Rect Sprite::getBounds() {
    updateBounds();
    return bounds;
}

void Sprite::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
    updateBounds();
}

void Sprite::setX(int x) {
    this->x = x;
    updateBounds();
}

void Sprite::setY(int y) {
    this->y = y;
    updateBounds();
}

int Sprite::getX() const {
    return x;
}

int Sprite::getY() const {
    return y;
}

void Sprite::setAngle(float angle) {
    this->angle = angle;
}

float Sprite::getAngle() const {
    return angle;
}
