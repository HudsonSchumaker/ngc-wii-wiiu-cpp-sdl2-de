/**
* @file MenuScreen.cpp
* @author Hudson Schumaker
* @brief Implements the MenuScreen class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "../gfx/Gfx.h"
#include "MenuScreen.h"
#include "HemiHead_ttf.h"
#include "../core/Context.h"

MenuScreen::MenuScreen() : Scene() {}

MenuScreen::~MenuScreen() {
    unload();
}

void MenuScreen::load() {
    nextScene = "GameScreen";
    title = new Label(0, 80);

    title->setText("Binary Siege");
    title->setFont(HemiHead_ttf, HemiHead_ttf_size, 48);
    title->setHorizontalCenter();

    isRunning = true;
}

short MenuScreen::run() {
    while (isRunning) {
        input();
        update();
        render();
    }
    return exit;
}

void MenuScreen::input() {
    PAD_ScanPads();
    u16 buttonsDown = PAD_ButtonsDown(0);
    if (buttonsDown & PAD_BUTTON_UP) {
        controlMenu(-1);
    } else if (buttonsDown & PAD_BUTTON_DOWN) {// TODO: change for LEFT/RIGHT
        controlMenu(1);
    } else if (buttonsDown & PAD_BUTTON_A) {
        isRunning = false;
        exit = NEXT;
    }
}

void MenuScreen::update() {
    title->update();
}

void MenuScreen::render() {
    beginRender();
    {
        title->render();
    }
    endRender();
}

void MenuScreen::controlMenu(short direction) {
    // Placeholder for menu navigation logic
}

void MenuScreen::unload() {
    isLoaded = false;

    delete title;
    title = nullptr;
}
