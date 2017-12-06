#include "Dot.h"
#include "stdio.h"
#include <string>

using namespace std;

Dot::Dot(int x, int y, string gra){
    setCoordinate(x, y);
    setInfo(gra, 0);
}

void Dot::setCoordinate(int x, int y){
    this->x = x;
    this->y = y;
}

void Dot::setInfo(string gra, int value){
    this->gra = gra;
    this->value = value;
}

string Dot::getGraph(){
    return this->gra;
}

int Dot::getValue(){
    return this->value;
}

void Dot::dropPiece(int value){
    this->setInfo(hash[value], value);
}

void Dot::changeMode(){
    this->setInfo(hash[this->value*2], this->value);
}
