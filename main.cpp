#include <SDL.h>
#include <SDL_image.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
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
SDL_Texture* gCurrentObstacleTexture = NULL;\
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
    return (a.x < b.x + b.w && a.x + a.w > b.x && a.y < b.y + b.h && a.y + a.h > b.y);
}

bool init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "ERROR" << SDL_GetError() << std::endl;
        return false;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        cout << "ERROR" << IMG_GetError() << std::endl;
        return false;
    }
    gWindow = SDL_CreateWindow("Flappy Bird", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    return true;
}


void close() {
    SDL_DestroyTexture(gBirdTexture);
    SDL_DestroyTexture(gBackgroundTexture);
    SDL_DestroyTexture(gFlyAnimationTexture);
    for (int i = 0; i < NUMBER_OF_OBSTACLE; i++) {
        SDL_DestroyTexture(gObstacleTextures[i]);
    }
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    IMG_Quit();
    SDL_Quit();
}

SDL_Texture* loadTexture(const char* filename) {
    SDL_Surface* loadedSurface = IMG_Load(filename);
    if (!loadedSurface) {
        cout << "Failed to load image: " << IMG_GetError() << endl;
        return nullptr;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
    SDL_FreeSurface(loadedSurface);
    if (!texture) {
        cout << "Failed to create texture: " << SDL_GetError() << endl;
        return nullptr;
    }
    SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
    return texture;
}

void render() {
    SDL_RenderClear(gRenderer);

    SDL_Rect BackgroundRect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_RenderCopy(gRenderer, gBackgroundTexture, NULL, &BackgroundRect);

    SDL_Rect BirdPos = {birdX, birdY, 40, 40};
    SDL_RenderCopy(gRenderer, gBirdTexture, NULL, &BirdPos);

    if(ShowFlyAnimation){
    SDL_Rect FlyAnimationPos = {FlyAnimationX, FlyAnimationY, 40, 40};
    SDL_RenderCopy(gRenderer, gFlyAnimationTexture, NULL, &FlyAnimationPos);
    }

    int w, h;
    SDL_QueryTexture(gCurrentObstacleTexture, NULL, NULL, &w, &h);
    SDL_Rect obstacleScaled = {obstacleRect.x, obstacleRect.y, w, h};
    SDL_Point center = {w / 2, h / 2};
    SDL_RenderCopyEx(gRenderer, gCurrentObstacleTexture, NULL, &obstacleScaled, rotationAngle, &center, SDL_FLIP_NONE);
    rotationAngle += 1.5f;

    SDL_RenderPresent(gRenderer);
}

int main(int argc, char* args[]) {
    srand(time(0));
    if (!init()) {
        return -1;
    }

    gBackgroundTexture = loadTexture("background-night.png");
    gBirdTexture = loadTexture("beach-ball.png");
    gFlyAnimationTexture=loadTexture("fly-animation.png");
    gObstacleTextures[0] = loadTexture("obstacle 01.png");
    gObstacleTextures[1] = loadTexture("obstacle 02.png");
    gCurrentObstacleTexture = gObstacleTextures[rand() % 2];

    birdX = (SCREEN_WIDTH - 40) / 2;
    birdY = 600;
    lastBirdY = birdY;
    maxBirdY = birdY;

    int w, h;
    SDL_QueryTexture(gCurrentObstacleTexture, NULL, NULL, &w, &h);
    obstacleRect = {(SCREEN_WIDTH - w) / 2, -h, w, h};

    SDL_Event e;
    bool quit = false;

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) quit = true;
            if (e.type == SDL_MOUSEBUTTONDOWN) {
                birdVelocityY = JUMP_STRENGTH;
                ShowFlyAnimation=true;
                FlyAnimationTimer=10;
            }
        }

        birdVelocityY += GRAVITY;
        birdY += birdVelocityY;


        FlyAnimationX = birdX;
        FlyAnimationY = birdY + 40;
         if (FlyAnimationTimer > 0) {
            FlyAnimationTimer--;
        } else {
            ShowFlyAnimation = false;
        }

        int deltaY = lastBirdY - birdY;
        if (deltaY > 0 && birdY < maxBirdY) {
            maxBirdY = birdY;
            obstacleRect.y += deltaY;
        }

        if (birdY < CHECK_POINT) {
            birdY = CHECK_POINT;
            obstacleRect.y += OBSTACLE_SPEED;
        }

        if (birdY > SCREEN_HEIGHT) {
                birdY = SCREEN_HEIGHT-50;
               // cout << "Game Over!" << endl;
                //quit = true;
        }
        if (obstacleRect.y > SCREEN_HEIGHT) {
            gCurrentObstacleTexture = gObstacleTextures[rand() % NUMBER_OF_OBSTACLE];
            SDL_QueryTexture(gCurrentObstacleTexture, NULL, NULL, &w, &h);
            obstacleRect = {(SCREEN_WIDTH - w) / 2, -h, w, h};
            lastBirdY = birdY;
        }

        SDL_Rect birdRect = {birdX, birdY, 40, 40};
        SDL_Rect obstacleRectScaled = {obstacleRect.x, obstacleRect.y, w, h};
        if (CheckCollision(birdRect, obstacleRectScaled)) {
            cout << "Game Over!" << endl;
            quit = true;
        }

        lastBirdY = birdY;

        render();
        SDL_Delay(16);
    }

    close();
    return 0;
}
