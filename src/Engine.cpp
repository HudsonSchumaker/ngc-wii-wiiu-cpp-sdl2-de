/**
* @file Engine.cpp
* @author Hudson Schumaker
* @brief Implements the Engine class.
* @version 1.0.0
*
* Dodoi Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "Engine.h"
#include "core/Context.h"
#include "core/SceneManager.h"
#include "playground/MenuScreen.h"
#include "playground/TitleScreen.h"
#include "playground/SplashScreen.h"

Engine::~Engine() {
    quit();
}

Engine& Engine::getInstance() {
    static Engine instance;
    return instance;
}

void Engine::start() {
    setup();
    SceneManager::getInstance()->loadSceneAsync("SplashScreen"); // Entry point
}

void Engine::setup() {
    Context::getInstance().start();
    SceneManager::getInstance()->addScene("SplashScreen", std::make_unique<SplashScreen>());
    SceneManager::getInstance()->addScene("TitleScreen", std::make_unique<TitleScreen>());
    SceneManager::getInstance()->addScene("MenuScreen", std::make_unique<MenuScreen>());
}

void Engine::quit() {
    // Clean up resources, shut down subsystems, etc.
}
