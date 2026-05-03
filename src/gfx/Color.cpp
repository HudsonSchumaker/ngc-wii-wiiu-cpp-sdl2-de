/**
* @file Color.cpp
* @author Hudson Schumaker
* @brief Defines the Color class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "Color.h"

const Color Color::Red = Color(255, 0, 0, 255);
const Color Color::RedBrighter = Color(224, 0, 0, 255);
const Color Color::RedBright = Color(192, 0, 0, 255);
const Color Color::RedMedium = Color(160, 0, 0, 255);
const Color Color::RedDim = Color(128, 0, 0, 255);
const Color Color::RedDimmer = Color(96, 0, 0, 255);
const Color Color::RedDimmest = Color(64, 0, 0, 255);
const Color Color::RedDarkest = Color(32, 0, 0, 255);

const Color Color::Green = Color(0, 255, 0, 255);
const Color Color::GreenBrighter = Color(0, 224, 0, 255);
const Color Color::GreenBright = Color(0, 192, 0, 255);
const Color Color::GreenMedium = Color(0, 160, 0, 255);
const Color Color::GreenDim = Color(0, 128, 0, 255);
const Color Color::GreenDimmer = Color(0, 96, 0, 255);
const Color Color::GreenDimmest = Color(0, 64, 0, 255);
const Color Color::GreenDarkest = Color(0, 32, 0, 255);

const Color Color::Blue = Color(0, 0, 255, 255);
const Color Color::BlueBrighter = Color(0, 0, 224, 255);
const Color Color::BlueBright = Color(0, 0, 192, 255);
const Color Color::BlueMedium = Color(0, 0, 160, 255);
const Color Color::NavyBlue = Color(0, 0, 128, 255);
const Color Color::BlueDimmer = Color(0, 0, 96, 255);
const Color Color::BlueDimmest = Color(0, 0, 64, 255);
const Color Color::BlueDarkest = Color(0, 0, 32, 255);

const Color Color::White = Color(255, 255, 255, 255);
const Color Color::Black = Color(0, 0, 0, 255);
const Color Color::Gray = Color(128, 128, 128, 255);
const Color Color::GrayDarker = Color(64, 64, 64, 255);
const Color Color::Orange = Color(255, 200, 0, 255);
const Color Color::Yellow = Color(255, 255, 0, 255);
const Color Color::Pink = Color(255, 175, 175, 255);
const Color Color::Brown = Color(78, 53, 36, 255);
const Color Color::Purple = Color(128, 0, 128, 255);
const Color Color::Teal = Color(0, 128, 128, 255);
const Color Color::Lime = Color(0, 255, 18, 255);
const Color Color::Maroon = Color(128, 0, 0, 255);
const Color Color::Olive = Color(128, 128, 0, 255);
const Color Color::Navy = Color(0, 0, 128, 255);
const Color Color::Magenta = Color(255, 0, 255, 255);
const Color Color::Cyan = Color(0, 255, 255, 255);
const Color Color::Silver = Color(192, 192, 192, 255);
const Color Color::Gold = Color(255, 215, 0, 255);

Color::Color(int r, int g, int b, int a) : r(r), g(g), b(b), a(a) {}
