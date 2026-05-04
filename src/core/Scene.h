/**
* @file Scene.h
* @author Hudson Schumaker
* @brief Defines the Scene class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../Pch.h"
#include "Camera.h"
#include "Context.h"

class Scene {
private:
    std::future<void> loadFuture;

    virtual void load() = 0;
    virtual void input() = 0;
    virtual void update() = 0;
    virtual void render() = 0;

protected:
    Camera camera;
	Context& context = Context::getInstance();
    SDL_Renderer* renderer = nullptr;

    float deltaTime = 0.0f;
    bool isRunning = false;
    bool isPaused = false;
    bool isLoaded = false;
    short exit = NEXT;
    std::string nextScene = "TitleScreen";

    float calculateDeltaTime();
    void beginRender();
    void endRender();

public:
    Scene();
    virtual ~Scene() {}

    virtual short run() = 0;
    virtual void unload() = 0;

    void loadAsync();
    void waitForLoad();
    bool getIsLoaded();
    const std::string& getNextScene() const;
};
