#include "../Headers/Point.h"

#include <string>
#include <sstream>
using namespace std;

Point::Point() {
    this -> x = -1;
    this -> y = -1;
}

Point::Point(int x, int y) {
    this -> x = x;
    this -> y = y;
}

Point::~Point(){
    // cout << "Removed (" << this -> x << "," << this -> y << ") Point" << endl;
}

string Point::toString(){
    stringstream s;
    s << "(" << (this -> x) << ", " << (this -> y) << ")";
    return s.str();
}