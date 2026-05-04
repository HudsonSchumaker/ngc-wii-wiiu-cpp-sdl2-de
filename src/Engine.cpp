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
#include "SplashScreen.h"

Engine::~Engine() {
    quit();
}

Engine& Engine::getInstance() {
    static Engine instance;
    return instance;
}

void Engine::start() {
    setup();
    SceneManager::getInstance()->loadSceneAsync("SplashScreen");
}

void Engine::setup() {
    Context::getInstance().start();
    SceneManager::getInstance()->addScene("SplashScreen", std::make_unique<SplashScreen>());
}

void Engine::quit() {
    // Clean up resources, shut down subsystems, etc.
}
