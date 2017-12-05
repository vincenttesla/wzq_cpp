#include "Game.h"
#include "Chessboard.h"
#include "AI.h"
#include <iostream>

using namespace std;

Game game;
Chessboard CB;
AI Ai;
int judge(int x, int y);
bool isOver(int who);
void AI(int &x, int &y);
bool jinshou(int x, int y);

int main(){
    game = Game();
    CB = Chessboard();
    Ai = Ai();
    while(game.agree){
        game.start();
        CB.CBinit();
        Ai.aiInit();
        game.chooseMode();
        CB.CBprint();
        if(game.model){//人对人
        while(true){
            int x,y,y2;
            int jud = 1;
            while(jud){
                cout<<"1P请落子:";
		        cin>>x>>y2;
                y=y2-97;//PY.coordinate();
                jud = judge(x,y);
                if(jud == 1){
                    cout<<"坐标不合法,请重下！";
                }else if(jud == 2){
                    cout<<"重复落子,请重下！";
                }else if(jud == 3){
                    cout<<"该位置为禁手区，请重下！";
                }
            }
            CB.CBrenew(x,y,1);
            CB.CBprint();
            if(isOver(1)){
                game.winner = 1;
                break;
            }
            jud = 1;
            while(jud){
                cout<<"2P请落子:";
		        cin>>x>>y2;
                y=y2-97;//PY.coordinate();
                jud = judge(x,y);
                if(jud == 1){
                    cout<<"坐标不合法,请重下！";
                }else if(jud == 2){
                    cout<<"重复落子,请重下！";
                }else if(jud == 3){
                    cout<<"该位置为禁手区，请重下！";
                }
            }
            CB.CBrenew(x,y,2);
            CB.CBprint();
            if(isOver(2)){
                game.winner = 2;
                break;
            }
        }
        game.over();
        }else{//人机
            while(true){
            int x,y,y2;
            int jud = 1;
            while(jud){//人
                cout<<"1P请落子:";
		        cin>>x>>y2;
                y=y2-97;//PY.coordinate();
                jud = judge(x,y);
                if(jud == 1){
                    cout<<"坐标不合法,请重下！";
                }else if(jud == 2){
                    cout<<"重复落子,请重下！";
                }else if(jud == 3){
                    cout<<"该位置为禁手区，请重下！";
                }
            }
            CB.CBrenew(x,y,1);
            CB.CBprint();
            if(isOver(1)){
                game.winner = 1;
                break;
            }
            jud = 1;
            while(jud){//机
                cout<<"机器人落子"<<endl;
                Ai.aiRenew(x,y,CB.CSBD,1);
            }
            CB.CBrenew(x,y,2);
            CB.CBprint();
            if(isOver(2)){
                game.winner = 2;
                break;
            }
        }
        game.over();
        }
    }
    game.end();
    return 0;
}

int judge(int x, int y){
    if(x>14 || x < 0 || y>14 || y<0) return 1;//越界
    if(CB.CSBD[x][y].getValue() != 0) return 2;//重复落子
    if(jinshou(x,y)) return 3;//禁手区域
    return 0;
}

bool isOver(int who){
    int x = CB.lastPointer[0];
    int y = CB.lastPointer[1];
    int xBegin = 0;
    int xEnd = 14;
    int yBegin = 0;
    int yEnd = 14;

    xBegin = x > 4 ? (x-4) : 0;
    xEnd = x < 10 ? (x+4) : 14;
    yBegin = y > 4 ? (y-4) : 0;
    yEnd = y < 10 ? (y+4) : 14;

    //一行
    for(int i = xBegin, j = y; i <= xEnd - 4; i++){
        if(CB.CSBD[i][j].getValue()==who&&
           CB.CSBD[i+1][j].getValue()==who&&
           CB.CSBD[i+2][j].getValue()==who&&
           CB.CSBD[i+3][j].getValue()==who&&
           CB.CSBD[i+4][j].getValue()==who)
           return true;
    }
    //一列
    for(int j = yBegin, i = x; j <= yEnd - 4; j++){
        if(CB.CSBD[i][j].getValue()==who&&
           CB.CSBD[i][j+1].getValue()==who&&
           CB.CSBD[i][j+2].getValue()==who&&
           CB.CSBD[i][j+3].getValue()==who&&
           CB.CSBD[i][j+4].getValue()==who)
           return true;
    }

    int len = 0;

    //主对角线
    len = x > y ? y-1 : x-1;
    if(len>4)
        len=4;
    xBegin = x - len;
    yBegin = y - len;

    len = x > y ? 14-x : 14-y;
    if(len>4)
        len=4;
    xEnd = x + len;
    yEnd = y + len;

    for(int i=xBegin,j=yBegin;(i+4<=xEnd)&&(j+4<=yEnd);i++,j++){
        if(CB.CSBD[i][j].getValue()==who&&
           CB.CSBD[i+1][j+1].getValue()==who&&
           CB.CSBD[i+2][j+2].getValue()==who&&
           CB.CSBD[i+3][j+3].getValue()==who&&
           CB.CSBD[i+4][j+4].getValue()==who)
           return true;
    }

    //副对角线
    len = x-1 > 14-y ? 14-y : x-1;
    if(len>4)
        len=4;
    xBegin = x - len;
    yBegin = y + len;

    len = 14-x > y-1 ? y-1 : 14-x;
    if(len>4)
        len=4;
    xEnd = x + len;
    yEnd = y - len;

    for(int i=xBegin,j=yBegin;(i+4<=xEnd)&&(j-4<=yEnd);i++,j--){
        if(CB.CSBD[i][j].getValue()==who&&
           CB.CSBD[i+1][j-1].getValue()==who&&
           CB.CSBD[i+2][j-2].getValue()==who&&
           CB.CSBD[i+3][j-3].getValue()==who&&
           CB.CSBD[i+4][j-4].getValue()==who)
           return true;
    }

    return false;
}

//判断是否禁手的规则
bool jinshou(int x, int y){
    return false;
}