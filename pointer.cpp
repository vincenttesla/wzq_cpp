#include "Pointer.h"

using namespace std;

setCoordinate(int x, int y){
    *this.x = x;
    this.y = y;
};
int getCoordinate(){
    int arr={x,y};
    return arr;
};
setInfo(string gra, int value){
    this.gra = gra;
    this.value = value;
};
string getGraph(){
    return this.gra;
};
int getValue(){
    return this.value;
};
Pointer(int x, int y, string gra){
    setCoordinate(x, y);
    setInfo(gra, 0);
};
dropPiece(int value){
    this.setInfo(hash[value], value);
}
changeMode(){
    this.setInfo(hash[this.value*2], this.value);
};