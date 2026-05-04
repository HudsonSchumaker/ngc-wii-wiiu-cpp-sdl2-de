/**
* @file Main.cpp
* @author Hudson Schumaker
* @brief Defines the entry point of the game.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "Pch.h"
#include "Engine.h"

int main(int argc, char **argv) {
    Engine::getInstance().start();
    return 0;
}
