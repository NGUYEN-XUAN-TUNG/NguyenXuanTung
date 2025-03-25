#include <SDL.h>
#include <SDL_image.h>
#include <cstdlib>
#include <ctime>

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 750;

SDL_Window *gWindow = NULL;
SDL_Surface *gScreenSurface = NULL;
SDL_Surface *gFlappyBird = NULL;
SDL_Surface *gBird = NULL;
SDL_Surface *gPipe = NULL;

void close() {
    SDL_FreeSurface(gFlappyBird);
    SDL_DestroyWindow(gWindow);
    IMG_Quit();
    SDL_Quit();
}
int main(int argc, char* argv[]) {
    srand(time(0));
    gWindow = SDL_CreateWindow("beach-ball", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    gScreenSurface = SDL_GetWindowSurface(gWindow);

    return 0;
}
