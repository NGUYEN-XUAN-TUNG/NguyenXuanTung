#ifndef GAME_H
#define GAME_H
#include "init.h"

void updateGame() {
    birdVelocityY += GRAVITY;
    birdY += birdVelocityY;

    FlyAnimationX = birdX;
    FlyAnimationY = birdY + 40;
    if (FlyAnimationTimer > 0) {
        FlyAnimationTimer--;
    } else {
        ShowFlyAnimation = false;
    }

    int deltaY = lastBirdY - birdY;
    if (deltaY > 0 && birdY < maxBirdY) {
        maxBirdY = birdY;
        obstacleRect.y += deltaY;
    }

    if (birdY < CHECK_POINT) {
        birdY = CHECK_POINT;
        obstacleRect.y += OBSTACLE_SPEED;
    }

    if (birdY > SCREEN_HEIGHT) {
        birdY = SCREEN_HEIGHT - 50;
    }

    if (obstacleRect.y > SCREEN_HEIGHT) {
        gCurrentObstacleTexture = gObstacleTextures[rand() % NUMBER_OF_OBSTACLE];
        int w, h;
        SDL_QueryTexture(gCurrentObstacleTexture, NULL, NULL, &w, &h);
        obstacleRect = {(SCREEN_WIDTH - w) / 2, -h, w, h};
        lastBirdY = birdY;
    }

    SDL_Rect birdRect = {birdX, birdY, 40, 40};
    SDL_Rect obstacleRectScaled = {obstacleRect.x, obstacleRect.y, obstacleRect.w, obstacleRect.h};
    if (CheckCollision(birdRect, obstacleRectScaled)) {
        cout << "Game Over!" << endl;
        exit(0);
    }

    lastBirdY = birdY;
}

#endif

