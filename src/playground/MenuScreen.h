/**
* @file MenuScreen.h
* @author Hudson Schumaker
* @brief Defines the MenuScreen class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#pragma once
#include "../ui/Label.h"
#include "../ui/Image.h"
#include "../core/Scene.h"

class MenuScreen final : public Scene {
private:
    Label* title = nullptr;
    Image* start = nullptr;
    Image* options = nullptr;
    short selectedIndex = 0;
    
    void load() override;
    void input() override;
    void update() override;
    void render() override;
    void unload() override;
    void controlMenu(short direction);

public:
    MenuScreen();
    ~MenuScreen();
    short run() override;
};
