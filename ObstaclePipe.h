#ifndef OBSTACLEPIPE_H
#define OBSTACLEPIPE_H
#include "init.h"
#include "definition.h"
//ob3 - Pipe
const int PIPE_WIDTH = 200;
const int PIPE_HEIGHT = 20;
const int PIPE_GAP = 350;
const int PIPE_SPEED = 3;
const int Y_START_PIPE = -230;
const int SPACE_PIPE = 200;
const int PIPE_Y_POSITION = 500;
//initial  pos  pipe;  |===|    |===|
int x1 = SCREEN_WIDTH;
int x2 = x1 + PIPE_GAP;
int x3 =-PIPE_WIDTH;
int x4 = x3 -PIPE_GAP;
int yTop = Y_START_PIPE;
int yBottom(){
    return yTop + SPACE_PIPE;
    }
void Obstacle3(SDL_Renderer* renderer) {

    SDL_Rect pipe1 = {x1, yTop, PIPE_WIDTH, PIPE_HEIGHT};
    SDL_RenderCopy(renderer, gPipeTexture, nullptr, &pipe1);

    SDL_Rect pipe2 = {x2, yTop, PIPE_WIDTH, PIPE_HEIGHT};
    SDL_RenderCopy(renderer, gPipeTexture, nullptr, &pipe2);

    SDL_Rect pipe3 = {x3, yBottom(), PIPE_WIDTH, PIPE_HEIGHT};
    SDL_RenderCopy(renderer, gPipeTexture, nullptr, &pipe3);

    SDL_Rect pipe4 = {x4, yBottom(), PIPE_WIDTH, PIPE_HEIGHT};
    SDL_RenderCopy(renderer, gPipeTexture, nullptr, &pipe4);

    x1 -= PIPE_SPEED;
    x2 -= PIPE_SPEED;
    x3 += PIPE_SPEED;
    x4 += PIPE_SPEED;

    if (x1 + PIPE_WIDTH <= 0) x1 = SCREEN_WIDTH;
    if (x2 + PIPE_WIDTH <= 0) x2 = SCREEN_WIDTH;
    if (x3 >=SCREEN_WIDTH)  x3=-PIPE_WIDTH;
    if (x4 >=SCREEN_WIDTH)  x4=-PIPE_WIDTH;
}
vector<SDL_Rect> getPipeRect3() {
    vector<SDL_Rect> pipes;
    pipes.push_back({x1, yTop, PIPE_WIDTH, PIPE_HEIGHT});
    pipes.push_back({x2, yTop, PIPE_WIDTH, PIPE_HEIGHT});
    pipes.push_back({x3, yBottom(), PIPE_WIDTH, PIPE_HEIGHT});
    pipes.push_back({x4, yBottom(), PIPE_WIDTH, PIPE_HEIGHT});
    return pipes;
}
void resetObstacle3(){
    yTop = Y_START_PIPE;
}

#endif
