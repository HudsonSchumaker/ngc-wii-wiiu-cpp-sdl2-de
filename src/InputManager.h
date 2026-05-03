#pragma once
#include "Pch.h"

enum class Button {
    Confirm,
    Cancel,
    Upgrade,
    Sell,
    Pause
};

class InputManager final {
private:
    std::unordered_map<Button, bool> currentButtons;
    std::unordered_map<Button, bool> previousButtons;

    int moveX = 0;
    int moveY = 0;
    bool quitRequested = false;

    void updateButtons(Uint32 padDown, Uint32 padHeld);
    void updateMovement(Uint32 padHeld);

public:
    InputManager() = default;
    ~InputManager() = default;

    void update();
    void resetFrameState();

    bool isDown(Button button) const;
    bool isPressed(Button button) const;
    bool isReleased(Button button) const;

    int getMoveX() const;
    int getMoveY() const;
    bool isQuitRequested() const;
};
