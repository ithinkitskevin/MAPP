#include "../Headers/Maze.h"
#include "../Headers/Piece.h"
#include "../Headers/Path.h"

#include <iostream>

using namespace std;

const char WALL = '1';
const char SPACE = ' ';
const char SOLVED = '0';

Maze::Maze() {
    this -> board[0][0] = new Piece(0,0,WALL);
    this -> board[0][1] = new Piece(0,1,WALL);
    this -> board[0][2] = new Piece(0,2,WALL);
    this -> board[0][3] = new Piece(0,3,WALL);
    this -> board[0][4] = new Piece(0,4,WALL);
    this -> board[0][5] = new Piece(0,5,WALL);
    this -> board[0][6] = new Piece(0,6,WALL);
    this -> board[0][7] = new Piece(0,7,WALL);
    this -> board[0][8] = new Piece(0,8,WALL);
    this -> board[0][9] = new Piece(0,9,WALL);
    this -> board[0][10] = new Piece(0,10,WALL);
    this -> board[0][11] = new Piece(0,11,WALL);
    this -> board[0][12] = new Piece(0,12,WALL);
    this -> board[0][13] = new Piece(0,13,WALL);
    this -> board[0][14] = new Piece(0,14,WALL);
    this -> board[0][15] = new Piece(0,15,WALL);
    this -> board[0][16] = new Piece(0,16,WALL);
    this -> board[0][17] = new Piece(0,17,WALL);
    this -> board[0][18] = new Piece(0,18,WALL);
    this -> board[0][19] = new Piece(0,19,WALL);
    this -> board[0][20] = new Piece(0,20,WALL);

    this -> board[1][0] = new Piece(1,0,WALL);
    this -> board[1][1] = new Piece(1,1,'A');
    this -> board[1][2] = new Piece(1,2,SPACE);
    this -> board[1][3] = new Piece(1,3,SPACE);
    this -> board[1][4] = new Piece(1,4,SPACE);
    this -> board[1][5] = new Piece(1,5,SPACE);
    this -> board[1][6] = new Piece(1,6,SPACE);
    this -> board[1][7] = new Piece(1,7,SPACE);
    this -> board[1][8] = new Piece(1,8,SPACE);
    this -> board[1][9] = new Piece(1,9,SPACE);
    this -> board[1][10] = new Piece(1,10,SPACE);
    this -> board[1][11] = new Piece(1,11,SPACE);
    this -> board[1][12] = new Piece(1,12,SPACE);
    this -> board[1][13] = new Piece(1,13,SPACE);
    this -> board[1][14] = new Piece(1,14,SPACE);
    this -> board[1][15] = new Piece(1,15,SPACE);
    this -> board[1][16] = new Piece(1,16,SPACE);
    this -> board[1][17] = new Piece(1,17,'B');
    this -> board[1][18] = new Piece(1,18,SPACE);
    this -> board[1][19] = new Piece(1,19,SPACE);
    this -> board[1][20] = new Piece(1,20,WALL);


    this -> board[2][0] = new Piece(2,0,WALL);
    this -> board[2][1] = new Piece(2,1,SPACE);
    this -> board[2][2] = new Piece(2,2,SPACE);
    this -> board[2][3] = new Piece(2,3,WALL);
    this -> board[2][4] = new Piece(2,4,SPACE);
    this -> board[2][5] = new Piece(2,5,SPACE);
    this -> board[2][6] = new Piece(2,6,WALL);
    this -> board[2][7] = new Piece(2,7,SPACE);
    this -> board[2][8] = new Piece(2,8,SPACE);
    this -> board[2][9] = new Piece(2,9,WALL);
    this -> board[2][10] = new Piece(2,10,SPACE);
    this -> board[2][11] = new Piece(2,11,SPACE);
    this -> board[2][12] = new Piece(2,12,WALL);
    this -> board[2][13] = new Piece(2,13,SPACE);
    this -> board[2][14] = new Piece(2,14,SPACE);
    this -> board[2][15] = new Piece(2,15,WALL);
    this -> board[2][16] = new Piece(2,16,SPACE);
    this -> board[2][17] = new Piece(2,17,SPACE);
    this -> board[2][18] = new Piece(2,18,WALL);
    this -> board[2][19] = new Piece(2,19,SPACE);
    this -> board[2][20] = new Piece(2,20,WALL);

    this -> board[3][0] = new Piece(3,0,WALL);
    this -> board[3][1] = new Piece(3,1,SPACE);
    this -> board[3][2] = new Piece(3,2,SPACE);
    this -> board[3][3] = new Piece(3,3,WALL);
    this -> board[3][4] = new Piece(3,4,SPACE);
    this -> board[3][5] = new Piece(3,5,SPACE);
    this -> board[3][6] = new Piece(3,6,WALL);
    this -> board[3][7] = new Piece(3,7,SPACE);
    this -> board[3][8] = new Piece(3,8,SPACE);
    this -> board[3][9] = new Piece(3,9,WALL);
    this -> board[3][10] = new Piece(3,10,'C');
    this -> board[3][11] = new Piece(3,11,'D');
    this -> board[3][12] = new Piece(3,12,WALL);
    this -> board[3][13] = new Piece(3,13,SPACE);
    this -> board[3][14] = new Piece(3,14,SPACE);
    this -> board[3][15] = new Piece(3,15,WALL);
    this -> board[3][16] = new Piece(3,16,SPACE);
    this -> board[3][17] = new Piece(3,17,SPACE);
    this -> board[3][18] = new Piece(3,18,WALL);
    this -> board[3][19] = new Piece(3,19,SPACE);
    this -> board[3][20] = new Piece(3,20,WALL);

    this -> board[4][0] = new Piece(4,0,WALL);
    this -> board[4][1] = new Piece(4,1,SPACE);
    this -> board[4][2] = new Piece(4,2,SPACE);
    this -> board[4][3] = new Piece(4,3,WALL);
    this -> board[4][4] = new Piece(4,4,SPACE);
    this -> board[4][5] = new Piece(4,5,SPACE);
    this -> board[4][6] = new Piece(4,6,WALL);
    this -> board[4][7] = new Piece(4,7,SPACE);
    this -> board[4][8] = new Piece(4,8,SPACE);
    this -> board[4][9] = new Piece(4,9,WALL);
    this -> board[4][10] = new Piece(4,10,'E');
    this -> board[4][11] = new Piece(4,11,'F');
    this -> board[4][12] = new Piece(4,12,WALL);
    this -> board[4][13] = new Piece(4,13,SPACE);
    this -> board[4][14] = new Piece(4,14,SPACE);
    this -> board[4][15] = new Piece(4,15,WALL);
    this -> board[4][16] = new Piece(4,16,SPACE);
    this -> board[4][17] = new Piece(4,17,SPACE);
    this -> board[4][18] = new Piece(4,18,WALL);
    this -> board[4][19] = new Piece(4,19,SPACE);
    this -> board[4][20] = new Piece(4,20,WALL);


    this -> board[5][0] = new Piece(5,0,WALL);
    this -> board[5][1] = new Piece(5,1,SPACE);
    this -> board[5][2] = new Piece(5,2,SPACE);
    this -> board[5][3] = new Piece(5,3,WALL);
    this -> board[5][4] = new Piece(5,4,SPACE);
    this -> board[5][5] = new Piece(5,5,SPACE);
    this -> board[5][6] = new Piece(5,6,WALL);
    this -> board[5][7] = new Piece(5,7,SPACE);
    this -> board[5][8] = new Piece(5,8,SPACE);
    this -> board[5][9] = new Piece(5,9,WALL);
    this -> board[5][10] = new Piece(5,10,SPACE);
    this -> board[5][11] = new Piece(5,11,SPACE);
    this -> board[5][12] = new Piece(5,12,WALL);
    this -> board[5][13] = new Piece(5,13,SPACE);
    this -> board[5][14] = new Piece(5,14,'G');
    this -> board[5][15] = new Piece(5,15,WALL);
    this -> board[5][16] = new Piece(5,16,SPACE);
    this -> board[5][17] = new Piece(5,17,SPACE);
    this -> board[5][18] = new Piece(5,18,WALL);
    this -> board[5][19] = new Piece(5,19,SPACE);
    this -> board[5][20] = new Piece(5,20,WALL);

    this -> board[6][0] = new Piece(6,0,WALL);
    this -> board[6][1] = new Piece(6,1,SPACE);
    this -> board[6][2] = new Piece(6,2,SPACE);
    this -> board[6][3] = new Piece(6,3,WALL);
    this -> board[6][4] = new Piece(6,4,SPACE);
    this -> board[6][5] = new Piece(6,5,SPACE);
    this -> board[6][6] = new Piece(6,6,WALL);
    this -> board[6][7] = new Piece(6,7,SPACE);
    this -> board[6][8] = new Piece(6,8,SPACE);
    this -> board[6][9] = new Piece(6,9,WALL);
    this -> board[6][10] = new Piece(6,10,SPACE);
    this -> board[6][11] = new Piece(6,11,SPACE);
    this -> board[6][12] = new Piece(6,12,WALL);
    this -> board[6][13] = new Piece(6,13,SPACE);
    this -> board[6][14] = new Piece(6,14,SPACE);
    this -> board[6][15] = new Piece(6,15,WALL);
    this -> board[6][16] = new Piece(6,16,SPACE);
    this -> board[6][17] = new Piece(6,17,SPACE);
    this -> board[6][18] = new Piece(6,18,WALL);
    this -> board[6][19] = new Piece(6,19,SPACE);
    this -> board[6][20] = new Piece(6,20,WALL);

    this -> board[7][0] = new Piece(7,0,WALL);
    this -> board[7][1] = new Piece(7,1,SPACE);
    this -> board[7][2] = new Piece(7,2,SPACE);
    this -> board[7][3] = new Piece(7,3,WALL);
    this -> board[7][4] = new Piece(7,4,SPACE);
    this -> board[7][5] = new Piece(7,5,SPACE);
    this -> board[7][6] = new Piece(7,6,WALL);
    this -> board[7][7] = new Piece(7,7,SPACE);
    this -> board[7][8] = new Piece(7,8,SPACE);
    this -> board[7][9] = new Piece(7,9,WALL);
    this -> board[7][10] = new Piece(7,10,SPACE);
    this -> board[7][11] = new Piece(7,11,SPACE);
    this -> board[7][12] = new Piece(7,12,WALL);
    this -> board[7][13] = new Piece(7,13,SPACE);
    this -> board[7][14] = new Piece(7,14,SPACE);
    this -> board[7][15] = new Piece(7,15,WALL);
    this -> board[7][16] = new Piece(7,16,SPACE);
    this -> board[7][17] = new Piece(7,17,SPACE);
    this -> board[7][18] = new Piece(7,18,WALL);
    this -> board[7][19] = new Piece(7,19,SPACE);
    this -> board[7][20] = new Piece(7,20,WALL);

    this -> board[8][0] = new Piece(8,0,WALL);
    this -> board[8][1] = new Piece(8,1,'H');
    this -> board[8][2] = new Piece(8,2,SPACE);
    this -> board[8][3] = new Piece(8,3,WALL);
    this -> board[8][4] = new Piece(8,4,SPACE);
    this -> board[8][5] = new Piece(8,5,SPACE);
    this -> board[8][6] = new Piece(8,6,WALL);
    this -> board[8][7] = new Piece(8,7,SPACE);
    this -> board[8][8] = new Piece(8,8,SPACE);
    this -> board[8][9] = new Piece(8,9,WALL);
    this -> board[8][10] = new Piece(8,10,SPACE);
    this -> board[8][11] = new Piece(8,11,SPACE);
    this -> board[8][12] = new Piece(8,12,WALL);
    this -> board[8][13] = new Piece(8,13,SPACE);
    this -> board[8][14] = new Piece(8,14,SPACE);
    this -> board[8][15] = new Piece(8,15,WALL);
    this -> board[8][16] = new Piece(8,16,SPACE);
    this -> board[8][17] = new Piece(8,17,SPACE);
    this -> board[8][18] = new Piece(8,18,WALL);
    this -> board[8][19] = new Piece(8,19,SPACE);
    this -> board[8][20] = new Piece(8,20,WALL);

    this -> board[9][0] = new Piece(9,0,WALL);
    this -> board[9][1] = new Piece(9,1,SPACE);
    this -> board[9][2] = new Piece(9,2,SPACE);
    this -> board[9][3] = new Piece(9,3,WALL);
    this -> board[9][4] = new Piece(9,4,SPACE);
    this -> board[9][5] = new Piece(9,5,SPACE);
    this -> board[9][6] = new Piece(9,6,WALL);
    this -> board[9][7] = new Piece(9,7,SPACE);
    this -> board[9][8] = new Piece(9,8,SPACE);
    this -> board[9][9] = new Piece(9,9,WALL);
    this -> board[9][10] = new Piece(9,10,SPACE);
    this -> board[9][11] = new Piece(9,11,SPACE);
    this -> board[9][12] = new Piece(9,12,WALL);
    this -> board[9][13] = new Piece(9,13,SPACE);
    this -> board[9][14] = new Piece(9,14,SPACE);
    this -> board[9][15] = new Piece(9,15,WALL);
    this -> board[9][16] = new Piece(9,16,SPACE);
    this -> board[9][17] = new Piece(9,17,SPACE);
    this -> board[9][18] = new Piece(9,18,WALL);
    this -> board[9][19] = new Piece(9,19,SPACE);
    this -> board[9][20] = new Piece(9,20,WALL);

    this -> board[10][0] = new Piece(10,0,WALL);
    this -> board[10][1] = new Piece(10,1,SPACE);
    this -> board[10][2] = new Piece(10,2,SPACE);
    this -> board[10][3] = new Piece(10,3,SPACE);
    this -> board[10][4] = new Piece(10,4,SPACE);
    this -> board[10][5] = new Piece(10,5,SPACE);
    this -> board[10][6] = new Piece(10,6,SPACE);
    this -> board[10][7] = new Piece(10,7,SPACE);
    this -> board[10][8] = new Piece(10,8,SPACE);
    this -> board[10][9] = new Piece(10,9,SPACE);
    this -> board[10][10] = new Piece(10,10,SPACE);
    this -> board[10][11] = new Piece(10,11,SPACE);
    this -> board[10][12] = new Piece(10,12,SPACE);
    this -> board[10][13] = new Piece(10,13,SPACE);
    this -> board[10][14] = new Piece(10,14,SPACE);
    this -> board[10][15] = new Piece(10,15,SPACE);
    this -> board[10][16] = new Piece(10,16,SPACE);
    this -> board[10][17] = new Piece(10,17,SPACE);
    this -> board[10][18] = new Piece(10,18,SPACE);
    this -> board[10][19] = new Piece(10,19,SPACE);
    this -> board[10][20] = new Piece(10,20,WALL);

    this -> board[11][0] = new Piece(11,0,WALL);
    this -> board[11][1] = new Piece(11,1,SPACE);
    this -> board[11][2] = new Piece(11,2,SPACE);
    this -> board[11][3] = new Piece(11,3,SPACE);
    this -> board[11][4] = new Piece(11,4,SPACE);
    this -> board[11][5] = new Piece(11,5,SPACE);
    this -> board[11][6] = new Piece(11,6,SPACE);
    this -> board[11][7] = new Piece(11,7,SPACE);
    this -> board[11][8] = new Piece(11,8,SPACE);
    this -> board[11][9] = new Piece(11,9,SPACE);
    this -> board[11][10] = new Piece(11,10,SPACE);
    this -> board[11][11] = new Piece(11,11,SPACE);
    this -> board[11][12] = new Piece(11,12,SPACE);
    this -> board[11][13] = new Piece(11,13,SPACE);
    this -> board[11][14] = new Piece(11,14,SPACE);
    this -> board[11][15] = new Piece(11,15,SPACE);
    this -> board[11][16] = new Piece(11,16,SPACE);
    this -> board[11][17] = new Piece(11,17,SPACE);
    this -> board[11][18] = new Piece(11,18,SPACE);
    this -> board[11][19] = new Piece(11,19,SPACE);
    this -> board[11][20] = new Piece(11,20,WALL);

    this -> board[12][0] = new Piece(12,0,WALL);
    this -> board[12][1] = new Piece(12,1,SPACE);
    this -> board[12][2] = new Piece(12,2,SPACE);
    this -> board[12][3] = new Piece(12,3,SPACE);
    this -> board[12][4] = new Piece(12,4,SPACE);
    this -> board[12][5] = new Piece(12,5,SPACE);
    this -> board[12][6] = new Piece(12,6,SPACE);
    this -> board[12][7] = new Piece(12,7,SPACE);
    this -> board[12][8] = new Piece(12,8,SPACE);
    this -> board[12][9] = new Piece(12,9,SPACE);
    this -> board[12][10] = new Piece(12,10,SPACE);
    this -> board[12][11] = new Piece(12,11,SPACE);
    this -> board[12][12] = new Piece(12,12,SPACE);
    this -> board[12][13] = new Piece(12,13,SPACE);
    this -> board[12][14] = new Piece(12,14,SPACE);
    this -> board[12][15] = new Piece(12,15,SPACE);
    this -> board[12][16] = new Piece(12,16,SPACE);
    this -> board[12][17] = new Piece(12,17,SPACE);
    this -> board[12][18] = new Piece(12,18,SPACE);
    this -> board[12][19] = new Piece(12,19,SPACE);
    this -> board[12][20] = new Piece(12,20,WALL);

    this -> board[13][0] = new Piece(13,0,WALL);
    this -> board[13][1] = new Piece(13,1,SPACE);
    this -> board[13][2] = new Piece(13,2,SPACE);
    this -> board[13][3] = new Piece(13,3,SPACE);
    this -> board[13][4] = new Piece(13,4,SPACE);
    this -> board[13][5] = new Piece(13,5,SPACE);
    this -> board[13][6] = new Piece(13,6,SPACE);
    this -> board[13][7] = new Piece(13,7,SPACE);
    this -> board[13][8] = new Piece(13,8,SPACE);
    this -> board[13][9] = new Piece(13,9,SPACE);
    this -> board[13][10] = new Piece(13,10,SPACE);
    this -> board[13][11] = new Piece(13,11,SPACE);
    this -> board[13][12] = new Piece(13,12,SPACE);
    this -> board[13][13] = new Piece(13,13,SPACE);
    this -> board[13][14] = new Piece(13,14,SPACE);
    this -> board[13][15] = new Piece(13,15,SPACE);
    this -> board[13][16] = new Piece(13,16,SPACE);
    this -> board[13][17] = new Piece(13,17,SPACE);
    this -> board[13][18] = new Piece(13,18,SPACE);
    this -> board[13][19] = new Piece(13,19,SPACE);
    this -> board[13][20] = new Piece(13,20,WALL);

    this -> board[14][0] = new Piece(14,0,WALL);
    this -> board[14][1] = new Piece(14,1,'a');
    this -> board[14][2] = new Piece(14,2,'b');
    this -> board[14][3] = new Piece(14,3,'c');
    this -> board[14][4] = new Piece(14,4,'d');
    this -> board[14][5] = new Piece(14,5,'e');
    this -> board[14][6] = new Piece(14,6,'f');
    this -> board[14][7] = new Piece(14,7,'g');
    this -> board[14][8] = new Piece(14,8,'h');
    this -> board[14][9] = new Piece(14,9,SPACE);
    this -> board[14][10] = new Piece(14,10,SPACE);
    this -> board[14][11] = new Piece(14,11,SPACE);
    this -> board[14][12] = new Piece(14,12, SPACE);
    this -> board[14][13] = new Piece(14,13, SPACE);
    this -> board[14][14] = new Piece(14,14, SPACE);
    this -> board[14][15] = new Piece(14,15, SPACE);
    this -> board[14][16] = new Piece(14,16, SPACE);
    this -> board[14][17] = new Piece(14,17, SPACE);
    this -> board[14][18] = new Piece(14,18,SPACE );
    this -> board[14][19] = new Piece(14,19, SPACE);
    this -> board[14][20] = new Piece(14,20,WALL);

    this -> board[15][0] = new Piece(15,0,WALL);
    this -> board[15][1] = new Piece(15,1,WALL);
    this -> board[15][2] = new Piece(15,2,WALL);
    this -> board[15][3] = new Piece(15,3,WALL);
    this -> board[15][4] = new Piece(15,4,WALL);
    this -> board[15][5] = new Piece(15,5,WALL);
    this -> board[15][6] = new Piece(15,6,WALL);
    this -> board[15][7] = new Piece(15,7,WALL);
    this -> board[15][8] = new Piece(15,8,WALL);
    this -> board[15][9] = new Piece(15,9,WALL);
    this -> board[15][10] = new Piece(15,10,WALL);
    this -> board[15][11] = new Piece(15,11,WALL);
    this -> board[15][12] = new Piece(15,12,WALL);
    this -> board[15][13] = new Piece(15,13,WALL);
    this -> board[15][14] = new Piece(15,14,WALL);
    this -> board[15][15] = new Piece(15,15,WALL);
    this -> board[15][16] = new Piece(15,16,WALL);
    this -> board[15][17] = new Piece(15,17,WALL);
    this -> board[15][18] = new Piece(15,18,WALL);
    this -> board[15][19] = new Piece(15,19,WALL);
    this -> board[15][20] = new Piece(15,20,WALL);
}

