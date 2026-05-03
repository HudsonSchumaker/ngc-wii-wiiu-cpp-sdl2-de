/**
* @file Gfx.cpp
* @author Hudson Schumaker
* @brief Defines the Gfx class.
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*/
#include "Gfx.h"
#include "../core/Context.h"

SDL_Texture* Gfx::loadTexture(const uint8_t* data, const size_t size) {
    SDL_Renderer* renderer = Context::getInstance().getRenderer();

    SDL_RWops* rw = SDL_RWFromMem((void*)data, size);
    SDL_Texture* texture = IMG_LoadTexture_RW(renderer, rw, 1);
    return texture;
}

SDL_Texture* Gfx::createText(const uint8_t* data, const size_t size, const std::string& text, short textSize, const Color& color) {
    SDL_Renderer* renderer = Context::getInstance().getRenderer();

    SDL_RWops* rw = SDL_RWFromMem((void*)data, size);
    TTF_Font* font = TTF_OpenFontRW(rw, 1, textSize);

    SDL_Color sdlColor = color.toSDLColor();
    SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), sdlColor);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);
    TTF_CloseFont(font);
    return texture;
}

SDL_Rect Gfx::getTextureSize(SDL_Texture* texture) {
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
    return rect;
}

SDL_FRect Gfx::getTextureFSize(SDL_Texture* texture) {
    SDL_Rect rect;
    SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
    SDL_FRect rectF = { 0.0f, 0.0f, static_cast<float>(rect.w), static_cast<float>(rect.h) };
    return rectF;
}

// Primitives
void Gfx::drawLine(const int x0, const int y0, const int x1, const int y1, const Color& color) {
    SDL_Renderer* renderer = Context::getInstance().getRenderer();

    Uint8 prevR, prevG, prevB, prevA;
    SDL_GetRenderDrawColor(renderer, &prevR, &prevG, &prevB, &prevA);
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer, x0, y0, x1, y1);

    SDL_SetRenderDrawColor(renderer, prevR, prevG, prevB, prevA);
}

void Gfx::drawCircle(const int centerX, const int centerY, const int radius, const Color& color) {
    SDL_Renderer* renderer = Context::getInstance().getRenderer();

    Uint8 prevR, prevG, prevB, prevA;
    SDL_GetRenderDrawColor(renderer, &prevR, &prevG, &prevB, &prevA);
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    // Draw
    int x = radius - 1;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - (radius << 1);

    while (x >= y) {
        SDL_RenderDrawPoint(renderer, centerX + x, centerY + y);
        SDL_RenderDrawPoint(renderer, centerX + y, centerY + x);
        SDL_RenderDrawPoint(renderer, centerX - y, centerY + x);
        SDL_RenderDrawPoint(renderer, centerX - x, centerY + y);
        SDL_RenderDrawPoint(renderer, centerX - x, centerY - y);
        SDL_RenderDrawPoint(renderer, centerX - y, centerY - x);
        SDL_RenderDrawPoint(renderer, centerX + y, centerY - x);
        SDL_RenderDrawPoint(renderer, centerX + x, centerY - y);

        if (err <= 0) {
            y++;
            err += dy;
            dy += 2;
        }

        if (err > 0) {
            x--;
            dx += 2;
            err += dx - (radius << 1);
        }
    }

    SDL_SetRenderDrawColor(renderer, prevR, prevG, prevB, prevA);
}

void Gfx::drawFillCircle(const int centerX, const int centerY, const int radius, const Color& color) {
    SDL_Renderer* renderer = Context::getInstance().getRenderer();

    Uint8 prevR, prevG, prevB, prevA;
    SDL_GetRenderDrawColor(renderer, &prevR, &prevG, &prevB, &prevA);
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    // Draw
    for (int y = -radius; y <= radius; y++) {
        for (int x = -radius; x <= radius; x++) {
            if (x * x + y * y <= radius * radius) {
                SDL_RenderDrawPoint(renderer, centerX + x, centerY + y);
            }
        }
    }

    SDL_SetRenderDrawColor(renderer, prevR, prevG, prevB, prevA);
}

void Gfx::drawDashedCircle(const int centerX, const int centerY, const int radius, const int dashLength, const Color& color) {
    SDL_Renderer* renderer = Context::getInstance().getRenderer();

    Uint8 prevR, prevG, prevB, prevA;
    SDL_GetRenderDrawColor(renderer, &prevR, &prevG, &prevB, &prevA);
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    // Draw
    const int totalSegments = int(radius * Def::TWO_PI / dashLength);
    const float angleIncrement = Def::TWO_PI / totalSegments;
    for (short i = 0; i < totalSegments; ++i) {
        float angle = angleIncrement * i;

        int x1 = static_cast<int>(centerX + radius * std::cosf(angle));
        int y1 = static_cast<int>(centerY + radius * std::sinf(angle));

        angle = angleIncrement * (i + 1);

        int x2 = static_cast<int>(centerX + radius * std::cosf(angle));
        int y2 = static_cast<int>(centerY + radius * std::sinf(angle));

        if (i % 2 == 0) {
            SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
        }
    }

    SDL_SetRenderDrawColor(renderer, prevR, prevG, prevB, prevA);
}

void Gfx::drawBox(const SDL_Rect& rect, const Color& color) {
    drawBox(rect.x, rect.y, rect.w, rect.h, color.r, color.g, color.b, color.a);
}

void Gfx::drawBox(const SDL_FRect& rect, const Color& color) {
    drawBox(rect.x, rect.y, rect.w, rect.h, color.r, color.g, color.b, color.a);
}

void Gfx::drawBox(const float x, const float y, const float w, const float h, const int r, const int g, const int b, const int a) {
    SDL_Renderer* renderer = Context::getInstance().getRenderer();
    Uint8 prevR, prevG, prevB, prevA;
    SDL_GetRenderDrawColor(renderer, &prevR, &prevG, &prevB, &prevA);
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    
    SDL_FRect rect = { x, y, w, h };
    SDL_RenderDrawRectF(renderer, &rect);

    SDL_SetRenderDrawColor(renderer, prevR, prevG, prevB, prevA);
}

void Gfx::drawFillBox(const SDL_FRect& rect, const Color& color) {
    drawFillBox(rect.x, rect.y, rect.w, rect.h, color.r, color.g, color.b, color.a);
}

void Gfx::drawFillBox(const SDL_Rect& rect, const Color& color) {
    drawFillBox(rect.x, rect.y, rect.w, rect.h, color.r, color.g, color.b, color.a);
}

void Gfx::drawFillBox(const float x, const float y, const float w, const float h, const int r, const int g, const int b, const int a) {
    SDL_Renderer* renderer = Context::getInstance().getRenderer();
    
    // Save the current draw color
    Uint8 prevR, prevG, prevB, prevA;
    SDL_GetRenderDrawColor(renderer, &prevR, &prevG, &prevB, &prevA);
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    
    // Draw the filled rectangle
    SDL_FRect rect = { x, y, w, h };
    SDL_RenderFillRectF(renderer, &rect);
    
    // Restore the previous draw color
    SDL_SetRenderDrawColor(renderer, prevR, prevG, prevB, prevA);
}

void Gfx::drawTriangle(const int x1, const int y1, const int x2, const int y2, const int x3, const int y3, const Color& color) {
    drawLine(x1, y1, x2, y2, color);
    drawLine(x2, y2, x3, y3, color);
    drawLine(x3, y3, x1, y1, color);
}
