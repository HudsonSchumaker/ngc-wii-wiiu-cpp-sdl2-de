/**
* @file BoxCollider.cpp
* @author Hudson Schumaker
* @brief Implements the BoxCollider class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "BoxCollider.h"

BoxCollider::BoxCollider() : x(0.0f), y(0.0f), w(0.0f), h(0.0f) {}
BoxCollider::BoxCollider(float x, float y, float w, float h) : x(x), y(y), w(w), h(h) {}

bool BoxCollider::contains(int px, int py) const {
	return contains(static_cast<float>(px), static_cast<float>(py));
}

bool BoxCollider::contains(float px, float py) const {
    return (px >= x && px < x + w && py >= y && py < y + h);
}

bool BoxCollider::collide(const BoxCollider& a, const BoxCollider& b) {
    float pwA = a.x + a.w;
    float pwB = b.x + b.w;
    float phA = a.y + a.h;
    float phB = b.y + b.h;
    return (pwA > b.x && a.x < pwB && phA > b.y && a.y < phB);
}
