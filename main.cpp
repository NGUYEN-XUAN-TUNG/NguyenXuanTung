#include "init.h"
#include "game.h"
#include "render.h"
#include "ObstacleDot.h"
#include "definition.h"
#include "ObstaclePipe.h"

int main(int argc, char* args[]) {
    srand(time(0));
    if (!initGame()) return -1;
    initializeDots(centerX, centerY);
    SDL_Event e;
    bool quit = false;

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            } else if (e.type == SDL_MOUSEBUTTONDOWN || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE)) {
                pausing();
                if (menu_ || character_) {
                    renderinMenu(e);
                }
                else if (gameStarted) {
                    birdVelocityY = JUMP_STRENGTH;
                    Mix_VolumeChunk(gFlySound, 20);
                    Mix_PlayChannel(-1, gFlySound, 0);
                    ShowFlyAnimation = true;
                    FlyAnimationTimer = 10;
                }
            } else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
                if (gameStarted) gameStarted = false;
                else gameStarted = true;
            }
        }
        if (menu_) {
            LoadMenu();
        }
        else if (character_) {
            LoadCharacterSelectScreen();
        }
        else if (gameStarted) {
            updateGame();
            if (isover) quit = true;
            render(e);
        }
        SDL_Delay(16);
    }

    closeGame();
    return 0;
}
