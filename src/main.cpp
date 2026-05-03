#include "Pch.h"
#include "gfx/Gfx.h"
#include "sfx/Sfx.h"
#include "core/Context.h"
#include "gfx/Color.h"
#include "InputManager.h"
#include "HemiHead_ttf.h"
#include "ok_wav.h"

int main(int argc, char **argv) {
    bool quit = false;
	if (Context::getInstance()->start() > 0) {
		return 1;
	}
    SDL_Renderer* renderer = Context::getInstance()->getRenderer();

    Mix_Chunk* sound = Sfx::loadSound(ok_wav, ok_wav_size);
    Mix_PlayChannel(-1, sound, 0);

    PAD_Init();
    InputManager inputManager;
    while (!quit) {
        inputManager.update();
        SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0xFF, 0xFF);
        SDL_RenderClear(renderer);

        // Test drawing functions
        Gfx::drawTriangle(100, 100, 200, 100, 150, 200, Color::Red);
        Gfx::drawCircle(320, 240, 50, Color::Blue);
        Gfx::drawFillCircle(0, 240, 50, Color::Black);
        Gfx::drawDashedCircle(320, 240, 100, 10, Color::Yellow);
        Gfx::drawBox(SDL_Rect{50, 100, 100, 100}, Color::Purple);
        Gfx::drawFillBox(SDL_Rect{200, 50, 100, 100}, Color::Pink); 
        
        SDL_Texture* textTexture = Gfx::createText(HemiHead_ttf, HemiHead_ttf_size, "Hello, World!", 24, Color::White);
        if (textTexture) {
            SDL_Rect textRect = Gfx::getTextureSize(*textTexture);
            SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
            SDL_DestroyTexture(textTexture);
        }

        SDL_RenderPresent(renderer);
    }
    
    delete Context::getInstance();
    return 0;
}
