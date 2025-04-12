
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
void showScoreScreen(SDL_Renderer* renderer, TTF_Font* font, int score, int highscore) {
    SDL_Color textColor = {0, 0, 0};
    string hs = "High Score: " + to_string(highscore);
    string ys = "Your Score: " + to_string(score);

    SDL_Surface* hsSurface = TTF_RenderText_Solid(font, hs.c_str(), textColor);
    SDL_Texture* hsTexture = SDL_CreateTextureFromSurface(renderer, hsSurface);
    int hsWidth = hsSurface->w;
    SDL_Rect hsRect = { (SCREEN_WIDTH - hsWidth) / 2, 350, hsSurface->w, hsSurface->h };
    SDL_RenderCopy(renderer, hsTexture, nullptr, &hsRect);
    SDL_FreeSurface(hsSurface);
    SDL_DestroyTexture(hsTexture);

    SDL_Surface* ysSurface = TTF_RenderText_Solid(font, ys.c_str(), textColor);
    SDL_Texture* ysTexture = SDL_CreateTextureFromSurface(renderer, ysSurface);
    int ysWidth = ysSurface->w;
    SDL_Rect ysRect = { (SCREEN_WIDTH - ysWidth) / 2, 350 + 50, ysSurface->w, ysSurface->h };
    SDL_RenderCopy(renderer, ysTexture, nullptr, &ysRect);
    SDL_FreeSurface(ysSurface);
    SDL_DestroyTexture(ysTexture);
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
