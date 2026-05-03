/**
* @file DeMath.cpp
* @author Hudson Schumaker
* @brief Implements the DeMath class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "DeMath.h"

float DeMath::distanceBetweenPoints(const float x1, const float y1, const float x2, const float y2) {
    return std::hypot(x2 - x1, y2 - y1);
}

float DeMath::normalizeAngle(const float angle) {
    auto resultAngle = std::remainder(angle, Def::TWO_PI);
    if (resultAngle < 0) {
        resultAngle = Def::TWO_PI + resultAngle;
    }
    return resultAngle;
}

float DeMath::deg2Rad(const float angle) {
    return angle * Def::PI / 180.0f;
}

float DeMath::rad2Deg(const float angle) {
    return angle * 180.0f / Def::PI;
}

float DeMath::randf(const float min, const float max) {
    if (min == max) {
        return min;
    }

    const float low = std::min(min, max);
    const float high = std::max(min, max);
    return low + static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * (high - low);
}

float DeMath::interpolatef(const float start, const float end, const float t) {
    return start + t * (end - start);
}

float DeMath::clamp01(const float v) {
    if (v < 0.0f) return 0.0f;
    if (v > 1.0f) return 1.0f;
    return v;
}

float DeMath::easeOutCubic(const float t) {
    const float clampedT = DeMath::clamp01(t);
    const float inv = 1.0f - clampedT;
    return 1.0f - (inv * inv * inv);
}
