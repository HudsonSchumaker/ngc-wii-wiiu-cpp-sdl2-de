#include "InputManager.h"

void InputManager::update() {
    previousButtons = currentButtons;
    resetFrameState();

    SDL_Event event;
    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT) {
            quitRequested = true;
        }
    }

    PAD_ScanPads();

    const Uint32 padDown = PAD_ButtonsDown(0);
    const Uint32 padHeld = PAD_ButtonsHeld(0);

    updateButtons(padDown, padHeld);
    updateMovement(padHeld);
}

void InputManager::resetFrameState() {
    moveX = 0;
    moveY = 0;
}

void InputManager::updateButtons(Uint32 padDown, Uint32 padHeld) {
    currentButtons[Button::Confirm] = (padHeld & PAD_BUTTON_A) != 0;
    currentButtons[Button::Cancel]  = (padHeld & PAD_BUTTON_B) != 0;
    currentButtons[Button::Upgrade] = (padHeld & PAD_BUTTON_X) != 0;
    currentButtons[Button::Sell]    = (padHeld & PAD_BUTTON_Y) != 0;
    currentButtons[Button::Pause]   = (padDown & PAD_BUTTON_START) != 0;
}

void InputManager::updateMovement(Uint32 padHeld) {
    moveX = 0;
    moveY = 0;

    if ((padHeld & PAD_BUTTON_LEFT) != 0) {
        moveX = -1;
    } else if ((padHeld & PAD_BUTTON_RIGHT) != 0) {
        moveX = 1;
    }

    if ((padHeld & PAD_BUTTON_UP) != 0) {
        moveY = -1;
    } else if ((padHeld & PAD_BUTTON_DOWN) != 0) {
        moveY = 1;
    }

    if (moveX == 0) {
        const s8 stickX = PAD_StickX(0);
        if (stickX < -32) {
            moveX = -1;
        } else if (stickX > 32) {
            moveX = 1;
        }
    }

    if (moveY == 0) {
        const s8 stickY = PAD_StickY(0);
        if (stickY > 32) {
            moveY = -1;
        } else if (stickY < -32) {
            moveY = 1;
        }
    }
}

bool InputManager::isDown(Button button) const {
    auto it = currentButtons.find(button);
    return it != currentButtons.end() ? it->second : false;
}

bool InputManager::isPressed(Button button) const {
    const bool current = isDown(button);

    auto it = previousButtons.find(button);
    const bool previous = it != previousButtons.end() ? it->second : false;

    return current && !previous;
}

bool InputManager::isReleased(Button button) const {
    const bool current = isDown(button);

    auto it = previousButtons.find(button);
    const bool previous = it != previousButtons.end() ? it->second : false;

    return !current && previous;
}

int InputManager::getMoveX() const {
    return moveX;
}

int InputManager::getMoveY() const {
    return moveY;
}

bool InputManager::isQuitRequested() const {
    return quitRequested;
}