Maze::~Maze() {
    // cout << "Removed Maze" << endl;
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
        arr[r] = new char[col];
        for (int c = 0; c < col; c++) {
            // cout << (char) (this -> board[r][c] -> getValue()) << " ";
            arr[r][c] = (char) (this -> board[r][c] -> getValue());
        } 
    }

    return arr;
}

void Maze::addActive(ActiveUnit p) {
    this -> activePieces.push_back(p);
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

void Maze::setUp(){
    int rowSize = this -> getRowCount();
    int colSize = this -> getColCount();

    Point activePiece[26];
    Point destinPiece[26];

    char** sMaze = this -> getSimpleMatrix();

    for(int r = 0; r < rowSize; r++){
        for(int c = 0; c < colSize; c++){
            if ( isalpha(sMaze[r][c]) ) {
                // Then the piece at the current position is an active unit
                if( islower(sMaze[r][c]) ) {
                    activePiece[((int) sMaze[r][c] - 97)] = Point(r,c);
                }
                if (isupper(sMaze[r][c])) {
                    destinPiece[((int) (sMaze[r][c]) - 65)] = Point(r,c);
                }
            }   
        }
    }

    for(int i = 0; i < 26; i ++) {
         cout << "FINISHED: STARTING PATH - " << i << endl;
        int activePieceX = activePiece[i].getX();
        int activePieceY = activePiece[i].getY();

        if(activePieceX == -1 && activePieceY == -1) {
            continue;
        }

        ActiveUnit temp(activePiece[i].getX(), activePiece[i].getY(), sMaze[activePieceX][activePieceY]);
        cout << "START ERROR AT BFS" << endl;
        vector<Point> currPath = getbfsPath(Point(activePieceX, activePieceY), Point(destinPiece[i].getX(), destinPiece[i].getY()), this -> getSimpleMatrix(), rowSize, colSize, Point(-1, -1));
        cout << "FINISHED ERROR AT BFS" << endl;
        temp.createPath(currPath);
        temp.setAlterConnect(true);

       
        
        // Alter Path now...
        vector<Point> alterPath;
        for(int i = 1; i < currPath.size() - 1; i++){
            Point currPoint = currPath.at(i-1);
            Point skipPoint = currPath.at(i);
            Point nextPoint = currPath.at(i+1);

            vector<Point> currAlterPath = getbfsPath(currPoint, nextPoint, this -> getSimpleMatrix(), rowSize, colSize, skipPoint);
            if(currAlterPath.size() == 0){
                temp.setAlterConnect(false);
            }
            for(int r = 0; r < currAlterPath.size(); r++) {
                alterPath.push_back(currAlterPath.at(r));
            }
        }
        // TODO: Utilize the Optimization talked in the paper
        temp.createAlterPath(alterPath);

        this -> addActive(temp);
    }
       

}