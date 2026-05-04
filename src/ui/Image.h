#pragma once
#include "Widget.h"
#include "../gfx/Color.h"

class Image final : public Widget {
private:
    SDL_Texture* texture = nullptr;
    Color tint = Color::White;

public:
    Image() = default;
    Image(int x, int y);
    ~Image() override;

    void setSource(const uint8_t* data, size_t size);
    void setTint(const Color& color);
    void render() override;
};
