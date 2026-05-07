/**
* @file DeMath.h
* @author Hudson Schumaker
* @brief Implements the DeMath class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../Pch.h"

class DeMath final {
public:

    /**
     * @brief Calculates the distance between two points.
     * 
     * @param x1 The x-coordinate of the first point.
     * @param y1 The y-coordinate of the first point.
     * @param x2 The x-coordinate of the second point.
     * @param y2 The y-coordinate of the second point.
     * @return The distance between the two points.
    */
    static float distanceBetweenPoints(const float x1, const float y1, const float x2, const float y2);

    /**
     * @brief Normalize the angle.
     * 
     * @param angle The angle.
     * @return The normalized angle.
    */
    static float normalizeAngle(const float angle);

    /**
     * @brief Converts an angle from degrees to radians.
     * 
     * @param angle The angle in degrees.
     * @return The angle in radians.
    */
    static float deg2Rad(const float angle);

    /**
     * @brief Converts an angle from radians to degrees.
     * 
     * @param angle The angle in radians.
     * @return The angle in degrees.
    */
    static float rad2Deg(const float angle);

    /**
     * @brief Generates a random float between min and max.
     * 
     * @param min The minimum value.
     * @param max The maximum value.
     * 
     * @return A random float between min and max.
    */
    static float randf(const float min, const float max);
	
    /**
     * @brief Linearly interpolates between two values.
     * 
     * @param start The starting value.
     * @param end The ending value.
     * @param t The interpolation factor (0.0 to 1.0).
     * @return The interpolated value.
     */
    static float interpolatef(const float start, const float end, const float t);
	
    /**
     * @brief Clamps a value between 0 and 1.
     * 
     * @param v The value to clamp.
     * @return The clamped value.
     */
    static float clamp01(const float v);
    
    /**
     * @brief Eases out a value using a cubic function.
     * 
     * @param t The value to ease out.
     * @return The eased out value.
     */
    static float easeOutCubic(const float t);

    /**
     * @brief Calculates the reciprocal square root of a number.
     * 
     * @param number The number.
     * @return The reciprocal square root of the number.
     */
    static float fastInvSqrt(const float number);

    
};
