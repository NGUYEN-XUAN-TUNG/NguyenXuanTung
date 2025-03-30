#include "init.h"
#include "game.h"
#include "render.h"

int main(int argc, char* args[]) {
    if (!initGame()) return -1;

    SDL_Event e;
    bool quit = false;

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) quit = true;
            if (e.type == SDL_MOUSEBUTTONDOWN) {
                birdVelocityY = JUMP_STRENGTH;
                ShowFlyAnimation = true;
                FlyAnimationTimer = 10;
            }
        }

        updateGame();
        render();
        SDL_Delay(16);
    }

    closeGame();
    return 0;
}
