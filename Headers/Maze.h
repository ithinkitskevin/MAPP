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
    protected:
    public:
        bool isPrivateZone(ActiveUnit*);
        Maze();
        ~Maze();
        vector<ActiveUnit*> getActiveUnits(){ return activePieces; }
        int getRowCount() { return ROWCOUNT; }
        int getColCount() { return COLCOUNT; }
        void toString();
        void placePiece(ActiveUnit*, int, int);
        Maze *getBoard() { if (! (this -> maze)) { maze = new Maze(); } return maze; }
        char ** getSimpleMatrix();
        void addActive(ActiveUnit) ;
        void setUp();
        void sortActivePieces();
        void doProgression();
        void doRegression();
        bool stillActive(){ if(activePieces.size() != 0){ return true; } return false; };
};

#endif // MAZE_H
