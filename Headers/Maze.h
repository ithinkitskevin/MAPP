#ifndef MAZE_H
#define MAZE_H

#include <string>
#include <vector>
#include <iostream>

#include "../Headers/Piece.h"
#include "../Headers/ActiveUnit.h"

using namespace std;

const int ROWCOUNT = 7;
const int COLCOUNT = 10;

class Maze {
    private:
        vector<ActiveUnit> activePieces;
        vector<Piece> solvedPieces;
        Piece *board[ROWCOUNT][COLCOUNT];
        Maze* maze;
        
    protected:
    public:
        Maze();
        ~Maze();
        vector<ActiveUnit> getActiveUnits(){ return activePieces; }
        int getRowCount() { return ROWCOUNT; }
        int getColCount() { return COLCOUNT; }
        void toString();
        void placePiece(int, int, int, int);
        Maze *getBoard() { if (! (this -> maze)) { maze = new Maze(); } return maze; }
        char ** getSimpleMatrix();
        void addActive(ActiveUnit) ;
        void setUp();
};

#endif // MAZE_H
