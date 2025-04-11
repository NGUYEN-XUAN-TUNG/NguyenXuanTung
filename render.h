#ifndef RENDER_H
#define RENDER_H
#include "init.h"
#include"definition.h"
#include"ObstacleDot.h"
#include "ObstaclePipe.h"
#include "gameover.h"
void updateScore(int score) {
    string scoreText = to_string(score);
    SDL_Color textColor = {255, 255, 255};
    SDL_Surface* textSurface = TTF_RenderText_Blended(gFont, scoreText.c_str(), textColor);
    scoreTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
    scoreRect = {SCREEN_WIDTH/2,20, textSurface->w, textSurface->h};
    SDL_FreeSurface(textSurface);
}
void resetAllObs(){
    resetObstacle1();
    resetObstacle2();
    resetObstacle3();
    resetObstacle4();
    resetObstacle5();
    resetObstacle6();
}
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
    { SDL_RenderCopy(gRenderer, birds[selectedCharacterIndex], NULL, &BirdPos);
    if (ShowFlyAnimation) {
        SDL_Rect FlyAnimationPos = {FlyAnimationX, FlyAnimationY(), birdW, birdH};
        SDL_RenderCopy(gRenderer, gFlyAnimationTexture, NULL, &FlyAnimationPos);
    }
    }else if (ready){SDL_RenderCopy(gRenderer, birds[selectedCharacterIndex], NULL, &BirdPos);}
    if(!gameStarted)updateScore(0);
    SDL_RenderCopy(gRenderer, scoreTexture, NULL, &scoreRect);
    SDL_RenderPresent(gRenderer);

}
void startNewGame(SDL_Event &e) {
    menu_ = false;
    character_ = false;
    ready = true;
    gameStarted = false;
    isover = false;
    score = 0;
    birdY = birdStart;
    birdVelocityY = 0;
    resetAllObs();
    render(e);
    playedDieSound = false;
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
                startNewGame(event);
            } else if (x > 150 && x < 350 && y > 445 && y < 545) {
                menu_ = false;
                character_ = true;
                gameStarted = false;
                isover=false;
            }
        }
    }}
    //lỗi escape :((( ko bt tại sao
void pausing(SDL_Event &e) {
    int x, y;
    SDL_GetMouseState(&x, &y);
    if ((x > SCREEN_WIDTH - 50&& y < 50)||(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)) {
       paused_ = !paused_;
       isplaying=!isplaying;

    }
}


#endif
