#ifndef OBSTACLEDOT_H
#define OBSTACLEDOT_H
#include"init.h"
#include"definition.h"
#include<cmath>

struct Dot1 {
    float progress;
    int edgeIdx;
    float x,y;
};

//obs1
float squareOffsetY = -SQUARE_SIZE-200;
SDL_Point baseCorners[4] = {
    {125, 125}, {375, 125}, {375, 375}, {125, 375}
};
Dot1 dots[4] = {
    {0.0f, 0}, {0.0f, 1}, {0.0f, 2}, {0.0f, 3}
};
void moveDot1(Dot1& dot, SDL_Renderer* renderer) {
    int startIdx = dot.edgeIdx;
    int endIdx = (dot.edgeIdx + 1) % 4;

    SDL_Point startCorner = {baseCorners[startIdx].x, baseCorners[startIdx].y + (int)squareOffsetY};
    SDL_Point endCorner = {baseCorners[endIdx].x, baseCorners[endIdx].y + (int)squareOffsetY};

    dot.progress += SPEED / SQUARE_SIZE;
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
    squareOffsetY = -SQUARE_SIZE-50;  // Đặt lại vị trí obstacle lên trên màn hình

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
struct Dot2{
    float x,y;
    float angle;
    int size;
};
Dot2 circledots[6];
float circleOffSetY = -2 * RADIUS - 100;
    //initialize
void initializeDots(float centerX, float centerY) {
    for (int i = 0; i < 3; i++) {
        float angleOffset = i * (2 * PI / 3);
        circledots[i] = {angleOffset, centerX + RADIUS * cos(angleOffset), centerY + RADIUS * sin(angleOffset), DOT_SIZE};
        circledots[i + 3] = {angleOffset + PI / 3, centerX + RADIUS * cos(angleOffset + PI / 3), centerY + RADIUS * sin(angleOffset + PI / 3), OTHER_DOT_SIZE};
    }
}

void moveDot2(Dot2 &dot, float centerX, float centerY, float radius) {
    dot.angle += SPEED;
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
    circleOffSetY= -2*RADIUS-100; }

SDL_Rect getDotRect2(const Dot2& dot) {
    return {(int)dot.x, (int)dot.y, dot.size, dot.size};
}

#endif
