#include "../Headers/Maze.h"
#include "../Headers/Piece.h"
#include "../Headers/Path.h"

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
    this -> board[0][7] = new Piece(0,7,WALL);
    this -> board[0][8] = new Piece(0,8,WALL);
    this -> board[0][9] = new Piece(0,9,WALL);

    this -> board[1][0] = new Piece(1,0,WALL);
    this -> board[1][1] = new Piece(1,1,SPACE);
    this -> board[1][2] = new Piece(1,2,'A');
    this -> board[1][3] = new Piece(1,3,SPACE);
    this -> board[1][4] = new Piece(1,4,SPACE);
    this -> board[1][5] = new Piece(1,5,SPACE);
    this -> board[1][6] = new Piece(1,6,'B');
    this -> board[1][7] = new Piece(1,7,SPACE);
    this -> board[1][8] = new Piece(1,8,SPACE);
    this -> board[1][9] = new Piece(1,9,WALL);

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

    this -> board[5][0] = new Piece(5,0,WALL);
    this -> board[5][1] = new Piece(5,1,'a');
    this -> board[5][2] = new Piece(5,2,'b');
    this -> board[5][3] = new Piece(5,3,SPACE);
    this -> board[5][4] = new Piece(5,4,SPACE);
    this -> board[5][5] = new Piece(5,5,SPACE);
    this -> board[5][6] = new Piece(5,6,SPACE);
    this -> board[5][7] = new Piece(5,7,SPACE);
    this -> board[5][8] = new Piece(5,8,SPACE);
    this -> board[5][9] = new Piece(5,9,WALL);

    this -> board[6][0] = new Piece(6,0,WALL);
    this -> board[6][1] = new Piece(6,1,WALL);
    this -> board[6][2] = new Piece(6,2,WALL);
    this -> board[6][3] = new Piece(6,3,WALL);
    this -> board[6][4] = new Piece(6,4,WALL);
    this -> board[6][5] = new Piece(6,5,WALL);
    this -> board[6][6] = new Piece(6,6,WALL);
    this -> board[6][7] = new Piece(6,7,WALL);
    this -> board[6][8] = new Piece(6,8,WALL);
    this -> board[6][9] = new Piece(6,9,WALL);
    
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
        arr[r] = new char[row];
        for (int c = 0; c < col; c++) {
            arr[r][c] = this -> board[r][c] -> getValue();
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
        int activePieceX = activePiece[i].getX();
        int activePieceY = activePiece[i].getY();

        if(activePieceX == -1 && activePieceY == -1) {
            continue;
        }
        ActiveUnit temp(activePiece[i].getX(), activePiece[i].getY(), sMaze[activePieceX][activePieceY]);
        vector<Point> currPath = getbfsPath(Point(activePieceX, activePieceY), Point(destinPiece[i].getX(), destinPiece[i].getY()), *(this -> getBoard()), Point(-1, -1));
        temp.createPath(currPath);
        temp.setAlterConnect(true);
        
        // Alter Path now...
        vector<Point> alterPath;
        for(int i = 1; i < currPath.size() - 1; i++){
            Point currPoint = currPath.at(i-1);
            Point skipPoint = currPath.at(i);
            Point nextPoint = currPath.at(i+1);

            vector<Point> currAlterPath = getbfsPath(currPoint, nextPoint, *(this -> getBoard()), skipPoint);
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