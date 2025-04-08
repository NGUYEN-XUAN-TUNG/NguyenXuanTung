#include "init.h"
#include "game.h"
#include "render.h"
#include"ObstacleDot.h"
#include"definition.h"
#include "ObstaclePipe.h"
bool gameStarted = false;
int main(int argc, char* args[]) {
    srand(time(0));
    if (!initGame()) return -1;
    initializeDots(centerX,centerY);
    SDL_Event e;
    bool quit = false;

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) quit = true;
            if (e.type == SDL_MOUSEBUTTONDOWN|| (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE)) {
                if(!gameStarted) gameStarted=true;
                birdVelocityY = JUMP_STRENGTH;
                Mix_PlayChannel(-1, gFlySound, 0);
                Mix_VolumeChunk(gFlySound, 20);
                ShowFlyAnimation = true;
                FlyAnimationTimer = 10;
            }
        }
        if(gameStarted){updateGame();}
        if(isover) quit=true;
        render();
        SDL_Delay(16);
    }
    closeGame();
    return 0;
}

