#ifndef OBSTACLEPIPE_H
#define OBSTACLEPIPE_H
#include "init.h"
#include "definition.h"
        //obs 3: line 8;    pipe
        //obs 4: line 52;   column
        //obs 5: line 105;  3 lines of pipes
//obs3
int x1 = SCREEN_WIDTH;
int x2 = x1 + PIPE_GAP;
int x3 =-PIPE_WIDTH;
int x4 = x3 -PIPE_GAP;
int yTop = Y_START_PIPE;
int yBottom(){
    return yTop + SPACE_PIPE;
    }
void Obstacle3(SDL_Renderer* renderer) {

    SDL_Rect pipe1 = {x1, yTop, PIPE_WIDTH, PIPE_HEIGHT};
    SDL_RenderCopy(renderer, gPipeTexture, nullptr, &pipe1);

    SDL_Rect pipe2 = {x2, yTop, PIPE_WIDTH, PIPE_HEIGHT};
    SDL_RenderCopy(renderer, gPipeTexture, nullptr, &pipe2);

    SDL_Rect pipe3 = {x3, yBottom(), PIPE_WIDTH, PIPE_HEIGHT};
    SDL_RenderCopy(renderer, gPipeTexture, nullptr, &pipe3);

    SDL_Rect pipe4 = {x4, yBottom(), PIPE_WIDTH, PIPE_HEIGHT};
    SDL_RenderCopy(renderer, gPipeTexture, nullptr, &pipe4);

    x1 -= PIPE_SPEED;
    x2 -= PIPE_SPEED;
    x3 += PIPE_SPEED;
    x4 += PIPE_SPEED;

    if (x1 + PIPE_WIDTH <= 0) x1 = SCREEN_WIDTH;
    if (x2 + PIPE_WIDTH <= 0) x2 = SCREEN_WIDTH;
    if (x3 >=SCREEN_WIDTH)  x3=-PIPE_WIDTH;
    if (x4 >=SCREEN_WIDTH)  x4=-PIPE_WIDTH;
}
vector<SDL_Rect> getPipeRect3() {
    vector<SDL_Rect> pipes;
    pipes.push_back({x1, yTop, PIPE_WIDTH, PIPE_HEIGHT});
    pipes.push_back({x2, yTop, PIPE_WIDTH, PIPE_HEIGHT});
    pipes.push_back({x3, yBottom(), PIPE_WIDTH, PIPE_HEIGHT});
    pipes.push_back({x4, yBottom(), PIPE_WIDTH, PIPE_HEIGHT});
    return pipes;
}
void resetObstacle3(){
    if(yTop>SCREEN_WIDTH)yTop = Y_START_PIPE;
}
//Initialize obs 4
bool obs4positive=true;
bool obs4negative=false;
int x1_=0;
int x2_(){
    return SCREEN_WIDTH/2-x1_;
}
int x3_=SCREEN_WIDTH-COLUMN_WIDTH_MIN;
int x4_(){
    return SCREEN_WIDTH/2 +(SCREEN_WIDTH-x3_);
}
int y1_=Y_START_COLUMN;
int y2_(){
 return y1_+COLUMN_HEIGHT_MIN/2;
}
void Obstacle4(SDL_Renderer* renderer) {

    SDL_Rect column1 = {x1_, y2_(), COLUMN_WIDTH_MIN, COLUMN_HEIGHT_MIN};
    SDL_RenderCopy(renderer, gColumnTexture, nullptr, &column1);

    SDL_Rect column2 = {x2_(),y1_ , COLUMN_WIDTH_MAX, COLUMN_HEIGHT_MAX};
    SDL_RenderCopy(renderer, gColumnTexture, nullptr, &column2);

    SDL_Rect column3 = {x3_, y2_(), COLUMN_WIDTH_MIN, COLUMN_HEIGHT_MIN};
    SDL_RenderCopy(renderer, gColumnTexture, nullptr, &column3);

    SDL_Rect column4 = {x4_(), y1_, COLUMN_WIDTH_MAX, COLUMN_HEIGHT_MAX};
    SDL_RenderCopy(renderer, gColumnTexture, nullptr, &column4);

    if(obs4positive){
    x1_ += COLUMN_SPEED;
    x3_ -= COLUMN_SPEED;
    }
    if(x1_==SCREEN_WIDTH/2-COLUMN_WIDTH_MIN){obs4negative=true;obs4positive=false;}
    if(x1_==0){obs4negative=false;obs4positive=true;}
    if(obs4negative){
    x1_ -= COLUMN_SPEED;
    x3_ += COLUMN_SPEED;
    }

}
vector<SDL_Rect> getColumnRect4() {
    vector<SDL_Rect> columns;
    columns.push_back({x1_, y2_(), COLUMN_WIDTH_MIN, COLUMN_HEIGHT_MIN});
    columns.push_back({x2_(), y1_, COLUMN_WIDTH_MAX, COLUMN_HEIGHT_MAX});
    columns.push_back({x3_, y2_(), COLUMN_WIDTH_MIN, COLUMN_HEIGHT_MIN});
    columns.push_back({x4_(), y1_, COLUMN_WIDTH_MAX, COLUMN_HEIGHT_MAX});

    return columns;
}
void resetObstacle4(){
    y1_=Y_START_COLUMN;
}
//obs 5:
const int O5_PIPE_HEIGHT=25;
const int O5_PIPE_WIDTH=100;
const float O5_SPEED=7;
const int O5_SPACE_LINE=75;
const int O5_Y_START=-175;

