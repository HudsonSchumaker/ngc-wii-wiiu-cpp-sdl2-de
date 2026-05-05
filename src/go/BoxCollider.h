/**
* @file BoxCollider.h
* @author Hudson Schumaker
* @brief Defines the BoxCollider class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once

class BoxCollider final {
public:
	float x, y, w, h;

	BoxCollider();
	BoxCollider(float x, float y, float w, float h);
	~BoxCollider() = default;

	bool contains(int px, int py) const;
	bool contains(float px, float py) const;
	static bool collide(const BoxCollider& a, const BoxCollider& b);
};
