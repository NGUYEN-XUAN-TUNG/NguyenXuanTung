
#ifndef GAME_H
#define GAME_H
#include "init.h"
#include "ObstacleDot.h"
bool isover=false;



bool CheckCollision(SDL_Rect a, SDL_Rect b) {
    return (a.x < b.x + b.w && a.x + a.w > b.x &&
            a.y < b.y + b.h && a.y + a.h > b.y);
}

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
        squareOffsetY += FALL_SPEED;
    }

    if (birdY < CHECK_POINT)  {
        birdY = CHECK_POINT;
        squareOffsetY += FALL_SPEED;
    }

    if (birdY > SCREEN_HEIGHT) {
        birdY = SCREEN_HEIGHT - 50;
    }

    SDL_Rect birdRect = {birdX, birdY, 40, 40};
    for (const auto& dot : dots) {
        if (CheckCollision(birdRect, getDotRect(dot))) {
            cout << "Game Over!" << endl;
            isover = true;
        }
    }

    // Nếu obstacle đi xuống quá màn hình thì reset lại vị trí
    if (squareOffsetY > SCREEN_HEIGHT-200) {
        resetObstacle();
    }
    lastBirdY = birdY;
}

#endif