//Obs 5:
Uint32 o5pauseTimer_line1 = 0;
bool o5isPaused_line1 = false;

Uint32 o5pauseTimer_line2 = 0;
bool o5isPaused_line2 = false;

Uint32 o5pauseTimer_line3 = 0;
bool o5isPaused_line3 = false;

bool o5positive_line1 = false;
bool o5negative_line1 = true;

bool o5positive_line2 = false;
bool o5negative_line2 = true;

bool o5positive_line3 = false;
bool o5negative_line3 = true;
    // 3 lines for pipes
int o5x1_line1 = 150;
int o5x1_line2 = 150;
int o5x1_line3 = 150;

int o5x2_line1() { return SCREEN_WIDTH - o5x1_line1 - O5_PIPE_WIDTH; }
int o5x2_line2() { return SCREEN_WIDTH - o5x1_line2 - O5_PIPE_WIDTH; }
int o5x2_line3() { return SCREEN_WIDTH - o5x1_line3 - O5_PIPE_WIDTH; }

int o5y_line1 = O5_Y_START;
int o5y_line2() { return o5y_line1 + O5_SPACE_LINE;}
int o5y_line3() { return o5y_line1 + 2*O5_SPACE_LINE;}

void Obstacle5(SDL_Renderer* renderer){
    SDL_Rect o5pipe_line1_1 = {o5x1_line1,o5y_line1,O5_PIPE_WIDTH, O5_PIPE_HEIGHT};
    SDL_RenderCopy(renderer, gPipeTexture, nullptr, &o5pipe_line1_1);

    SDL_Rect o5pipe_line1_2 = {o5x2_line1(),o5y_line1,O5_PIPE_WIDTH, O5_PIPE_HEIGHT};
    SDL_RenderCopy(renderer, gPipeTexture, nullptr, &o5pipe_line1_2);

    SDL_Rect o5pipe_line2_1 = {o5x1_line2,o5y_line2(),O5_PIPE_WIDTH, O5_PIPE_HEIGHT};
    SDL_RenderCopy(renderer, gPipeTexture, nullptr, &o5pipe_line2_1);

    SDL_Rect o5pipe_line2_2 = {o5x2_line2(),o5y_line2(),O5_PIPE_WIDTH, O5_PIPE_HEIGHT};
    SDL_RenderCopy(renderer, gPipeTexture, nullptr, &o5pipe_line2_2);

    SDL_Rect o5pipe_line3_1 = {o5x1_line3,o5y_line3(),O5_PIPE_WIDTH, O5_PIPE_HEIGHT};
    SDL_RenderCopy(renderer, gPipeTexture, nullptr, &o5pipe_line3_1);

    SDL_Rect o5pipe_line3_2 = {o5x2_line3(),o5y_line3(),O5_PIPE_WIDTH, O5_PIPE_HEIGHT};
    SDL_RenderCopy(renderer, gPipeTexture, nullptr, &o5pipe_line3_2);
            //line 1 delay
    if (!o5isPaused_line1) {
        if (o5positive_line1) o5x1_line1 += O5_SPEED;
        if (o5negative_line1) o5x1_line1 -= O5_SPEED;
    }

    if (!o5isPaused_line1) {
        if (o5x1_line1 <= 0) {
            o5positive_line1 = true;
            o5negative_line1 = false;
            o5isPaused_line1 = true;
            o5pauseTimer_line1 = SDL_GetTicks();
        } else if (o5x1_line1+O5_PIPE_WIDTH >= 250) {
            o5positive_line1 = false;
            o5negative_line1 = true;
            o5isPaused_line1 = true;
            o5pauseTimer_line1 = SDL_GetTicks();
        }
    } else {
        if (SDL_GetTicks() - o5pauseTimer_line1 >= 1000) {
            o5isPaused_line1 = false;
        }
    }

        //line 2 delay
    if (!o5isPaused_line2) {
        if (o5positive_line2) o5x1_line2 += O5_SPEED;
        if (o5negative_line2) o5x1_line2 -= O5_SPEED;
    }

    if (!o5isPaused_line2) {
        if (o5x1_line2 <=0) {
            o5positive_line2 = true;
            o5negative_line2 = false;
            o5isPaused_line2 = true;
            o5pauseTimer_line2 = SDL_GetTicks();
        } else if (o5x1_line2+O5_PIPE_WIDTH >= 250) {
            o5positive_line2 = false;
            o5negative_line2 = true;
            o5isPaused_line2 = true;
            o5pauseTimer_line2 = SDL_GetTicks();
        }
    } else {
        if (SDL_GetTicks() - o5pauseTimer_line2 >=1000 ) {
            o5isPaused_line2 = false;
        }
    }

        //line 3 delay
    if (!o5isPaused_line3) {
        if (o5positive_line3) o5x1_line3 += O5_SPEED;
        if (o5negative_line3) o5x1_line3 -= O5_SPEED;
    }

    if (!o5isPaused_line3) {
        if (o5x1_line3 <= 0) {
            o5positive_line3 = true;
            o5negative_line3 = false;
            o5isPaused_line3 = true;
            o5pauseTimer_line3 = SDL_GetTicks();
        } else if (o5x1_line3+O5_PIPE_WIDTH >= 250) {
            o5positive_line3 = false;
            o5negative_line3 = true;
            o5isPaused_line3 = true;
            o5pauseTimer_line3 = SDL_GetTicks();
        }
    } else {
        if (SDL_GetTicks() - o5pauseTimer_line3 >= 1000) {
            o5isPaused_line3 = false;
        }
    }
}
vector<SDL_Rect> getPipeRect5() {
    vector<SDL_Rect> o5_pipes;

    // LINE 1
    SDL_Rect pipe1_line1 = {o5x1_line1,o5y_line1, O5_PIPE_WIDTH, O5_PIPE_HEIGHT};
    SDL_Rect pipe2_line1 = {o5x2_line1(), o5y_line1, O5_PIPE_WIDTH, O5_PIPE_HEIGHT};
    o5_pipes.push_back(pipe1_line1);
    o5_pipes.push_back(pipe2_line1);

    // LINE 2
    SDL_Rect pipe1_line2 = {o5x1_line2, o5y_line2(), O5_PIPE_WIDTH, O5_PIPE_HEIGHT};
    SDL_Rect pipe2_line2 = {o5x2_line2(), o5y_line2(), O5_PIPE_WIDTH, O5_PIPE_HEIGHT};
    o5_pipes.push_back(pipe1_line2);
    o5_pipes.push_back(pipe2_line2);

    // LINE 3
    SDL_Rect pipe1_line3 = {o5x1_line3, o5y_line3(), O5_PIPE_WIDTH, O5_PIPE_HEIGHT};
    SDL_Rect pipe2_line3 = {o5x2_line3(), o5y_line3(), O5_PIPE_WIDTH, O5_PIPE_HEIGHT};
    o5_pipes.push_back(pipe1_line3);
    o5_pipes.push_back(pipe2_line3);

    return o5_pipes;
}
void resetObstacle5(){
    o5y_line1=O5_Y_START;
    }
#endif
