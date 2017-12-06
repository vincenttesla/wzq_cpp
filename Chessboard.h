#include "Dot.h"
#include <iostream>

using namespace std;

class Chessboard//棋盘类
{
public:
    Dot* CSBD[15][15];
	void CBinit();//棋盘的初始化
	void CBrenew(int x,int y, int who);//棋盘的更新
	void CBprint();//打印棋盘
	int **getValueArr();
	void updateLastDot(int x, int y);
	int lastDot[3];//0:x 1:y 2:是否已落子，0:否 1：是
};
