#include "init.h"
#include "game.h"
#include "render.h"
#include"ObstacleDot.h"
#include"definition.h"
#include "ObstaclePipe.h"

int main(int argc, char* args[]) {
    srand(time(0));
    if (!initGame()) return -1;

    initializeDots(centerX,centerY);
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
        if(isover) quit=true;
        render();
        SDL_Delay(16);
    }

    closeGame();
    return 0;
}

