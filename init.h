#ifndef INIT_H
#define INIT_H
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <iostream>
#include<vector>
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
//ob6
SDL_Texture* gGun_IncreTexture=NULL;
SDL_Texture* gGun_DecreTexture=NULL;
SDL_Texture* gBullet_IncreTexture=NULL;
SDL_Texture* gBullet_DecreTexture=NULL;
SDL_Texture* gBullet_Animation_IncreTexture=NULL;
SDL_Texture* gBullet_Animation_DecreTexture=NULL;

Mix_Chunk* gFlySound = NULL;
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

    gWindow = SDL_CreateWindow("Fly-up", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!gWindow) {
        cout << "SDL Window Error: " << SDL_GetError() << endl;
        return false;
    }

    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if (!gRenderer) {
        cout << "SDL Render Error: " << SDL_GetError() << endl;
        return false;
    }
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) {
        cout << "SDL Mixer Error: " << Mix_GetError()<<endl;
        return false;
    }


    gBackgroundTexture = IMG_LoadTexture(gRenderer, "background.png");
    gBirdTexture = IMG_LoadTexture(gRenderer, "beach-ball.png");
    gFlyAnimationTexture = IMG_LoadTexture(gRenderer, "fly-animation.png");
    gDotTexture=IMG_LoadTexture(gRenderer,"Dot.png");
    gPipeTexture=IMG_LoadTexture(gRenderer,"pipe.png");
    gColumnTexture=IMG_LoadTexture(gRenderer,"column.png");
    //ob6
    gGun_IncreTexture=IMG_LoadTexture(gRenderer,"gun_incre.png");
    gGun_DecreTexture=IMG_LoadTexture(gRenderer,"gun_decre.png");
    gBullet_IncreTexture=IMG_LoadTexture(gRenderer,"bullet_incre.png");
    gBullet_DecreTexture=IMG_LoadTexture(gRenderer,"bullet_decre.png");
    gBullet_Animation_IncreTexture=IMG_LoadTexture(gRenderer,"bullet_animation_incre.png");
    gBullet_Animation_DecreTexture=IMG_LoadTexture(gRenderer,"bullet_animation_decre.png");
    //sound
    gFlySound = Mix_LoadWAV("Fly.mp3");

    if (!gBackgroundTexture || !gBirdTexture || !gFlyAnimationTexture || !gDotTexture||!gPipeTexture||!gGun_IncreTexture
        ||!gGun_DecreTexture||!gBullet_IncreTexture||!gBullet_DecreTexture||!gBullet_Animation_IncreTexture||!gBullet_Animation_DecreTexture||!gFlySound) {
        cout << "Failed to load textures or Sound!" << endl;
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
    //ob6
    SDL_DestroyTexture(gGun_IncreTexture);
    SDL_DestroyTexture(gGun_DecreTexture);
    SDL_DestroyTexture(gBullet_IncreTexture);
    SDL_DestroyTexture(gBullet_DecreTexture);
    SDL_DestroyTexture(gBullet_Animation_IncreTexture);
    SDL_DestroyTexture(gBullet_Animation_DecreTexture);
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    Mix_FreeChunk(gFlySound);
    SDL_Quit();
    Mix_Quit();
}

#endif
