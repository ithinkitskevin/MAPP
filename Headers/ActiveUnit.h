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
        vector<int> alterPathLoc;
        Point nextMove;
        bool alterConnect;
        Point dest;
        vector<Point> pointVisisted;
    public:
        void addVisited(Point v) { pointVisisted.push_back(v); } 
        vector<Point> getPointVisited() { return pointVisisted; }
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
        void setNextMove(Point n) { this -> nextMove = n; }
        Point getNextMove() { 
            for(int i = 0; i < this -> path.size() - 1; i++) {
                if(this -> path.at(i).getX() == this -> getX() && 
                    this -> path.at(i).getY() == this -> getY() ) {
                    return Point(this -> path.at(i+1).getX(), this -> path.at(i+1).getY());
                }
            }
            return Point(-1, -1);
         }
        vector<int> getAlterPathLoc() { return alterPathLoc; }
        void addAlterPathLoc(int x){
            this -> alterPathLoc.push_back(x);
        }
        vector<Point> getAlterPathAt(int r) {
            vector<Point> cc;
            // for(int r = 0; r < this -> getAlterPathLoc().size() - 1; r++ ) {
                int start = this -> getAlterPathLoc().at(r);
                int end = this -> getAlterPathLoc().at(r+1);
                // cout << start << " AND  " << end << endl;

                for(int x = start; x < end; x++) {
                    cc.push_back(this -> getAlterPath().at(x));
                }
                // cout << "For coord " << r << ", the alter path is " ; 
            // }
            return cc;
        }
        bool operator< (const ActiveUnit &other) const { return this->priority < other.priority; }
        bool isEmpty() { if(path.size() == 0 ) {return false;} return true; }
        bool findPath(Point, Point);
        bool findAlterPath(Point, Point);
        void setAlterConnect(bool r) { this->alterConnect = r; }
        bool getAlterConnect() { return alterConnect; }
        void setPriority(int priority) { this -> priority = priority; }
        int getPriority(){ return priority; }
        void setDest(Point dest){ this -> dest = dest; }
        Point getDest(){return dest;}
        vector<Point> getPrivateZone();
};

#endif // ActiveUnit_H