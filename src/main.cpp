#include "Pch.h"
#include "gfx/Gfx.h"
#include "gfx/Color.h"
#include "Context.h"
#include "InputManager.h"

int main(int argc, char **argv) {
	if (Context::getInstance()->start() > 0) {
		return 1;
	}

    SDL_Renderer* renderer = Context::getInstance()->getRenderer();
    


    bool quit = false;
    PAD_Init();
    InputManager inputManager;

    while (!quit) {
        inputManager.update();
        SDL_SetRenderDrawColor(renderer, 0x0, 0xFF, 0x0, 0xFF);
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);
    }
    
    delete Context::getInstance();
    return 0;
}
