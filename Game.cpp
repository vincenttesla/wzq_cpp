#include "Game.h"
#include <iostream>

using namespace std;

void Game::start() {
    cout<<"***五子棋***"<<endl;
}

void Game::chooseMode() {
	cout <<"1pp 2pc others close"<< endl;
	cout << "please choose model:" << endl;
	cin >> model;
	if(model>2||model<1)
		exit(-1);
	system("cls");
	model-=1;
}

void Game::over() {
    int m;
    cout<<"Game Over!"<<endl;
    cout<<"Winner is "<<winner<<"!"<<endl;
    cout<<"regame? 1 yes 2 no"<<endl;
	cin>>m;
    this->agree = m == 1 ? 1 : 0;
}

void Game::end() {
    cout<<"Thanks for playing"<<endl;
}

Game::Game(){
    this->agree = 1;
    this->winner = 0;
    this->model = 0;
    this->more = 0;
};