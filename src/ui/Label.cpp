/**
* @file Label.cpp
* @author Hudson Schumaker
* @brief Defines the Label class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "Label.h"
#include "../gfx/Gfx.h"
#include "../core/Context.h"

Label::Label(int x, int y) : Widget(x, y, 0, 0) {}

Label::~Label() {
    SDL_DestroyTexture(texture);
    texture = nullptr;
}

void Label::rebuildTexture() {
    SDL_DestroyTexture(texture);
    texture = nullptr;

    width = 0;
    height = 0;

    if (fontData == nullptr || fontDataSize == 0 || text.empty()) {
        return;
    }

    texture = Gfx::createText(fontData, fontDataSize, text, fontSize, color);
    if (texture == nullptr) {
        return;
    }

    SDL_Rect size = Gfx::getTextureSize(texture);
    width = size.w;
    height = size.h;
}

void Label::setText(const std::string& text) {
    this->text = text;
    rebuildTexture();
}

void Label::setColor(const Color& color) {
    this->color = color;
    rebuildTexture();
}

void Label::setFont(const uint8_t* fontData, size_t fontDataSize, short fontSize) {
    this->fontData = fontData;
    this->fontDataSize = fontDataSize;
    this->fontSize = fontSize;
    rebuildTexture();
}

const std::string& Label::getText() const {
    return text;
}

void Label::render() {
    if (!visible || texture == nullptr) {
        return;
    }

    SDL_Rect bounds = getBounds();
    SDL_RenderCopy(Context::getInstance().getRenderer(), texture, nullptr, &bounds);
}
