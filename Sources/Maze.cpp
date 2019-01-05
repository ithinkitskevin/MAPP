#include "../Headers/Maze.h"
#include "../Headers/Piece.h"

#include <iostream>

using namespace std;

Maze::Maze() {
    // int row = this -> getRowCount();
    // int col = this -> getColCount();

    // for(int r = 0; r < row; r++){
    //     for (int c = 0; c < col; c++) {
    //         this -> board[r][c] = new Piece(r,c,'x');
    //     }
    // }
    this -> board[0][0] = new Piece(0,0,'a');
    this -> board[0][1] = new Piece(0,1,'b');
    this -> board[1][0] = new Piece(1,0,'c');
    this -> board[1][1] = new Piece(1,1,'d');
    this -> board[2][0] = new Piece(2,0,'e');
    this -> board[2][1] = new Piece(2,1,'f');
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