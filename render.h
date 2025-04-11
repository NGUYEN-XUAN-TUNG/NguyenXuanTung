#ifndef RENDER_H
#define RENDER_H
#include "init.h"
#include"definition.h"
#include"ObstacleDot.h"
#include "ObstaclePipe.h"
#include "gameover.h"
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

    SDL_Rect PauseRect = {SCREEN_WIDTH-50,0, 50, 50};
    SDL_RenderCopy(gRenderer, PausedTexture, NULL, &PauseRect);

    SDL_Rect BirdPos = {birdX, birdY, birdW, birdH};


    if(gameStarted)
    {
    SDL_RenderCopy(gRenderer, birds[selectedCharacterIndex], NULL, &BirdPos);

    if (ShowFlyAnimation) {
        SDL_Rect FlyAnimationPos = {FlyAnimationX, FlyAnimationY(), birdW, birdH};
        SDL_RenderCopy(gRenderer, gFlyAnimationTexture, NULL, &FlyAnimationPos);
    }
    SDL_RenderPresent(gRenderer);
    }

}
void LoadCharacterSelectScreen() {
    SDL_Rect charBG = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_RenderCopy(gRenderer, SelectCharacterTexture, NULL, &charBG);
    SDL_RenderPresent(gRenderer);
}
void LoadHomeButton(){
    SDL_Rect home = {SCREEN_WIDTH-75,0,75,75};
    SDL_RenderCopy(gRenderer, HomeTexture, NULL, &home);
    SDL_RenderPresent(gRenderer);
}
void LoadLeftButton(){
    SDL_Rect left = {-5,430,100,100};
    SDL_RenderCopy(gRenderer, LeftButtonTexture, NULL, &left);
    SDL_RenderPresent(gRenderer);
}
void LoadRightButton(){
    SDL_Rect right = {405,430,100,100};
    SDL_RenderCopy(gRenderer, RightButtonTexture, NULL, &right);
    SDL_RenderPresent(gRenderer);
}
void LoadStartButtonUp(){
    SDL_Rect start = {150,325,200,100};
    SDL_RenderCopy(gRenderer, StartTexture, NULL, &start);
    SDL_RenderPresent(gRenderer);
}
void LoadStartButtonDown(){
    SDL_Rect character = {150,445,200,100};
    SDL_RenderCopy(gRenderer, CharacterTexture, NULL, &character);
    SDL_RenderPresent(gRenderer);
}
void LoadMenu() {
    if (character_) {
        LoadCharacterSelectScreen();
        return;
    }
    SDL_Rect menurect = {0, 0, 500, 800};
    SDL_RenderCopy(gRenderer, MenuTexture, NULL, &menurect);

    int x, y;
    SDL_GetMouseState(&x, &y);

    if (x > 150 && x < 350 && y > 325 && y < 425) {
        LoadStartButtonUp();
    } else if (x > 150 && x < 350 && y > 445 && y < 545) {
        LoadStartButtonDown();
    }
    SDL_RenderPresent(gRenderer);
}
void renderCharacterSelection(SDL_Event &event) {
    SDL_RenderClear(gRenderer);
    SDL_RenderCopy(gRenderer, SelectCharacterTexture, NULL, NULL);

    SDL_Rect characterRect = {SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 - 40, 200, 200};
    SDL_RenderCopy(gRenderer, birds[selectedCharacterIndex], NULL, &characterRect);

    int x, y;
    SDL_GetMouseState(&x, &y);

     if (x > 0 && x < 100 && y > 430 && y < 530) {
        LoadLeftButton();
    } else if (x > 400 && x < 500&& y > 400&& y < 500) {
        LoadRightButton();
    } else if (x > SCREEN_WIDTH-75 && x < SCREEN_WIDTH&& y > 0&& y < 75) {
        LoadHomeButton();
    }

    if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
        if (x > 0 && x < 100 && y > 430 && y < 530) {
            selectedCharacterIndex = (selectedCharacterIndex - 1 + 6) % 6;
        }else if (x > 400 && x < 500&& y > 430&& y < 530){
            selectedCharacterIndex = (selectedCharacterIndex + 1) % 6;
        }
    }

    SDL_RenderPresent(gRenderer);
}
void renderinMenu(SDL_Event &event) {
    if (character_) {
    if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
        int x, y;
        SDL_GetMouseState(&x, &y);
        if (x > SCREEN_WIDTH-75&& x < SCREEN_WIDTH && y > 0 && y < 75) {
            character_ = false;
            menu_ = true;
            isover=false;
        }
    }
    renderCharacterSelection(event);
    return;
    }
    if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
        int x, y;
        SDL_GetMouseState(&x, &y);

        if (menu_) {
            if (x > 150 && x < 350 && y > 325 && y < 425) {
                startNewGame();
            } else if (x > 150 && x < 350 && y > 445 && y < 545) {
                menu_ = false;
                character_ = true;
                gameStarted = false;
                isover=false;
            }
        }
    }
}
void pausing() {
    int x, y;
    SDL_GetMouseState(&x, &y);
    if (x > SCREEN_WIDTH - 50 && y < 50) {
        paused_ = !paused_;
        gameStarted = !paused_;
    }
}


#endif
