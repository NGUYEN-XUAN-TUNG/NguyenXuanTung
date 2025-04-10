#ifndef RENDER_H
#define RENDER_H
#include "init.h"
#include"definition.h"
#include"ObstacleDot.h"
#include "ObstaclePipe.h"
void render(SDL_Event &event) {
    SDL_RenderClear(gRenderer);

    SDL_Rect BackgroundRect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_RenderCopy(gRenderer, gBackgroundTexture, NULL, &BackgroundRect);

    Obstacle2(gRenderer, centerX,centerY);
    Obstacle1(gRenderer);
    Obstacle3(gRenderer);
    Obstacle4(gRenderer);
    Obstacle5(gRenderer);
    Obstacle6(gRenderer);

    SDL_Rect PauseRect = {SCREEN_WIDTH-50,-2, 50, 50};
    SDL_RenderCopy(gRenderer, PausedTexture, NULL, &PauseRect);

    SDL_Rect BirdPos = {birdX, birdY, birdW, birdH};


    if(gameStarted)
    {
    SDL_RenderCopy(gRenderer, gBirdTexture, NULL, &BirdPos);

    if (ShowFlyAnimation) {
        SDL_Rect FlyAnimationPos = {FlyAnimationX, FlyAnimationY(), birdW, birdH};
        SDL_RenderCopy(gRenderer, gFlyAnimationTexture, NULL, &FlyAnimationPos);
    }
    SDL_RenderPresent(gRenderer);
    }

}

void renderinMenu(SDL_Event &event) {
    if (character_) {
        if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
            int x, y;
            SDL_GetMouseState(&x, &y);
            if (x >0 && x < 50 && y > 0&& y < 50) {
                character_ = false;
                menu_ = true;
            }

            // Sau này thêm chọn nhân vật tại đây
        }
        return;
    }

    SDL_Rect menurect = {0, 0, 500, 800};
    SDL_RenderCopy(gRenderer, MenuTexture, NULL, &menurect);
    SDL_RenderPresent(gRenderer);

    if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
        int x, y;
        SDL_GetMouseState(&x, &y);

        if (menu_) {
            if (x > 150 && x < 350 && y > 325 && y < 425) {
                menu_ = false;
                gameStarted = true;
            } else if (x > 150 && x < 350 && y > 445 && y < 545) {
                menu_ = false;
                character_ = true;
                gameStarted = false;
            }
        }
    }
}
void LoadCharacterSelectScreen() {
    SDL_Rect charBG = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_RenderCopy(gRenderer, SelectCharacterTexture, NULL, &charBG);

    SDL_Rect Back = {10, 10, 100, 50};
    SDL_RenderCopy(gRenderer, PausedTexture, NULL, &Back);

    SDL_RenderPresent(gRenderer);
}

void LoadStartButtonUp()
{
    SDL_Rect start = {150,325,200,100};
    SDL_RenderCopy(gRenderer, StartTexture, NULL, &start);
    SDL_RenderPresent(gRenderer);
}

void LoadStartButtonDown()
{
    SDL_Rect character = {150,445,200,100};
    SDL_RenderCopy(gRenderer, CharacterTexture, NULL, &character);
    SDL_RenderPresent(gRenderer);
}


//void LoadPausedScreen()
//{
//    SDL_Rect pause = {0,0,200,799};
//    SDL_RenderCopy(gRenderer, PausedScreenTexture, NULL, &pause);
//    SDL_RenderPresent(gRenderer);
//}

void LoadMenu() {
    if (character_) {
        LoadCharacterSelectScreen();
        return;
    }

    SDL_Rect menurect = {0, 0, 500, 800};
    SDL_RenderCopy(gRenderer, MenuTexture, NULL, &menurect);
    SDL_RenderPresent(gRenderer);

    int x, y;
    SDL_GetMouseState(&x, &y);

    if (x > 150 && x < 350 && y > 325 && y < 425) {
        LoadStartButtonUp(); // hover nút Start
    } else if (x > 150 && x < 350 && y > 445 && y < 545) {
        LoadStartButtonDown(); // hover nút Character
    }
}

void pausing()
{
    int x, y;
    SDL_GetMouseState(&x, &y);

    if (x > SCREEN_WIDTH-50&& x < SCREEN_WIDTH && y > 0 && y < 50)
    {
        if (paused_ == false)
        {
            paused_ = true;
            gameStarted = false;
        }
        else
        {
            paused_ = false;
            gameStarted = true;
        }
    }
}

#endif
