#ifndef MAZE_H
#define MAZE_H

#include <string>
#include <vector>
#include <iostream>

#include "../Headers/Piece.h"
#include "../Headers/ActiveUnit.h"

using namespace std;

const int ROWCOUNT = 16;
const int COLCOUNT = 21;

class Maze {
    private:
        vector<ActiveUnit*> activePieces;
        vector<ActiveUnit*> solvedPieces;
        Piece *board[ROWCOUNT][COLCOUNT];
        Maze* maze;
        bool change;
    protected:
    public:
        bool getChange() {
            return this -> change;
        }
        void setChange(bool c) {
            this -> change = c;
        }
        bool doesDestInterfere(ActiveUnit*);
        bool isPrivateZone(ActiveUnit*, Point);
        bool isBringBlank(ActiveUnit*);
        void createBlank(ActiveUnit*,int, int, vector<Point>);
        Maze();
        ~Maze();
        vector<ActiveUnit*> getActiveUnits(){ return activePieces; }
        int getRowCount() { return ROWCOUNT; }
        int getColCount() { return COLCOUNT; }
        void toString();
        void placePiece(ActiveUnit*, int, int);
        void placePiece(int, int, int, int);
        Maze *getBoard() { if (! (this -> maze)) { maze = new Maze(); } return maze; }
        char ** getSimpleMatrix();
        void addActive(ActiveUnit) ;
        void setUp();
        void getPriority();
        void doProgression();
        void doRepositioning();
        bool stillActive(){ if(activePieces.size() != 0){ return true; } return false; };
        bool isAlterPathAvail(vector<Point> , char** );
};

#endif // MAZE_H
