/**
* @file SceneManager.h
* @author Hudson Schumaker
* @brief Defines the SceneManager class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "Scene.h"
#include "../Pch.h"

class SceneManager final {
private:
    inline static SceneManager* instance = nullptr;

    /**
    * @brief Map of scene names to unique pointers of Scene objects.
    */
    std::map<std::string, std::unique_ptr<Scene>> scenes;
    bool isLoading = false;

    SceneManager() = default;
    void displayLoadingScreen();

public:
    ~SceneManager() = default;

    /**
    * @brief Returns the singleton instance of SceneManager.
    * @return SceneManager* The singleton instance of SceneManager.
    */
    static SceneManager* getInstance();

    /**
    * @brief Adds a scene to the SceneManager.
    *
    * @param sceneName The name of the scene.
    * @param scene The unique pointer to the Scene object.
    */
    void addScene(const std::string& sceneName, std::unique_ptr<Scene> scene);

    /**
    * @brief Loads a scene asynchronously.
    * @param sceneName The name of the scene to load.
    */
    void loadSceneAsync(const std::string& sceneName);
};
