/**
* @file Scene.cpp
* @author Hudson Schumaker
* @brief Implements the prototype of Scene class.
* @version 1.0.0
*
* Dodoi Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "Scene.h"
#include "Context.h"

Scene::Scene() {
    this->renderer = context.getRenderer();
}

float Scene::calculateDeltaTime() {
    static Uint64 prev = 0;
    const Uint64 now = SDL_GetPerformanceCounter();

    if (prev == 0) {
        prev = now;
        deltaTime = 0.0f;
        return deltaTime;
    }

    const double freq = static_cast<double>(SDL_GetPerformanceFrequency());
    double dt = static_cast<double>(now - prev) / freq;
    prev = now;

    // Clamp spikes
    if (dt > 0.1) dt = 0.1;
    if (dt < 0.0) dt = 0.0;

    // Mild smoothing to reduce micro-stutter
    const float alpha = 0.1f;
    if (deltaTime <= 0.0f) deltaTime = static_cast<float>(dt);
    else deltaTime += (static_cast<float>(dt) - deltaTime) * alpha;

    return deltaTime;
}

void Scene::loadAsync() {
    camera.color = Color::Black;
    loadFuture = std::async(std::launch::async, &Scene::load, this);
}

void Scene::beginRender() {
    // Clear with the chroma key color (magenta): these pixels become transparent "holes".
    // SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
    SDL_SetRenderDrawColor(renderer, camera.color.r, camera.color.g, camera.color.b, camera.color.a);
    SDL_RenderClear(renderer);
}

void Scene::endRender() {
    SDL_RenderPresent(renderer);
}

void Scene::waitForLoad() {
    if (loadFuture.valid()) {
        loadFuture.get();
        isLoaded = true;
    }
}

const std::string& Scene::getNextScene() const {
    return nextScene;
}

bool Scene::getIsLoaded() {
    return isLoaded;
}
