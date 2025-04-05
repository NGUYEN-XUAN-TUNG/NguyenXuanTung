#ifndef OBSTACLEPIPE_H
#define OBSTACLEPIPE_H
#include<vector>
#include "init.h"
#include "definition.h"
//initial  pos  pipe;  |===|    |===|
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
    yTop = Y_START_PIPE;
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
//Obs 5:
const int O5_PIPE_HEIGHT=25;
const int O5_PIPE_WIDTH=50;
const int O5_SPEED=2;
const int O5_Y_START=0;
    //line 1:
    int o5x1_line1=200;
    int o5x2_line1(){
        return SCREEN_WIDTH-o5x1_line1-O5_PIPE_WIDTH;
        }
    int o5y_line1=O5_Y_START;
    //line 2:
    int o5x1_line2=200;
    int o5x2_line2(){
        return SCREEN_WIDTH-o5x1_line2-O5_PIPE_WIDTH;
        }
    int o5y_line2(){
        return o5y_line1+O5_PIPE_HEIGHT;
        }
    //line 3:
    int o5x1_line3=200;
    int o5x2_line3(){
        return SCREEN_WIDTH-o5x1_line3-O5_PIPE_WIDTH;
        }
    int o5y_line3(){
        return o5y_line1+2*O5_PIPE_HEIGHT;
        }
bool o5positive_line1=false;
bool o5negative_line1=true;
bool o5positive_line2=false;
bool o5negative_line2=true;
bool o5positive_line3=false;
bool o5negative_line3=true;
void Obstacle5(SDL_Renderer* renderer){
    SDL_Rect o5pipe_line1_1 = {o5x1_line1,o5y_line1,O5_PIPE_WIDTH, O5_PIPE_HEIGHT};
    SDL_RenderCopy(renderer, gPipeTexture, nullptr, &o5pipe_line1_1);

    SDL_Rect o5pipe_line1_2 = {o5x2_line1(),o5y_line1,O5_PIPE_WIDTH, O5_PIPE_HEIGHT};
    SDL_RenderCopy(renderer, gPipeTexture, nullptr, &o5pipe_line1_2);

    SDL_Rect o5pipe_line2_1 = {o5x1_line2,o5y_line2(),O5_PIPE_WIDTH, O5_PIPE_HEIGHT};
    SDL_RenderCopy(renderer, gPipeTexture, nullptr, &o5pipe_line2_1);

    SDL_Rect o5pipe_line2_2 = {o5x2_line2(),o5y_line2(),O5_PIPE_WIDTH, O5_PIPE_HEIGHT};
    SDL_RenderCopy(renderer, gPipeTexture, nullptr, &o5pipe4);

    SDL_Rect o5pipe_line3_1 = {o5x1_line3,o5y_line3(),O5_PIPE_WIDTH, O5_PIPE_HEIGHT};
    SDL_RenderCopy(renderer, gPipeTexture, nullptr, &o5pipe_line3_1);

    SDL_Rect o5pipe_line3_2 = {o5x2_line3(),o5y_line3(),O5_PIPE_WIDTH, O5_PIPE_HEIGHT};
    SDL_RenderCopy(renderer, gPipeTexture, nullptr, &o5pipe_line3_2);

    //line 1:


}
#endif
