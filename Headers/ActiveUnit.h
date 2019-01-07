#ifndef ACTIVEUNIT_H
#define ACTIVEUNIT_H

#include "../Headers/Piece.h"
#include "../Headers/Point.h"

#include <vector>

class ActiveUnit : public Piece {
    private:
        int priority;
        vector<Point> path;
        vector<Point> alterPath;
        bool alterConnect;
        Point dest;
    public:
        ActiveUnit( int x = -1, int y = -1, char value = 'X'):Piece(x, y, value) { }
        vector<Point> getPath() { return path; }
        void createPath(vector <Point> vect1) { 
            for (int i=0; i<vect1.size(); i++) {
                 this -> path.push_back(vect1[i]); 
            }
         }
        vector<Point> getAlterPath() { return alterPath; }
        void createAlterPath(vector<Point> vect1) { 
            for (int i=0; i<vect1.size(); i++) {
               this -> alterPath.push_back(vect1[i]); 
            }
        }
        bool operator< (const ActiveUnit &other) const { return priority < other.priority; }
        bool isEmpty() { if(path.size() == 0 ) {return false;} return true; }
        bool findPath(Point, Point);
        bool findAlterPath(Point, Point);
        void setAlterConnect(bool r) { this->alterConnect = r; }
        bool getAlterConnect() { return alterConnect; }
        void setPriority(int priority) { this -> priority = priority; }
        int getPriority(){ return priority; }
        void setDest(Point dest){ this -> dest = dest; }
        Point getDest(){return dest;}
};

#endif // ActiveUnit_H