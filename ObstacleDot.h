#ifndef OBSTACLEDOT_H
#define OBSTACLEDOT_H
#include"init.h"

const int SQUARE_SIZE = 250;
const int DOT_SIZE = 40;
const float SPEED = 1.5f;
const float FALL_SPEED = 5.0f;

float squareOffsetY = -SQUARE_SIZE;
SDL_Point baseCorners[4] = {
    {125, 125}, {375, 125}, {375, 375}, {125, 375}
};

struct Dot {
    float progress;
    int edgeIdx;
    float x,y;
};

Dot dots[4] = {
    {0.0f, 0}, {0.0f, 1}, {0.0f, 2}, {0.0f, 3}
};
void moveDot(Dot& dot, SDL_Renderer* renderer) {
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
        moveDot(dots[i], renderer);
    }
}
void resetObstacle() {
    squareOffsetY = -SQUARE_SIZE;  // Đặt lại vị trí obstacle lên trên màn hình

    for (int i = 0; i < 4; i++) {
        dots[i].progress = 0.0f;
        dots[i].edgeIdx = i;
    }
}
// tính vị trí dot
SDL_Rect getDotRect(const Dot& dot) {
    int startIdx = dot.edgeIdx;
    int endIdx = (dot.edgeIdx + 1) % 4;

    SDL_Point startCorner = {baseCorners[startIdx].x, baseCorners[startIdx].y + (int)squareOffsetY};
    SDL_Point endCorner = {baseCorners[endIdx].x, baseCorners[endIdx].y + (int)squareOffsetY};

    float x = startCorner.x + (endCorner.x - startCorner.x) * dot.progress - DOT_SIZE / 2;
    float y = startCorner.y + (endCorner.y - startCorner.y) * dot.progress - DOT_SIZE / 2;

    return {(int)x, (int)y, DOT_SIZE, DOT_SIZE};
}
#endif
