
#ifndef RENDER_H
#define RENDER_H
#include "init.h"
#include"definition.h"
#include"ObstacleDot.h"
#include "ObstaclePipe.h"
void render() {
    SDL_RenderClear(gRenderer);

    SDL_Rect BackgroundRect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_RenderCopy(gRenderer, gBackgroundTexture, NULL, &BackgroundRect);

    Obstacle2(gRenderer, centerX,centerY);
    Obstacle1(gRenderer);
    Obstacle3(gRenderer);
    Obstacle4(gRenderer);
    Obstacle5(gRenderer);

    SDL_Rect BirdPos = {birdX, birdY, birdW, birdH};
    SDL_RenderCopy(gRenderer, gBirdTexture, NULL, &BirdPos);

    if (ShowFlyAnimation) {
        SDL_Rect FlyAnimationPos = {FlyAnimationX, FlyAnimationY, birdW, birdH};
        SDL_RenderCopy(gRenderer, gFlyAnimationTexture, NULL, &FlyAnimationPos);
    }
    SDL_RenderPresent(gRenderer);
}
#endif
