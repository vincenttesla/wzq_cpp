class Game
{
public:
	int agree;
	int model;//0：人人 1：人机
	int winner;
	int more;
	
	Game();
	void start();
	void chooseMode();
	void over();
	void end();
};