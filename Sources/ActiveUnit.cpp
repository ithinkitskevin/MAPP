#include "../Headers/ActiveUnit.h"

bool findPath(Point, Point) {
    return true;
}

bool findAlterPath(Point, Point) {
    return true;
}

vector<Point> ActiveUnit::getPrivateZone(){
    vector<Point> privateZone;
    privateZone.push_back(Point(this -> getX(), this -> getY())); //Current
    for(int i = 1; i < this -> path.size() - 1; i++) {
        int x = path.at(i).getX();
        int y = path.at(i).getY();

        if(x == this -> getX() && y == this -> getY()) {
            int parentX = path.at(i-1).getX();
            int parentY = path.at(i-1).getY();
            privateZone.push_back(Point(parentX, parentY)); // Parent
            break;
        }
    }
    return privateZone;
}