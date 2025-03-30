#ifndef RENDER_H
#define RENDER_H
#include "init.h"

void render() {
    SDL_RenderClear(gRenderer);

    SDL_Rect BackgroundRect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_RenderCopy(gRenderer, gBackgroundTexture, NULL, &BackgroundRect);

    SDL_Rect BirdPos = {birdX, birdY, 40, 40};
    SDL_RenderCopy(gRenderer, gBirdTexture, NULL, &BirdPos);

    if (ShowFlyAnimation) {
        SDL_Rect FlyAnimationPos = {FlyAnimationX, FlyAnimationY, 40, 40};
        SDL_RenderCopy(gRenderer, gFlyAnimationTexture, NULL, &FlyAnimationPos);
    }

    int w, h;
    SDL_QueryTexture(gCurrentObstacleTexture, NULL, NULL, &w, &h);
    SDL_Rect obstacleScaled = {obstacleRect.x, obstacleRect.y, w, h};
    SDL_Point center = {w / 2, h / 2};
    SDL_RenderCopyEx(gRenderer, gCurrentObstacleTexture, NULL, &obstacleScaled, rotationAngle, &center, SDL_FLIP_NONE);
    rotationAngle += 1.5f;

    SDL_RenderPresent(gRenderer);
}

#endif
