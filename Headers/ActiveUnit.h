#ifndef ACTIVEUNIT_H
#define ACTIVEUNIT_H

#include "../Headers/Piece.h"
#include "../Headers/Point.h"

#include <vector>

class ActiveUnit : public Piece {
    private:
        vector<Point> path;
        vector<Point> alterPath;
    public:
        vector<Point> getPath() { return path; }
        void addPath(Point point) { this -> path.push_back(point); }
        vector<Point> getAlterPath() { return alterPath; }
        void addAlterPath(Point point) { this -> alterPath.push_back(point); }
};

#endif // ActiveUnit_H