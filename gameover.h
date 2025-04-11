#ifndef GAMEOVER_H
#define GAMEOVER_H
#include "init.h"
#include "definition.h"
#include "render.h"
void LoadHome(){
    SDL_Rect home = {275,560,150,150};
    SDL_RenderCopy(gRenderer, HomeTexture, NULL, &home);
    SDL_RenderPresent(gRenderer);
}
void LoadRestartButoon(){
    SDL_Rect right = {110,560,150,150};
    SDL_RenderCopy(gRenderer, RestartButtonTexture, NULL, &right);
    SDL_RenderPresent(gRenderer);
}
void LoadGameover(){
    if(menu_){
        LoadMenu();
        return;
    }
    SDL_Rect bgGameover={0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_RenderCopy(gRenderer,GameoverTexture,NULL,&bgGameover);
    int x, y;
    SDL_GetMouseState(&x, &y);
    if( x > 110 && x < 260 && y > 560 && y < 710 ){
        LoadRestartButoon();
    }else if( x > 275 && x < 425 && y > 560 && y < 710 ){
        LoadHome();
    }
    SDL_RenderPresent(gRenderer);
}
void renderinGameover(SDL_Event &event){
    if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
        int x, y;
        SDL_GetMouseState(&x, &y);
        if( x > 110 && x < 260 && y > 560 && y < 710 ) {
            startNewGame();
        }else if( x > 275 && x < 425 && y > 560 && y < 710 ){
            menu_ = true;
            character_ = false;
            gameStarted = false;
        }
    }
    SDL_RenderPresent(gRenderer);

}


#endif
