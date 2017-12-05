#include <iostream>
#include <string>
#include "stdafx.h"
#include "stdio.h"
#include "Pointer.h"

using namespace std;

class Chessboard//棋盘类
{
public:
	CBinit();//棋盘的初始化
	CBrenew(int x,int y);//棋盘的更新
	CBprint();//打印棋盘
	updateLastPointer(int x, int y);
	Pointer CSBD[15][15];
	int lastPointer[3];//0:x 1:y 2:是否已落子，0:否 1：是
protected:
private:
};