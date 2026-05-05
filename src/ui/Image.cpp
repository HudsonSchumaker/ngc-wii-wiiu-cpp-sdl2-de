/**
* @file Image.cpp
* @author Hudson Schumaker
* @brief Defines the Image class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "Image.h"
#include "../gfx/Gfx.h"
#include "../core/Context.h"

Image::Image(int x, int y) : Widget(x, y, 0, 0) {}

Image::~Image() {
    SDL_DestroyTexture(texture);
    texture = nullptr;
}

void Image::setSource(const uint8_t* data, size_t size) {
    SDL_DestroyTexture(texture);
    texture = nullptr;

    width = 0;
    height = 0;

    if (data == nullptr || size == 0) {
        return;
    }

    texture = Gfx::loadTexture(data, size);
    if (texture == nullptr) {
        return;
    }

    SDL_Rect sizeRect = Gfx::getTextureSize(texture);
    width = sizeRect.w;
    height = sizeRect.h;
}

void Image::setTint(const Color& color) {
    tint = color;
}

void Image::render() {
    if (!visible || texture == nullptr) {
        return;
    }

    SDL_SetTextureColorMod(texture, static_cast<Uint8>(tint.r), static_cast<Uint8>(tint.g), static_cast<Uint8>(tint.b));
    SDL_SetTextureAlphaMod(texture, static_cast<Uint8>(tint.a));

    SDL_Rect bounds = getBounds();
    SDL_RenderCopy(Context::getInstance().getRenderer(), texture, nullptr, &bounds);
}
