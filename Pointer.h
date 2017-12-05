#include <string>
#include "stdio.h"
#include "stdafx.h"

using namespace std;

class Pointer
{
public:
    setCoordinate(int x, int y);
    int getCoordinate();
    setInfo(string gra, int value);
    string getGraph();
    changeMode();
    dropPiece(int value);
    int getValue();
protected:
    string hash[4] = {"□", "■", "○", "●"};
private:
	int x;
	int y;
    string gra;
    int value;//0:未落子 1：白子 2：黑子
};