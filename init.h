
#ifndef INIT_H
#define INIT_H
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include"definition.h"


using namespace std;

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
SDL_Texture* gBirdTexture = NULL;
SDL_Texture* gBackgroundTexture = NULL;
SDL_Texture* gFlyAnimationTexture=NULL;
SDL_Texture* gDotTexture=NULL;
SDL_Texture* gPipeTexture = NULL;
SDL_Texture* gColumnTexture=NULL;
// Bird
int birdY = 600;
int birdVelocityY = 0;
int lastBirdY;
int maxBirdY;
//Fly Animation
int FlyAnimationY;
bool ShowFlyAnimation=false;
int FlyAnimationTimer=0;

bool initGame() {

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

    gBackgroundTexture = IMG_LoadTexture(gRenderer, "background.png");
    gBirdTexture = IMG_LoadTexture(gRenderer, "beach-ball.png");
    gFlyAnimationTexture = IMG_LoadTexture(gRenderer, "fly-animation.png");
    gDotTexture=IMG_LoadTexture(gRenderer,"Dot.png");
    gPipeTexture=IMG_LoadTexture(gRenderer,"pipe.png");
    gColumnTexture=IMG_LoadTexture(gRenderer,"column.png");

    if (!gBackgroundTexture || !gBirdTexture || !gFlyAnimationTexture || !gDotTexture||!gPipeTexture) {
        cout << "Failed to load textures!" << endl;
        return false;
    }
    //bird position
    lastBirdY = birdY;
    maxBirdY = birdY;
    return true;
}

void closeGame() {
    SDL_DestroyTexture(gBackgroundTexture);
    SDL_DestroyTexture(gBirdTexture);
    SDL_DestroyTexture(gFlyAnimationTexture);
    SDL_DestroyTexture(gDotTexture);
    SDL_DestroyTexture(gPipeTexture);
    SDL_DestroyTexture(gColumnTexture);
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    SDL_Quit();
}

#endif
