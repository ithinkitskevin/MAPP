#ifndef POINT_H
#define POINT_H

#include <string>

using namespace std;

class Point {
    private:
        int x;
        int y;
    public:
        Point();
        Point(int, int);
        ~Point();
        string toString();
        int getX() { return x; }
        int getY() { return y; }
        void setX(int x) { this -> x = x; }
        void setY(int y) { this -> y = y; }
};

#endif // POINT_H