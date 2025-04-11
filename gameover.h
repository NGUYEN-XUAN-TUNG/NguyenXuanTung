
#ifndef GAMEOVER_H
#define GAMEOVER_H
#include "init.h"
#include "definition.h"
#include "render.h"
int highscore;

int loadHighScore() {
    int hscore=0;
    ifstream file("highscore.txt");
    int score;
    while (file >> score) {
        if (score > hscore) {
            hscore = score;
        }
    }
    file.close();
    return hscore;
}
void saveScore(int score) {
    ofstream file("highscore.txt", ios::app);
    if (file.is_open()) {
        file << score <<endl;
        file.close();
    }
}

void renderCenteredText(SDL_Renderer* renderer, TTF_Font* font, const string& text, int centerX, int y, SDL_Color color) {
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    int textWidth = surface->w;
    SDL_Rect dstRect = { centerX - textWidth / 2, y, textWidth, surface->h };

    SDL_RenderCopy(renderer, texture, nullptr, &dstRect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}
void showScoreScreen(SDL_Renderer* renderer, TTF_Font* font, int score, int highScore) {
    SDL_Color textColor = {0, 0, 0};
    int centerX = 250;
    int startY = 350;
        stringstream hs, ys;
        hs << "High Score: " << highScore;
        ys << "Your Score: " << score;
        renderCenteredText(renderer, font, hs.str(), centerX, startY, textColor);
        renderCenteredText(renderer, font, ys.str(), centerX, startY + 50, textColor);

}

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
    showScoreScreen(gRenderer,gFont,score,highscore);
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
            startNewGame(event);
        }else if( x > 275 && x < 425 && y > 560 && y < 710 ){
            menu_ = true;
            character_ = false;
            gameStarted = false;
        }
    }
    SDL_RenderPresent(gRenderer);

}


#endif
