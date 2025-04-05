
#ifndef GAME_H
#define GAME_H
#include "init.h"
#include "definition.h"
#include "ObstacleDot.h"
#include "ObstaclePipe.h"
#include <cstdlib>
#include <ctime>
int randobs=1;
bool isover=false;
void updateGame() {
    birdVelocityY += GRAVITY;
    birdY += birdVelocityY;

    FlyAnimationY = birdY + birdH;
    if (FlyAnimationTimer > 0) {
        FlyAnimationTimer--;
    } else {
        ShowFlyAnimation = false;
    }

    int deltaY = lastBirdY - birdY;
    if (deltaY > 0 && birdY < maxBirdY) {
        maxBirdY = birdY;
        if(randobs==0)squareOffsetY+=FALL_SPEED_FIRST;
        else if(randobs==1) circleOffSetY+=FALL_SPEED_FIRST;
        else yTop+=FALL_SPEED;}


    if (birdY < CHECK_POINT) {
        birdY = CHECK_POINT;
    if(randobs==0)squareOffsetY+=FALL_SPEED;
    else if(randobs==1) circleOffSetY+=FALL_SPEED;
    else yTop+=FALL_SPEED;}


    if (birdY > SCREEN_HEIGHT) {
        birdY = SCREEN_HEIGHT - 50;
    }
    SDL_Rect birdRect = {birdX, birdY, birdW, birdH};

    if(randobs==0){for (const auto& dot : dots) {
            if (CheckCollisionCircle(birdRect, getDotRect1(dot))) isover = true;}
            }
    else if(randobs==1){for (const auto& dot : circledots) {
            if (CheckCollisionCircle(birdRect, getDotRect2(dot))) isover = true;}
            }
    else{for( SDL_Rect& rect:getPipeRect3()){
            if(CheckCollisionRect(rect,birdRect))isover=true;}
            }


    if (squareOffsetY > SCREEN_HEIGHT||circleOffSetY>SCREEN_HEIGHT||yTop>SCREEN_HEIGHT) {
        if (randobs == 0) {
            resetObstacle1();
        } else if(randobs==1) {
            resetObstacle2();
        }else {
            resetObstacle3();}

        randobs=rand()%3;
    }

    lastBirdY = birdY;
}
#endif
