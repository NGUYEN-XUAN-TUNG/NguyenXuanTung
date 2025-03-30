#ifndef INIT_H
#define INIT_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SCREEN_WIDTH = 500;
const int SCREEN_HEIGHT = 800;
const int GRAVITY = 1;
const int JUMP_STRENGTH = -15;
const int CHECK_POINT = SCREEN_HEIGHT / 2 - 100;
const int OBSTACLE_SPEED = 5;
const int NUMBER_OF_OBSTACLE = 2;

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
SDL_Texture* gBirdTexture = NULL;
SDL_Texture* gBackgroundTexture = NULL;
SDL_Texture* gObstacleTextures[NUMBER_OF_OBSTACLE];
SDL_Texture* gCurrentObstacleTexture = NULL;
SDL_Texture* gFlyAnimationTexture=NULL;

// Bird
int birdX, birdY;
int birdVelocityY = 0;
int lastBirdY;
int maxBirdY;

//Fly Animation
int FlyAnimationX,FlyAnimationY;
bool ShowFlyAnimation=false;
int FlyAnimationTimer=0;

// Obstacle
SDL_Rect obstacleRect;
float rotationAngle = 0.0f;

bool CheckCollision(SDL_Rect a, SDL_Rect b) {
    return (a.x < b.x + b.w && a.x + a.w > b.x &&
            a.y < b.y + b.h && a.y + a.h > b.y);
}

bool initGame() {
    srand(time(0));

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL Init Error: " << SDL_GetError() << endl;
        return false;
    }

    gWindow = SDL_CreateWindow("Flappy Bird", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!gWindow) {
        cout << "SDL Window Error: " << SDL_GetError() << endl;
        return false;
    }

    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if (!gRenderer) {
        cout << "SDL Render Error: " << SDL_GetError() << endl;
        return false;
    }

    gBackgroundTexture = IMG_LoadTexture(gRenderer, "background-night.png");
    gBirdTexture = IMG_LoadTexture(gRenderer, "beach-ball.png");
    gFlyAnimationTexture = IMG_LoadTexture(gRenderer, "fly-animation.png");
    gObstacleTextures[0] = IMG_LoadTexture(gRenderer, "obstacle 01.png");
    gObstacleTextures[1] = IMG_LoadTexture(gRenderer, "obstacle 02.png");

    if (!gBackgroundTexture || !gBirdTexture || !gFlyAnimationTexture || !gObstacleTextures[0] || !gObstacleTextures[1]) {
        cout << "Failed to load textures!" << endl;
        return false;
    }

    gCurrentObstacleTexture = gObstacleTextures[rand() % NUMBER_OF_OBSTACLE];

    //bird position
    birdX = (SCREEN_WIDTH - 40) / 2;
    birdY = 600;
    lastBirdY = birdY;
    maxBirdY = birdY;

    int w, h;
    SDL_QueryTexture(gCurrentObstacleTexture, NULL, NULL, &w, &h);
    obstacleRect = {(SCREEN_WIDTH - w) / 2, -h, w, h};

    return true;
}

void closeGame() {
    SDL_DestroyTexture(gBackgroundTexture);
    SDL_DestroyTexture(gBirdTexture);
    SDL_DestroyTexture(gFlyAnimationTexture);
    SDL_DestroyTexture(gObstacleTextures[0]);
    SDL_DestroyTexture(gObstacleTextures[1]);
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    SDL_Quit();
}

#endif
