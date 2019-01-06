#include "../Headers/Maze.h"
#include "../Headers/Piece.h"

#include <iostream>

using namespace std;

const char WALL = '1';
const char SPACE = ' ';
const char SOLVED = '0';

Maze::Maze() {
    // int row = this -> getRowCount();
    // int col = this -> getColCount();

    // for(int r = 0; r < row; r++){
    //     for (int c = 0; c < col; c++) {
    //         this -> board[r][c] = new Piece(r,c,'x');
    //     }
    // }
    this -> board[0][0] = new Piece(0,0,WALL);
    this -> board[0][1] = new Piece(0,1,WALL);
    this -> board[0][2] = new Piece(0,2,WALL);
    this -> board[0][3] = new Piece(0,3,WALL);
    this -> board[0][4] = new Piece(0,4,WALL);
    this -> board[0][5] = new Piece(0,5,WALL);
    this -> board[0][6] = new Piece(0,6,WALL);

    this -> board[1][0] = new Piece(1,0,WALL);
    this -> board[1][1] = new Piece(1,1,SPACE);
    this -> board[1][2] = new Piece(1,2,SPACE);
    this -> board[1][3] = new Piece(1,3,SPACE);
    this -> board[1][4] = new Piece(1,4,SPACE);
    this -> board[1][5] = new Piece(1,5,'B');
    this -> board[1][6] = new Piece(1,6,WALL);

    this -> board[2][0] = new Piece(2,0,WALL);
    this -> board[2][1] = new Piece(2,1,SPACE);
    this -> board[2][2] = new Piece(2,2,WALL);
    this -> board[2][3] = new Piece(2,3,SPACE);
    this -> board[2][4] = new Piece(2,4,WALL);
    this -> board[2][5] = new Piece(2,5,SPACE);
    this -> board[2][6] = new Piece(2,6,WALL);

    this -> board[3][0] = new Piece(3,0,WALL);
    this -> board[3][1] = new Piece(3,1,SPACE);
    this -> board[3][2] = new Piece(3,2,WALL);
    this -> board[3][3] = new Piece(3,3,SPACE);
    this -> board[3][4] = new Piece(3,4,WALL);
    this -> board[3][5] = new Piece(3,5,SPACE);
    this -> board[3][6] = new Piece(3,6,WALL);

    this -> board[4][0] = new Piece(4,0,WALL);
    this -> board[4][1] = new Piece(4,1,SPACE);
    this -> board[4][2] = new Piece(4,2,WALL);
    this -> board[4][3] = new Piece(4,3,SPACE);
    this -> board[4][4] = new Piece(4,4,WALL);
    this -> board[4][5] = new Piece(4,5,SPACE);
    this -> board[4][6] = new Piece(4,6,WALL);

    this -> board[5][0] = new Piece(5,0,WALL);
    this -> board[5][1] = new Piece(5,1,SPACE);
    this -> board[5][2] = new Piece(5,2,'b');
    this -> board[5][3] = new Piece(5,3,SPACE);
    this -> board[5][4] = new Piece(5,4,SPACE);
    this -> board[5][5] = new Piece(5,5,SPACE);
    this -> board[5][6] = new Piece(5,6,WALL);

    this -> board[6][0] = new Piece(6,0,WALL);
    this -> board[6][1] = new Piece(6,1,WALL);
    this -> board[6][2] = new Piece(6,2,WALL);
    this -> board[6][3] = new Piece(6,3,WALL);
    this -> board[6][4] = new Piece(6,4,WALL);
    this -> board[6][5] = new Piece(6,5,WALL);
    this -> board[6][6] = new Piece(6,6,WALL);
}
Maze::~Maze() {
    cout << "Removed Maze" << endl;
}

void Maze::toString() {
    int row = this -> getRowCount();
    int col = this -> getColCount();

    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            cout << this -> board[r][c] -> toString() << " ";
        } cout << endl;
    } 
}

char ** Maze::getSimpleMatrix(){
    int row = this -> getRowCount();
    int col = this -> getColCount();

    char ** arr = new char*[row];

    for (int r = 0; r < row; r++) {
        arr[r] = new char[row];
        for (int c = 0; c < col; c++) {
            arr[r][c] = this -> board[r][c] -> getValue();
        } 
    }
    return arr;
}

void Maze::placePiece(int c_x, int c_y, int d_x, int d_y) { 
    Piece *currPiece = this -> board[c_x][c_y];
    Piece *destPiece = this -> board[d_x][d_y];

    currPiece -> setX(d_x);
    currPiece -> setY(d_y);

    destPiece -> setX(c_x);
    destPiece -> setY(c_y);

    if (tolower(destPiece -> getValue()) == (currPiece -> getValue()) ){
        // This is if the active unit meets its desination
        currPiece -> setValue('0');
        destPiece -> setValue(' ');

        // TODO: Finish the Active Pieces
        // this -> activePieces() 
    }

    board[c_x][c_y] = destPiece;
    board[d_x][d_y] = currPiece;
}