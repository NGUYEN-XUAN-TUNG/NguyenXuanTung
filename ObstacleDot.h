#ifndef OBSTACLEDOT_H
#define OBSTACLEDOT_H
#include"init.h"
#include"definition.h"
    //obs 1: line 14;   square
    //obs 2: line 70;   circle
    //obs 6: line 117;  gun

struct Dot1 {
    float progress;
    int edgeIdx;
};

//obs1
float squareOffsetY = Y_START_DOT;
SDL_Point baseCorners[4] = {
    {BASE_X1, BASE_Y1}, {BASE_X2, BASE_Y1}, {BASE_X2, BASE_Y2}, {BASE_X1, BASE_Y2}
};
Dot1 dots[4] = {
    {0.0f, 0}, {0.0f, 1}, {0.0f, 2}, {0.0f, 3}
};

void moveDot1(Dot1& dot, SDL_Renderer* renderer) {
    int startIdx = dot.edgeIdx;
    int endIdx = (dot.edgeIdx + 1) % 4;

    SDL_Point startCorner = {baseCorners[startIdx].x, baseCorners[startIdx].y + (int)squareOffsetY};
    SDL_Point endCorner = {baseCorners[endIdx].x, baseCorners[endIdx].y + (int)squareOffsetY};

    dot.progress += SPEED_SQUARE / SQUARE_SIZE;
    if (dot.progress >= 1.0f) {
        dot.progress = 0.0f;
        dot.edgeIdx = (dot.edgeIdx + 1) % 4;
    }

    float x = startCorner.x + (endCorner.x - startCorner.x) * dot.progress - DOT_SIZE / 2;
    float y = startCorner.y + (endCorner.y - startCorner.y) * dot.progress - DOT_SIZE / 2;

    SDL_Rect dotRect = {(int)x, (int)y, DOT_SIZE, DOT_SIZE};
    SDL_RenderCopy(renderer, gDotTexture, nullptr, &dotRect);
}

void Obstacle1(SDL_Renderer* renderer) {
    for (int i = 0; i < 4; i++) {
        moveDot1(dots[i], renderer);
    }
}

void resetObstacle1() {
    squareOffsetY = Y_START_DOT;  // Đặt lại vị trí obstacle lên trên màn hình

    for (int i = 0; i < 4; i++) {
        dots[i].progress = 0.0f;
        dots[i].edgeIdx = i;
    }
}
// tính vị trí dot
SDL_Rect getDotRect1(const Dot1& dot) {
    int startIdx = dot.edgeIdx;
    int endIdx = (dot.edgeIdx + 1) % 4;

    SDL_Point startCorner = {baseCorners[startIdx].x, baseCorners[startIdx].y + (int)squareOffsetY};
    SDL_Point endCorner = {baseCorners[endIdx].x, baseCorners[endIdx].y + (int)squareOffsetY};

    float x = startCorner.x + (endCorner.x - startCorner.x) * dot.progress - DOT_SIZE / 2;
    float y = startCorner.y + (endCorner.y - startCorner.y) * dot.progress - DOT_SIZE / 2;

    return {(int)x, (int)y, DOT_SIZE, DOT_SIZE};
}
//obs2
const float centerX = SCREEN_WIDTH / 2;
const float centerY = -95   ;

struct Dot2{
    float x,y;
    float angle;
    int size;
};
Dot2 circledots[6];
float circleOffSetY =-75;

void initializeDots(float centerX, float centerY) {
    for (int i = 0; i < 3; i++) {
        float angleOffset = i * (2 * PI / 3);
        circledots[i] = {centerX + RADIUS * cos(angleOffset), centerY + RADIUS * sin(angleOffset), angleOffset, DOT_SIZE};
        circledots[i + 3] = {centerX + RADIUS * cos(angleOffset + PI / 3), centerY + RADIUS * sin(angleOffset + PI / 3), angleOffset + PI / 3, OTHER_DOT_SIZE};
    }
}

