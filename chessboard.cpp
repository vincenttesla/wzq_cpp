#include "Pointer.h"
#include "Chessboard.h"

Chessboard::CBinit(){
    CSBD[0][0]=new Pointer(0,0,"┏");
	CSBD[0][14]=new Pointer(0,14,"┓");
	CSBD[14][0]=new Pointer(14,0,"┗");
	CSBD[14][14]=new Pointer(14,14,"┛");
	for (int i=1;i<14;i++)
	{
		CSBD[0][i]= new Pointer(0,i,"┯");
		CSBD[14][i]= new Pointer(14,i,"┷");
		CSBD[i][0]= new Pointer(i,0,"┠");
		CSBD[i][14]= new Pointer(i,14,"┨");
		
	}
	for (int i=1;i<14;i++)
	{
		for(int j=1;j<14;j++)
		{
			CSBD[i][j]=new Pointer(i,j,"┼");		
		}
	}
}

Chessboard::updateLastPointer(int x,int y){
    lastPointer[0]=x;
    lastPointer[1]=y;
    lastPointer[2]=1;
}

Chessboard::CBrenew(int x,int y, int who){
    if(lastPointer[2]){//之后改进不判断
        CSBD[lastPointer[0]][lastPointer[1]].changeMode();
        CSBD[x][y].dropPiese(who);
    }else{
        CSBD[x][y].dropPiese(who);
        CSBD[x][y].changeMode();
    };
    updateLastPointer(x,y);
}

CBprint(){
	system("cls");
    for (i=0;i<15;i++){
		printf("%2d",15-i);
		for(j=0;j<15;j++)
		{
			cout<<Csboard[i][j].getGraph();
			if(j==14)cout<<endl;
		}
	}
	cout<<"  ";
	for (i=0;i<15;i++)
	{
		printf("%2c",i+65);
	}
	cout<<endl;
}