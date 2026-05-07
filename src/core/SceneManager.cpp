/**
* @file SceneManager.cpp
* @author Hudson Schumaker
* @brief Implements the SceneManager class.
* @version 1.0.0
*
* Dodoi Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "Context.h"
#include "SceneManager.h"

SceneManager& SceneManager::getInstance() {
    static SceneManager instance;
    return instance;
}

void SceneManager::displayLoadingScreen() {
    SDL_Renderer* renderer = Context::getInstance().getRenderer();
    SDL_SetRenderDrawColor(renderer, 192, 192, 192, 255); // Silver for test
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

void SceneManager::loadSceneAsync(const std::string& sceneName) {
    displayLoadingScreen();

    // Check if the scene exists
    if (scenes.find(sceneName) == scenes.end()) {
        return;
    }

    Scene* scene = scenes[sceneName].get();
    scene->loadAsync();

    // Wait for the scene to finish loading
    scene->waitForLoad();
    auto exitCode = scene->run();
    if (exitCode == EXIT) {
        return;
    }

    std::string nextSceneName = scene->getNextScene();
    scene->unload();
    // Load the next scene
    if (!nextSceneName.empty()) {
        loadSceneAsync(nextSceneName);
    }
}

void SceneManager::addScene(const std::string& sceneName, std::unique_ptr<Scene> scene) {
    scenes[sceneName] = std::move(scene);
}
