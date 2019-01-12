#ifndef PIECE_H
#define PIECE_H

#include <string>

#include "Point.h"

using namespace std;

class Piece {
    private:
        Point *point;
        char value;
    protected:
    public:
        Piece(int, int, char);
        Piece();
        ~Piece();
        string toString();
        int getX() { return this -> point -> getX(); }
        int getY() { return this -> point -> getY(); }
        int getValue() { return value; }
        void setX(int x) { this -> point -> setX(x); }
        void setY(int y) { this -> point -> setY(y); }
        void setValue(int value) { this -> value = value; }

};

#endif // PIECE_H
