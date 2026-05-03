/**
* @file Color.h
* @author Hudson Schumaker
* @brief Defines the Color class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../Pch.h"

class Color final {
public:
    int r = 0, g = 0, b = 0, a = 0;
    static const Color Red;
    static const Color RedBrighter;
    static const Color RedBright;
    static const Color RedMedium;
    static const Color RedDim;
    static const Color RedDimmer;
    static const Color RedDimmest;
    static const Color RedDarkest;

    static const Color Green;
    static const Color GreenBrighter;
    static const Color GreenBright;
    static const Color GreenMedium;
    static const Color GreenDim;
    static const Color GreenDimmer;
    static const Color GreenDimmest;
    static const Color GreenDarkest;

    static const Color Blue;
    static const Color BlueBrighter;
    static const Color BlueBright;
    static const Color BlueMedium;
    static const Color NavyBlue;
    static const Color BlueDimmer;
    static const Color BlueDimmest;
    static const Color BlueDarkest;

    static const Color White;
    static const Color Black;
    static const Color Gray;
    static const Color GrayDarker;
    static const Color Orange;
    static const Color Yellow;
    static const Color Pink;
    static const Color Brown;
    static const Color Purple;
    static const Color Teal;
    static const Color Lime;
    static const Color Maroon;
    static const Color Olive;
    static const Color Navy;
    static const Color Magenta;
    static const Color Cyan;
    static const Color Silver;
    static const Color Gold;

    Color() = default;
    Color(int r, int g, int b, int a);
    ~Color() = default;
};
