/**
* @file Widget.cpp
* @author Hudson Schumaker
* @brief Defines the Widget class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "Widget.h"

Widget::Widget(int x, int y, int width, int height)
    : x(x), y(y), width(width), height(height) {
}

void Widget::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
}

void Widget::setSize(int width, int height) {
    this->width = width;
    this->height = height;
}

int Widget::getX() const {
    return x;
}

int Widget::getY() const {
    return y;
}

int Widget::getWidth() const {
    return width;
}

int Widget::getHeight() const {
    return height;
}

SDL_Rect Widget::getBounds() const {
    return SDL_Rect{ x, y, width, height };
}

bool Widget::contains(int px, int py) const {
    return px >= x && px < (x + width) && py >= y && py < (y + height);
}

void Widget::setVisible(bool visible) {
    this->visible = visible;
}

bool Widget::isVisible() const {
    return visible;
}

void Widget::setEnabled(bool enabled) {
    this->enabled = enabled;
}

bool Widget::isEnabled() const {
    return enabled;
}

void Widget::setFocused(bool focused) {
    this->focused = focused;
}

bool Widget::isFocused() const {
    return focused;
}
