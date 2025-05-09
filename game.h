#ifndef GAME_H
#define GAME_H
#include "init.h"
#include "definition.h"
#include "ObstacleDot.h"
#include "ObstaclePipe.h"
#include "gameover.h"
#include <cstdlib>
#include <ctime>
int randobs=1;
int pre_randobs;
void updateGame() {
    birdVelocityY += GRAVITY;
    birdY += birdVelocityY;

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
        else if(randobs==3) y1_+=FALL_SPEED_FIRST;
        else if(randobs==4) o5y_line1+=FALL_SPEED_FIRST;
        else if(randobs==5) y_gun_incre+=FALL_SPEED_FIRST;}


    if (birdY < CHECK_POINT) {
        birdY = CHECK_POINT;
    if(randobs==0)squareOffsetY+=FALL_SPEED;
    else if(randobs==1) circleOffSetY+=FALL_SPEED;
    else if(randobs==2) yTop+=FALL_SPEED;
    else if(randobs==3) y1_+=FALL_SPEED;
    else if(randobs==4) o5y_line1+=FALL_SPEED;
    else if(randobs==5) y_gun_incre+=FALL_SPEED;}
    if (birdY > SCREEN_HEIGHT) {
        isover=true;
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
        else if(randobs==4){for( SDL_Rect& rect:getPipeRect5()){
            if(CheckCollisionRect(rect,birdRect))isover=true;}
            }
        else if(randobs==5){for( SDL_Rect& rect:getBulletRect6()){
            if(CheckCollisionRect(rect,birdRect))isover=true;}
            }

    if (squareOffsetY > SCREEN_HEIGHT||circleOffSetY>SCREEN_HEIGHT+RADIUS||yTop>SCREEN_HEIGHT
            ||y1_>SCREEN_HEIGHT||o5y_line1>SCREEN_HEIGHT||y_gun_incre>SCREEN_HEIGHT) {
        if (randobs == 0) resetObstacle1();
        else if(randobs==1) resetObstacle2();
        else if(randobs==2) resetObstacle3();
        else if(randobs==3) resetObstacle4();
        else if(randobs==4) resetObstacle5();
        else if(randobs==5) resetObstacle6();
        pre_randobs=randobs;
        do {randobs = rand() % 6; } while (randobs == pre_randobs);
        score++;
        updateScore(score);
    }

    lastBirdY = birdY;
}
#endif
