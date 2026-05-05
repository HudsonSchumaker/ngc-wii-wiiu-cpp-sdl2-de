/**
* @file Label.h
* @author Hudson Schumaker
* @brief Defines the Label class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "Widget.h"
#include "../gfx/Color.h"

class Label final : public Widget {
private:
    std::string text;
    const uint8_t* fontData = nullptr;
    size_t fontDataSize = 0;
    short fontSize = 16;
    Color color = Color::White;
    SDL_Texture* texture = nullptr;

    void rebuildTexture();

public:
    Label() = default;
    Label(int x, int y);
    ~Label() override;

    void setText(const std::string& text);
    void setColor(const Color& color);
    void setFont(const uint8_t* fontData, size_t fontDataSize, short fontSize);

    const std::string& getText() const;
    void render() override;
};
