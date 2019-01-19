#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <iomanip>
#include <queue>
#include <math.h>
#include <ctime>
#include <string>

using namespace std;

class Point {
    private:
        int x;
        int y;
        int level;
        int priority;
    public:
        Point();
        Point(int, int);
        Point(int x, int y, int level, int priority) {
            this -> x = x;
            this -> y = y;
            this -> level = level;
            this -> priority = priority;
        };
        void nextLevel(const int & i) {
             this -> level+=(4==8?(i%2==0?10:14):10);
        };
        ~Point();
        string toString();
        int getX() const { return x; }
        int getY() const { return y; }
        int getLevel() const { return level; }
        int getPriority() const { return priority; }
        void setX(int x) { this -> x = x; }
        void setY(int y) { this -> y = y; }
        void setLevel(int level) { this -> level = level; }
        void setPriority(int priority) { this -> priority = priority; }
        void updatePriority(const int & xDest, const int & yDest) {
            this -> priority = level + calc(xDest, yDest)*10; //A*
        }
        const int & calc(const int & destX, const int & destY) const {
            static int dX, dY, d;
            dX = destX - x;
            dY = destY - y;   
            d = static_cast<int>(sqrt(dX*dX+dY*dY));

            return(d);
        }


};

#endif // POINT_H