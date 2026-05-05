/**
* @file Button.cpp
* @author Hudson Schumaker
* @brief Defines the Button class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "Button.h"
#include "../gfx/Gfx.h"
#include "../core/Context.h"

Button::Button(int x, int y) : Widget(x, y, 0, 0) {}

Button::~Button() {
    SDL_DestroyTexture(texture);
    texture = nullptr;
}

void Button::setButtonType(u16 btn) {
    this->padButton = btn;
}

void Button::setSource(const uint8_t* data, size_t size) {
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

void Button::setOnClick(std::function<void()> callback) {
    onClick = std::move(callback);
}

void Button::render() {
    if (!visible || texture == nullptr) {
        return;
    }

    SDL_Rect bounds = getBounds();
    SDL_RenderCopy(Context::getInstance().getRenderer(), texture, nullptr, &bounds);
}

void Button::update() {
    PAD_ScanPads();
    u16 buttonsDown = PAD_ButtonsDown(0);
    
    if (onClick && visible && padButton != 0) {
        if (buttonsDown & padButton) {
            onClick();
        }
    }
}
