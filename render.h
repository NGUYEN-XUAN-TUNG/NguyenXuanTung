
#ifndef RENDER_H
#define RENDER_H
#include "init.h"
#include"ObstacleDot.h"
void render() {
    SDL_RenderClear(gRenderer);

    SDL_Rect BackgroundRect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_RenderCopy(gRenderer, gBackgroundTexture, NULL, &BackgroundRect);

    Obstacle1(gRenderer);


    SDL_Rect BirdPos = {birdX, birdY, 40, 40};
    SDL_RenderCopy(gRenderer, gBirdTexture, NULL, &BirdPos);

    if (ShowFlyAnimation) {
        SDL_Rect FlyAnimationPos = {FlyAnimationX, FlyAnimationY, 40, 40};
        SDL_RenderCopy(gRenderer, gFlyAnimationTexture, NULL, &FlyAnimationPos);
    }
    SDL_RenderPresent(gRenderer);
}

#endif
