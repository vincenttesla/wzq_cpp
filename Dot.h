#include <string>

using namespace std;

class Dot
{
public:
    Dot(int x, int y, string gra);
    void setCoordinate(int x, int y);
    void setInfo(string gra, int value);
    string getGraph();
    void changeMode();
    void dropPiece(int value);
    int getValue();
protected:
    string hash[4] = {"O", "X", "o", "x"};
private:
	int x;
	int y;
    string gra;
    int value;//0:未落子 1：白子 2：黑子
};
