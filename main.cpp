#include "init.h"
#include "game.h"
#include "gameover.h"
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
                pausing(e);
                if (menu_ || character_) {
                    renderinMenu(e);
                }else if (!gameStarted&&!isover&&isplaying) {
                    gameStarted=true;
                    ready=false;
                    birdVelocityY = JUMP_STRENGTH;
                    Mix_VolumeChunk(gFlySound, 20);
                    Mix_PlayChannel(-1, gFlySound, 0);
                    ShowFlyAnimation = true;
                    FlyAnimationTimer = 10;
                }else if (gameStarted&&!isover&&isplaying) {
                    birdVelocityY = JUMP_STRENGTH;
                    Mix_VolumeChunk(gFlySound, 20);
                    Mix_PlayChannel(-1, gFlySound, 0);
                    ShowFlyAnimation = true;
                    FlyAnimationTimer = 10;
                }else if(isover){
                    renderinGameover(e);
                }
            }}
      if (menu_) {
            LoadMenu();
        }
        else if (character_) {
            renderCharacterSelection(e);
        }else if (gameStarted&&isplaying) {
            if (!isover) {
                updateGame();
                render(e);
                playedDieSound=false;
            } else {
                if (!playedDieSound) {
                Mix_VolumeChunk(gDieSound, 40);
                Mix_PlayChannel(-1, gDieSound, 0);
                playedDieSound = true;
                }
                highscore=loadHighScore();
                saveScore(score);
                LoadGameover();
            }
        }
        SDL_Delay(16);
    }

    closeGame();
    return 0;
}
