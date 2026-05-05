/**
* @file Button.h
* @author Hudson Schumaker
* @brief Defines the Button class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "Widget.h"

class Button final : public Widget {
private:
    u16 padButton = 0; 
    SDL_Texture* texture = nullptr;
    std::function<void()> onClick;

public:
    Button() = default;
    Button(int x, int y);
    ~Button();

    void setButtonType(u16 btn);
    void setSource(const uint8_t* data, size_t size);
    void setOnClick(std::function<void()> callback);
    void update() override;
    void render() override;
};