void moveDot2(Dot2 &dot, float centerX, float centerY, float radius) {
    dot.angle += SPEED_CIRCLE;

    if (dot.angle >= 2 * PI) {
        dot.angle -= 2 * PI;
    }

    dot.x = centerX + radius * cos(dot.angle) - dot.size / 2;
    dot.y = centerY + radius * sin(dot.angle) - dot.size / 2 + circleOffSetY;
}

void Obstacle2(SDL_Renderer *renderer, float centerX, float centerY) {
    for (int i = 0; i < 6; i++) {
        moveDot2(circledots[i], centerX, centerY, RADIUS);
        SDL_Rect dotRect = {(int)circledots[i].x, (int)circledots[i].y, circledots[i].size, circledots[i].size};
        SDL_RenderCopy(renderer, gDotTexture, nullptr, &dotRect);
    }
}

void resetObstacle2() {
    circleOffSetY= -75;
    }
SDL_Rect getDotRect2(const Dot2& dot) {
    return {(int)dot.x, (int)dot.y, dot.size, dot.size};
}

//gun
int y_gun_incre=Y_START_GUN;
int y_gun_decre(){
    return y_gun_incre+100;
}
int x_bullet_incre=300;
int y_bullet_incre(){
    return y_gun_incre+5;
}
//bullet
int x_bullet_decre(){
    return SCREEN_WIDTH-x_bullet_incre;
}
int y_bullet_decre(){
    return y_gun_incre+106;
}
//ANIMATION OF BULLET
int x_bullet_animation_incre(){
    return x_bullet_incre-BULLET_WIDTH-15;
}
int y_bullet_animation_incre(){
    return y_bullet_incre();
}
int x_bullet_animation_decre(){
    return x_bullet_decre()+BULLET_WIDTH+4;
}
int y_bullet_animation_decre(){
    return y_bullet_decre();
}
void Obstacle6(SDL_Renderer* renderer){
    //bullet
    SDL_Rect bullet_incre = {x_bullet_incre,y_bullet_incre(), BULLET_WIDTH, BULLET_HEIGHT};
    SDL_RenderCopy(renderer, gBullet_IncreTexture, nullptr, &bullet_incre);

    SDL_Rect bullet_decre = {x_bullet_decre(),y_bullet_decre(), BULLET_WIDTH, BULLET_HEIGHT};
    SDL_RenderCopy(renderer, gBullet_DecreTexture, nullptr, &bullet_decre);
    //animation
    SDL_Rect bullet_animation_incre = {x_bullet_animation_incre(),y_bullet_animation_incre(), BULLET_ANIMATION_WIDTH, BULLET_ANIMATION_HEIGHT};
    SDL_RenderCopy(renderer, gBullet_Animation_IncreTexture, nullptr, &bullet_animation_incre);

    SDL_Rect bullet_animation_decre = {x_bullet_animation_decre(),y_bullet_animation_decre(), BULLET_ANIMATION_WIDTH, BULLET_ANIMATION_HEIGHT};
    SDL_RenderCopy(renderer, gBullet_Animation_DecreTexture, nullptr, &bullet_animation_decre);
    //gun
    SDL_Rect gun_incre = {0,y_gun_incre, GUN_WIDTH, GUN_HEIGHT};
    SDL_RenderCopy(renderer, gGun_IncreTexture, nullptr, &gun_incre);

    SDL_Rect gun_decre = {SCREEN_WIDTH-GUN_WIDTH,y_gun_decre(), GUN_WIDTH, GUN_HEIGHT};
    SDL_RenderCopy(renderer, gGun_DecreTexture, nullptr, &gun_decre);

    x_bullet_incre+=BULLET_SPEED;
    if(x_bullet_incre>SCREEN_WIDTH) x_bullet_incre=0;

}
vector<SDL_Rect> getBulletRect6() {
    vector<SDL_Rect> bullets;
    bullets.push_back({x_bullet_incre,y_bullet_incre(), BULLET_WIDTH, BULLET_HEIGHT});
    bullets.push_back({x_bullet_decre(),y_bullet_decre(), BULLET_WIDTH, BULLET_HEIGHT});
    return bullets;
}
void resetObstacle6(){
    y_gun_incre=Y_START_GUN;
}
#endif
