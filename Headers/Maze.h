#ifndef MAZE_H
#define MAZE_H

#include <string>
#include <vector>
#include <iostream>

#include "../Headers/Piece.h"

using namespace std;

const int ROWCOUNT = 7;
const int COLCOUNT = 7;

class Maze {
    private:
        vector<Piece> activePieces;
        vector<Piece> solvedPieces;
        Piece *board[ROWCOUNT][COLCOUNT];
        Maze* maze;
    protected:
    public:
        Maze();
        ~Maze();
        int getRowCount() { return ROWCOUNT; }
        int getColCount() { return COLCOUNT; }
        void toString();
        void placePiece(int, int, int, int);
        Maze *getBoard() { if (! (this -> maze)) { maze = new Maze(); } return maze; }
        char ** getSimpleMatrix();
};

#endif // MAZE_H
