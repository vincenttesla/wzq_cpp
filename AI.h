#include "stdafx.h"
using namespace std;


class AI//
{
public:
	aiInit();//影响因子矩阵初始化。 和棋盘初始化放在一起。
	aiRenew(int x,int y,int value[15][15],int n);//更新影响因子矩阵，输出最大影响因子点
	aiWord(int x,int y);//影响因子计算公式
protected:
private:
	int aiMath[15][15];//影响因子矩阵
	int i;
	int j;
};