#ifndef DEFINITION_H
#define DEFINITION_H
#include<cmath>
//init
const int SCREEN_WIDTH = 500;
const int SCREEN_HEIGHT = 800;
const int GRAVITY = 1;
const int JUMP_STRENGTH = -15;
const int CHECK_POINT = SCREEN_HEIGHT / 2 - 100;
const float FALL_SPEED = 7.0f;
const float FALL_SPEED_FIRST=9.0f;
//Bird
const int birdW=40;
const int birdH=40;
const int birdX = (SCREEN_WIDTH - birdW) / 2;
const int birdStart=600;
//Fly animation
const int FlyAnimationX = birdX;
//obs1 - Dot
const int SQUARE_SIZE = 250;
const int DOT_SIZE = 40;
const float SPEED_SQUARE = 3.0f;
const int BASE_X1=125;
const int BASE_Y1=125;
const int BASE_X2=125+SQUARE_SIZE;
const int BASE_Y2=125+SQUARE_SIZE;

const int Y_START_DOT=-400;
//obs2 - Dot
const float RADIUS=150;
const float SPEED_CIRCLE=0.02f;
const int OTHER_DOT_SIZE=20;
const float PI=3.14159f;
//ob3 - Pipe
const int PIPE_WIDTH = 200;
const int PIPE_HEIGHT = 20;
const int PIPE_GAP = 350;
const int PIPE_SPEED = 3;
const int Y_START_PIPE = -230;
const int SPACE_PIPE = 200;
const int PIPE_Y_POSITION = 500;
//obs 4:
const int COLUMN_HEIGHT_MAX=200;
const int COLUMN_HEIGHT_MIN=100;
const int COLUMN_WIDTH_MAX=20;
const int COLUMN_WIDTH_MIN=10;
const int COLUMN_SPEED=2;
const int Y_START_COLUMN=-200;
//obs 5:
const int O5_PIPE_HEIGHT=25;
const int O5_PIPE_WIDTH=100;
const float O5_SPEED=9;
const int O5_SPACE_LINE=75;
const int O5_Y_START=-175;
//ob6 - gun;
const int GUN_HEIGHT=60;
const int GUN_WIDTH=80;
const int BULLET_WIDTH=30;
const int BULLET_HEIGHT=12;
const int BULLET_ANIMATION_WIDTH=40;
const int BULLET_ANIMATION_HEIGHT=10;
const int BULLET_SPEED=8;
const int Y_START_GUN=-150;
//CheckCollision
bool CheckCollisionRect(SDL_Rect a, SDL_Rect b) {
    return (a.x < b.x + b.w && a.x + a.w > b.x &&
            a.y < b.y + b.h && a.y + a.h > b.y);
}
bool CheckCollisionCircle(SDL_Rect a, SDL_Rect b) {
    float x1=a.x+a.w/2.0;
    float y1=a.y+a.h/2.0;
    float x2=b.x+b.w/2.0;
    float y2=b.y+b.h/2.0;
    float dis=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    return dis<a.w/2.0+b.w/2.0;
}

#endif
