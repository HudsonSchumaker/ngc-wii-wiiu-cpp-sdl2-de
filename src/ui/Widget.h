/**
* @file Widget.h
* @author Hudson Schumaker
* @brief Defines the Widget class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../Pch.h"

class Widget {
protected:
    int x = 0;
    int y = 0;
    int width = 0;
    int height = 0;

    bool visible = true;
    bool enabled = true;
    bool focused = false;

public:
    Widget() = default;
    Widget(int x, int y, int width, int height);
    virtual ~Widget() = default;

    virtual void update() = 0;
    virtual void render() = 0;

    void setPosition(int x, int y);
    void setSize(int width, int height);

    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;

    SDL_Rect getBounds() const;
    bool contains(int px, int py) const;

    void setVisible(bool visible);
    bool isVisible() const;

    void setEnabled(bool enabled);
    bool isEnabled() const;

    void setFocused(bool focused);
    bool isFocused() const;
};
