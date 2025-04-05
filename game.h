
#ifndef GAME_H
#define GAME_H
#include "init.h"
#include "definition.h"
#include "ObstacleDot.h"
#include "ObstaclePipe.h"
#include <cstdlib>
#include <ctime>
int randobs=rand()%4;
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
        else if(randobs==2) yTop+=FALL_SPEED;
        else if(randobs==3) y1_+=FALL_SPEED_FIRST;}


    if (birdY < CHECK_POINT) {
        birdY = CHECK_POINT;
    if(randobs==0)squareOffsetY+=FALL_SPEED;
    else if(randobs==1) circleOffSetY+=FALL_SPEED;
    else if(randobs==2) yTop+=FALL_SPEED;
    else if(randobs==3) y1_+=FALL_SPEED;}


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
    else if (randobs==2){for( SDL_Rect& rect:getPipeRect3()){
            if(CheckCollisionRect(rect,birdRect))isover=true;}
            }
    else if(randobs==3){for( SDL_Rect& rect:getColumnRect4()){
            if(CheckCollisionRect(rect,birdRect))isover=true;}
            }


    if (squareOffsetY > SCREEN_HEIGHT||circleOffSetY>SCREEN_HEIGHT||yTop>SCREEN_HEIGHT||y1_>SCREEN_HEIGHT) {
        if (randobs == 0) resetObstacle1();
        else if(randobs==1) resetObstacle2();
        else if(randobs==2) resetObstacle3();
        else if(randobs==3) resetObstacle4();

        randobs=rand()%4;
    }

    lastBirdY = birdY;
}
#endif
