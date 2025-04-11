#ifndef INIT_H
#define INIT_H
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <iostream>
#include<vector>
#include <fstream>
#include <sstream>
#include"definition.h"


using namespace std;
bool isover=false;
bool gameStarted = false;
bool menu_ = true;
bool paused_ = false;
bool character_ = false;
bool playedDieSound = false;
bool ready=false;
bool isplaying=true;

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
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

SDL_Texture* MenuTexture = NULL;
SDL_Texture* StartTexture = NULL;
SDL_Texture* CharacterTexture= NULL;
SDL_Texture* PausedTexture = NULL;
SDL_Texture* SelectCharacterTexture=NULL;
SDL_Texture* LeftButtonTexture=NULL;
SDL_Texture* RightButtonTexture=NULL;
SDL_Texture* HomeTexture = NULL;
SDL_Texture* GameoverTexture = NULL;
SDL_Texture* RestartButtonTexture = NULL;
SDL_Texture* scoreTexture=NULL;

vector<SDL_Texture*> birds(6);
int selectedCharacterIndex=0;

Mix_Chunk* gFlySound = NULL;
Mix_Chunk* gDieSound = NULL;
//Font
int score=0;
TTF_Font* gFont=NULL;
SDL_Rect scoreRect;
// Bird
int birdY = birdStart;
int birdVelocityY = 0;
int lastBirdY;
int maxBirdY;
//Fly Animation
int FlyAnimationY(){
    return birdY + birdH*3/4;
}
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
    if (TTF_Init() == -1) {
    cout << "SDl TTF Error: " << TTF_GetError()<<endl;
    return false;
    }


    gBackgroundTexture = IMG_LoadTexture(gRenderer, "background.png");
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

    MenuTexture = IMG_LoadTexture(gRenderer,"menu_.png");
    StartTexture = IMG_LoadTexture(gRenderer,"start_.png");
    CharacterTexture=IMG_LoadTexture(gRenderer,"character.png");
    PausedTexture = IMG_LoadTexture(gRenderer, "pause.png");
    SelectCharacterTexture=IMG_LoadTexture(gRenderer,"selectchar.png");
    LeftButtonTexture=IMG_LoadTexture(gRenderer, "left_button.png");
    RightButtonTexture=IMG_LoadTexture(gRenderer, "right_button.png");
    HomeTexture=IMG_LoadTexture(gRenderer,"home.png");
    GameoverTexture=IMG_LoadTexture(gRenderer,"gameover.png");
    RestartButtonTexture=IMG_LoadTexture(gRenderer,"restart.png");

    //load characters
    for( int i=0;i<6;i++){
        string path="bird"+to_string(i+1)+".png";
        birds[i]=IMG_LoadTexture(gRenderer,path.c_str());
        if (!birds[i]) {
            cout << "Failed to load birds texture: " << path << endl;
            return false;
        }
    }
    //sound
    gFlySound = Mix_LoadWAV("Fly.mp3");
    gDieSound = Mix_LoadWAV("Die.mp3");
    gFont=TTF_OpenFont("font.ttf",40);
    if (!gBackgroundTexture|| !gFlyAnimationTexture || !gDotTexture || !gPipeTexture ||
        !gColumnTexture || !gFlySound ||!gDieSound|| !MenuTexture || !StartTexture || !CharacterTexture || !PausedTexture ||
        !SelectCharacterTexture || birds.empty()||!LeftButtonTexture||!RightButtonTexture||!HomeTexture||
        !GameoverTexture||!RestartButtonTexture||gFont == nullptr) {
        cout << "Failed to load resources!" << endl;
        return false;
    }
    //bird position
    lastBirdY = birdY;
    maxBirdY = birdY;
    return true;
}

void closeGame() {
    SDL_DestroyTexture(gBackgroundTexture);
    SDL_DestroyTexture(gFlyAnimationTexture);
    SDL_DestroyTexture(gDotTexture);
    SDL_DestroyTexture(gPipeTexture);
    SDL_DestroyTexture(gColumnTexture);
    SDL_DestroyTexture(gGun_IncreTexture);
    SDL_DestroyTexture(gGun_DecreTexture);
    SDL_DestroyTexture(gBullet_IncreTexture);
    SDL_DestroyTexture(gBullet_DecreTexture);
    SDL_DestroyTexture(gBullet_Animation_IncreTexture);
    SDL_DestroyTexture(gBullet_Animation_DecreTexture);
    SDL_DestroyTexture(MenuTexture);
    SDL_DestroyTexture(StartTexture);
    SDL_DestroyTexture(CharacterTexture);
    SDL_DestroyTexture(PausedTexture);
    SDL_DestroyTexture(SelectCharacterTexture);
    SDL_DestroyTexture(RightButtonTexture);
    SDL_DestroyTexture(LeftButtonTexture);
    SDL_DestroyTexture(HomeTexture);
    SDL_DestroyTexture(GameoverTexture);
    SDL_DestroyTexture(RestartButtonTexture);

    for (int i = 0; i < 6; ++i) {
        SDL_DestroyTexture(birds[i]);
    }

    Mix_FreeChunk(gFlySound);
    Mix_FreeChunk(gDieSound);
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    SDL_Quit();
    Mix_Quit();
}


#endif
