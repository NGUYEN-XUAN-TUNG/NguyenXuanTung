#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
#include <cstdlib>
#include <ctime>

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 750;
const int GRAVITY = 1;
const int JUMP_STRENGTH=-15;

SDL_Window *gWindow = NULL;
SDL_Surface *gScreenSurface = NULL;
SDL_Surface *gFlappyBird = NULL;
SDL_Surface *gBird = NULL;
SDL_Surface *gPipe = NULL;

int birdX, birdY;
int birdVelocityY = 0;

void close() {
    SDL_FreeSurface(gFlappyBird);
    SDL_DestroyWindow(gWindow);
    IMG_Quit();
    SDL_Quit();
}

void render() {
    SDL_Rect stretchRect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
    SDL_BlitScaled(gFlappyBird, NULL, gScreenSurface, &stretchRect);

    SDL_Rect birdPos = { birdX, birdY, gBird->w, gBird->h };
    SDL_BlitSurface(gBird, NULL, gScreenSurface, &birdPos);

    SDL_UpdateWindowSurface(gWindow);
}


int main(int argc, char* argv[]) {
    srand(time(0));
    gWindow = SDL_CreateWindow("Flappy Bird", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    gScreenSurface = SDL_GetWindowSurface(gWindow);
    gFlappyBird = IMG_Load("background-night.png");
    gBird = IMG_Load("beach-ball.png");

    birdX = (SCREEN_WIDTH - gBird->w) / 2;
    birdY = (SCREEN_HEIGHT - gBird->h) / 2;

    return 0;
}
