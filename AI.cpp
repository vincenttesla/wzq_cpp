#include <iostream>
#include <string>
#include "stdio.h"
#include "math.h"
#include "AI.h"

using namespace std;

int AI::aiWord(int x,int y)
{
	char e=2.71828;
	return 10*(pow(e,(-0.5*(pow(x-8,2)+pow(y-8,2)))))/1; 
}
void AI::aiInit()
{
	for(i=0;i<15;i++)
	{
		for (j=0;j<15;j++)
		{
			aiMath[i][j]=aiWord(i,j);
		}	
	}	
}
//前者输入的 x横坐标； y纵坐标； value[][]是棋盘值矩阵：元素 0没子 1黑子 2白字；  n表示谁是黑子（先手）：n=0 AI黑子,t=1 AI白子
void AI::aiRenew(int &x,int &y,int **value,int n) 
{
	int m=value[x][y];
	for(i=1;i<5;i++)
	{
		if (2==m+n)//从棋子向八个方向扩散高斯分布的影响因子，遇到对方棋子阻挡则中断。
			break;
		aiMath[x+i][y]+=aiWord(8+i,8);
	}
	for(i=1;i<5;i++)
	{
		if (2==m+n)
			break;
		aiMath[x-i][y]+=aiWord(8-i,8);
	}
	for(i=1;i<5;i++)
	{
		if (2==m+n)
			break;
		aiMath[x][y+i]+=aiWord(8,8+i);
	}
	for(i=1;i<5;i++)
	{
		if (2==m+n)
			break;
		aiMath[x][y-i]+=aiWord(8,8-i);
	}
	for(i=1;i<5;i++)
	{
		if (2==m+n)
			break;
		aiMath[x+i][y+i]+=aiWord(8+i,8+i);
	}
	for(i=1;i<5;i++)
	{
		if (2==m+n)
			break;
		aiMath[x+i][y-i]+=aiWord(8+i,8-i);
	}
	for(i=1;i<5;i++)
	{
		if (2==m+n)
			break;
		aiMath[x-i][y+i]+=aiWord(8-i,8+i);
	}
	for(i=1;i<5;i++)//
	{
		if (2==m+n)
			break;
		aiMath[x-i][y-i]+=aiWord(8-i,8-i);
	}
	int a;//暂存最大影响因子坐标
	int b;
	int max=0;
	for(i=0;i<15;i++)//扫点找最大影响因子坐标
	{
		for (j=0;j<15;j++)
		{
			if (value[i][j]) //有子则跳过
				continue;
			if (aiMath[i][j]>max)
			{
				max=aiMath[i][j];
				a=i;
				b=j;
			}
			
		}	
	}
}
