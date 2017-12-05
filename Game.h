#include "stdafx.h"

using namespace std;

class Game
{
public:
	start();
	chooseMode();
	over();
	end();
	Game();
	int agree;
	int model;//0：人人 1：人机
	int winner;
	int more;
};