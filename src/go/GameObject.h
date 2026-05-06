/**
* @file GameObject.h
* @author Hudson Schumaker
* @brief Defines the GameObject class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../Pch.h"
#include "BoxCollider.h"

class GameObject {
protected:
    bool active = true;
    float x = 0.0f, y = 0.0f, w = 0.0f, h = 0.0f;
    short z = 0;

public:
    GameObject(float x, float y, float w, float h) : x(x), y(y), w(w), h(h) {}
    virtual ~GameObject() {}

    virtual void update(float dt) = 0;
    virtual void render() = 0;
    virtual BoxCollider getCollider() const = 0;

    float getX() const { return x; }
    float getY() const { return y; }
    float getWidth() const { return w; }
    float getHeight() const { return h; }
    short getZ() const { return z; }
    bool isActive() const { return active; }
    void setActive(bool isActive) { active = isActive; }
    void setZ(short newZ) { z = newZ; } 

    void setPosition(float newX, float newY) {
        x = newX;
        y = newY;
    }

    void setSize(float newWidth, float newHeight) {
        w = newWidth;
        h = newHeight;
    }

    virtual void reset(float x, float y, float w, float h) {
        setPosition(x, y);
        setSize(w, h);
        active = true;
    }
};
 