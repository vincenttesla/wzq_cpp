#include "Chessboard.h"
#include <iostream>

void Chessboard::CBinit(){
    CSBD[0][0] = new Dot(0,0,"┏");
	CSBD[0][14] = new Dot(0,14,"┓");
	CSBD[14][0] = new Dot(14,0,"┗");
	CSBD[14][14] = new Dot(14,14,"┛");
	for (int i = 1; i < 14; i++)
	{
		CSBD[0][i]= new Dot(0,i,"┯");
		CSBD[14][i]= new Dot(14,i,"┷");
		CSBD[i][0]= new Dot(i,0,"┠");
		CSBD[i][14]= new Dot(i,14,"┨");
	}
	for (int i=1;i<14;i++)
	{
		for(int j=1;j<14;j++)
		{
			CSBD[i][j] = new Dot(i,j,"┼");
		}
	}
}

void Chessboard::updateLastDot(int x,int y){
    lastDot[0]=x;
    lastDot[1]=y;
    lastDot[2]=1;
}

void Chessboard::CBrenew(int x,int y, int who){
    if(lastDot[2]){//之后改进不判断
        CSBD[lastDot[0]][lastDot[1]]->changeMode();
        CSBD[x][y]->dropPiece(who);
    }else{
        CSBD[x][y]->dropPiece(who);
        CSBD[x][y]->changeMode();
    };
    updateLastDot(x,y);
}

void Chessboard::CBprint(){
	system("cls");
    for (int i = 0; i<15; i++){
		printf("%2d",15-i);
		for(int j=0;j<15;j++)
		{
			cout<<CSBD[i][j]->getGraph();
			if(j==14)
                cout<<endl;
		}
	}
	cout<<"  ";
	for (int i=0;i<15;i++)
	{
		printf("%2c",i+65);
	}
	cout<<endl;
}

int** Chessboard::getValueArr() {
	int **a;
	for(int i=0;i<15;i++){
		for(int j=0;j<15;j++){
			a[i][j] = CSBD[i][j]->getValue();
		}
	}
	return a;
}
