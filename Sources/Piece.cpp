#include "../Headers/Piece.h"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Piece::Piece() {
    this -> point = new Point(-1, -1);
    this -> value = '/';
}

Piece::Piece(int x, int y, char value) {
    this -> point = new Point(x, y);
    this -> value = value;
}

Piece::~Piece(){
    // cout << "Removed (" << this -> x << "," << this -> y << ") Point" << endl;
}

string Piece::toString(){
    stringstream s;
    s << "(" << (this -> getX()) << ", " << (this -> getY()) << ", " << (this -> value) << ")";
    return s.str();
}