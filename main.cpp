#include <SDL.h>
#include <SDL_image.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

const int SCREEN_WIDTH = 500;
const int SCREEN_HEIGHT = 800;
const int GRAVITY = 1;
const int JUMP_STRENGTH = -15;
const int OBSTACLE_SPEED = 1.5;



SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
SDL_Texture* gBirdTexture = NULL;
SDL_Texture* gBackgroundTexture = NULL;
SDL_Texture* gObstacleTexture = NULL;

// Bird
int birdX, birdY;
int birdVelocityY = 0;

// Obstacle
SDL_Rect obstacleRect;
float rotationAngle = 0.0f;
bool obstacleFalling = false; // Khi bird bay lên, obstacle mới bắt đầu rơi

void close() {
    SDL_DestroyTexture(gBirdTexture);
    SDL_DestroyTexture(gBackgroundTexture);
    SDL_DestroyTexture(gObstacleTexture);
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    IMG_Quit();
    SDL_Quit();
}

SDL_Texture* loadTexture(const char* filename) {
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);
    SDL_Texture* texture = IMG_LoadTexture(gRenderer, filename);
    return texture;
}

void render() {
    SDL_RenderClear(gRenderer);

    SDL_Rect BackgroundRect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
    SDL_RenderCopy(gRenderer, gBackgroundTexture, NULL, &BackgroundRect);

    SDL_Rect BirdPos = { birdX, birdY, 45, 45 };
    SDL_RenderCopy(gRenderer, gBirdTexture, NULL, &BirdPos);

    int w, h;
    SDL_QueryTexture(gObstacleTexture, NULL, NULL, &w, &h);
    SDL_Rect obstacleScaled = { obstacleRect.x, obstacleRect.y, w, h };
    SDL_Point center = { w / 2, h / 2 };
    SDL_RenderCopyEx(gRenderer, gObstacleTexture, NULL, &obstacleScaled, rotationAngle, &center, SDL_FLIP_NONE);
    rotationAngle += 2.0f;

    SDL_RenderPresent(gRenderer);
}

int main(int argc, char* args[]) {
    srand(time(0));

    gWindow = SDL_CreateWindow("Flappy Bird", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);

    gBackgroundTexture = loadTexture("background-night.png");
    gBirdTexture = loadTexture("beach-ball.png");
    gObstacleTexture = loadTexture("obstacle 01.png");

    birdX = (SCREEN_WIDTH - 45) / 2;
    birdY = SCREEN_HEIGHT / 2;

    int w, h;
    SDL_QueryTexture(gObstacleTexture, NULL, NULL, &w, &h);
    obstacleRect = { (SCREEN_WIDTH - w) / 2, -10, w, h };

    SDL_Event e;
    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) quit = true;
            if (e.type == SDL_MOUSEBUTTONDOWN) {
                birdVelocityY = JUMP_STRENGTH;
                obstacleFalling = true;
            }
        }

        birdVelocityY += GRAVITY;
        birdY += birdVelocityY;

        if (birdY > SCREEN_HEIGHT) quit = true;

        if (obstacleFalling) {
            obstacleRect.y += OBSTACLE_SPEED;
        }

        render();
        SDL_Delay(16);
    }

    close();
    return 0;
}
