#include "../Headers/Maze.h"
#include "../Headers/Piece.h"
#include "../Headers/Path.h"
#include "../Headers/Heuristic.h"


#include <iostream>
#include <string>

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

bool isMovable(int x, int y, char**maze){
    char c = maze[x][y];
    if(isalpha(c)){
        if(islower(c)){
            return true;
        }
        if(isupper(c)) {
            return false;
        }
    }
    if(c == '0'){
        // Not needed... 
        return false;
    }
    return false;
}

bool isSpace(int x, int y, char**maze){
    char c = maze[x][y];
    if(c == ' ') {
        return true;
    }
    if(isalpha(c)){
        if(isupper(c)){
            return true;
        }
    }
    return false;
}

void printVectors(vector<Point> p){
    for(int i = 0; i < p.size() ; i++){
        cout << p.at(i).getX() << ", " << p.at(i).getY();
        if(i != p.size()-1) {
            cout << " -> ";
        }
    } cout << endl;
}

// TODO: Rename this. It's just getting the prioritei
void Maze::getPriority(){
    vector<ActiveUnit*> r = this -> activePieces;
    for(int a = 0; a < r.size(); a++){
        int d = straightLine(r.at(a)->getX(), r.at(a)->getY(), r.at(a)->getDest().getX(), r.at(a)->getDest().getY());
        
        r.at(a)->setPriority(d);
    }
}

bool compareUnitPointer(ActiveUnit* a, ActiveUnit* b) { return (*b < *a); }

bool containsVectorPoint(vector<Point> points, Point point) {
    for(int i = 0; i < points.size(); i++){
        if(points.at(i).getX() == point.getX() &&
            points.at(i).getY() == point.getY() ) {
                return true;
            }
    }
    return false;
}

bool Maze::isPrivateZone(ActiveUnit* curr, Point nextMove){
    cout << "isPrivateZone " << nextMove.getX() << ","  << nextMove.getY() << " - ";
    sort(this -> activePieces.begin(), this -> activePieces.end(), compareUnitPointer);
    for(int r = 0; r < this -> activePieces.size(); r++){
        if(this -> activePieces.at(r) -> getPriority() > curr -> getPriority() ) {
            // This actually means current has a higher priority, as
            // low distance is high priority...
            if(containsVectorPoint(this -> activePieces.at(r) -> getPrivateZone(), nextMove )) {
                printVectors(this -> activePieces.at(r) -> getPrivateZone());
                cout << endl << "At isPrivateZone, " << this -> activePieces.at(r) -> getX() << "," << this -> activePieces.at(r) -> getY() << " causes private zone"; 
                return true;
            }
        } else {
            // That's it, no other priorities are better...
            cout << "at " << r << " done prioritizing..." << endl;
            return false;
        }
    } 

    cout << endl;
    return false;
}

void Maze::createBlank(ActiveUnit* curr,int alterX, int alterY, vector<Point> alterPath) {
    cout << "createBlank at " << alterX << ", " << alterY << endl;
    if(alterPath.size() == 0){
        return;
    }
    printVectors(alterPath);
    cout << "AHH?: " << curr -> getX() << ", " << curr -> getY() << endl;
    int x = 0;
    while(this -> board[curr -> getNextMove().getX()][curr -> getNextMove().getY()] -> getValue() != SPACE) {
        cout << "AHH!: "<< curr -> getNextMove().getX()<<", "<<curr -> getNextMove().getY()<<", "<<(char)this -> board[curr -> getNextMove().getX()][curr -> getNextMove().getY()] -> getValue() << endl;
        int indexMove = x;
    
        int fromX = alterPath.at(indexMove).getX();
        int fromY = alterPath.at(indexMove).getY();
        int toX = alterPath.at(indexMove+1).getX();
        int toY = alterPath.at(indexMove+1).getY();

        // move unit to next position

        // TODO: Fix into a hashtable for faster result...
        char from = board[fromX][fromY] -> getValue();
        char to = board[toX][toY] -> getValue();

        this -> board[fromX][fromY] -> setValue(to);
        this -> board[toX][toY] -> setValue(from);

        x++;

    }
}



bool Maze::isBringBlank(ActiveUnit* curr){
    cout <<"IS BRING BLANK" << endl ;
    if(!isMovable(curr -> getNextMove().getX(), curr -> getNextMove().getY(), this -> getSimpleMatrix())){
        return false;
    }
    vector<Point> alterPath = curr -> getAlterPathAt(curr -> getX(), curr -> getY(), true);
    
    // if(alterPath.size() == 0) {
    //     // Check, since it doesn't have any alterPath, if you can place the blockingPiece in either four direction
    //     int x[4] = {-1, 0, 1, 0};
    //     int y[4] = {0, 1, 0, -1};

    //     for(int i = 0; i < 4; i++){
    //         int blockX = curr -> getNextMove().getX() + x[i];
    //         int blockY = curr -> getNextMove().getY() + y[i];
    //         if(isSpace(blockX, blockY, this -> getSimpleMatrix())){
    //             // Also, set note that the piece has been moved
    //             //TODO: Seriously, make a hashmap of this...
    //             for(int r = 0; r <activePieces.size(); r++) {
    //                 int actX = activePieces.at(r) -> getX();
    //                 int actY = activePieces.at(r) -> getY();

    //                 if(actX == curr -> getNextMove().getX()
    //                         && actY == curr -> getNextMove().getY()){
                        
    //                     if(activePieces.at(r) -> getOriginal().getX() == -1 && 
    //                         activePieces.at(r) -> getOriginal().getY() == -1){
                            
    //                         cout << "NEW ORIGINAL FOR " << (char)activePieces.at(r) -> getValue() << ": " << actX << ", " << actY << endl;
    //                         activePieces.at(r) -> setOriginal(Point(actX, actY));
    //                         activePieces.at(r) -> setMovedPath(Point(actX, actY));

    //                     }
    //                     activePieces.at(r) -> setMovedPath(Point(blockX, blockY));
    //                     placePiece(activePieces.at(r), blockX, blockY);
    //                     cout << "BROUGHT PIECE " << (char)activePieces.at(r) -> getValue() << ": " << activePieces.at(r) -> getX() << ", " << activePieces.at(r) -> getY() << endl;
    //                 }
    //             }
    //             cout << "PLACED " << blockX << "," << blockY <<  ","  << (char)this -> board[blockX][blockY] -> getValue() << endl;

    //             return true;
    //         }
    //     }
    //     cout << "Impossible to BRING BLANK" << endl;

    //     return false;
    // }

    // ToDo: Do this with alterPath too??
    for(int i = 0; i < alterPath.size(); i++) {
        cout << "AT "<< i << " "; 
        if(isPrivateZone(curr, alterPath.at(i))) {
            return false;
        } 
        if(this -> board[alterPath.at(i).getX()][alterPath.at(i).getY()] -> getValue() == SPACE) {
            createBlank(curr, alterPath.at(i).getX(), alterPath.at(i).getY(), alterPath);
            return true;
        }
        
    }

    return false;
}

bool Maze::isAlterPathAvail(vector<Point> alterPath, char** maze){
    int alterPathSize = alterPath.size();
    if(alterPathSize <= 1) {
        return false;
    }
    for(int a = 1; a < alterPathSize; a++){
        if(maze[alterPath.at(a).getX()][alterPath.at(a).getY()] != SPACE) {
            // cout << "I'M NOT SPACE!! " << maze[alterPath.at(a).getX()][alterPath.at(a).getY()] << endl;
            return false;
        }
    }
    return true;
}

bool Maze::doesDestInterfere(ActiveUnit* curr){
    // cout << "IN doesDestInterfere, LOOKING FOR " << curr -> getDest().toString() << endl;
    for(int i = 0; i < this -> activePieces.size(); i++) {
        if(this -> activePieces.at(i) -> getX() == curr -> getX()
            && this -> activePieces.at(i) -> getY() == curr -> getY()){
            continue;
        }
        printVectors(this -> activePieces.at(i) -> getPath());
        if(containsVectorPoint(this -> activePieces.at(i) -> getPath(), curr -> getDest())){
            return true;            
        }
    }
    //   cout << "DONE WITH doesDestInterfere" << endl;
    return false;
}

void Maze::doProgression(){
    bool change = false;

    // cout << "BEGIN PROGRESSION: " << this -> activePieces.size() << endl;
    while(change == false) {
        sort(this -> activePieces.begin(), this -> activePieces.end(), compareUnitPointer);
        for(int r = 0; r < this -> activePieces.size(); r++){
            cout << "SORTED: " << this -> activePieces.at(r) -> getX() << "," << this -> activePieces.at(r) -> getY() << "," << this -> activePieces.at(r) -> getPriority() << endl;
        }
        for (int a = 0; a < this -> activePieces.size(); a++) {
            ActiveUnit * curr = this -> activePieces.at(a);
            Point nxt = curr -> getNextMove();
            cout << "In Progression Step:  (" << (char)curr -> getValue() << ") - " << curr -> getX() << ", " << curr -> getY() << " with next move - " <<  nxt.getX() << "," << nxt.getY() << "," << (char) this -> board[nxt.getX()][nxt.getY()] -> getValue() << endl;
            Point currPosition = Point(curr -> getX(), curr -> getY());
            if(!containsVectorPoint(curr -> getPath(), currPosition)){
                // Current position is not in the path
                    // Do Nothing
                cout << "Current Position is NOT in the path" << endl;
                // If position is not in the path, then see if it's somewhere else and bring it back home
                // vector<Point> movedPath = curr -> getMovedPath();
                // reverse(movedPath.begin(), movedPath.end()); // Simpler... TODO: FIX so that the iterator does it
                // int eraseIndex = 0;
                // for(int i = 0; i < movedPath.size() - 1; i++) {
                //     int destX = movedPath.at(i+1).getX();
                //     int destY = movedPath.at(i+1).getY();

                //     int origX = movedPath.at(i).getX();
                //     int origY = movedPath.at(i).getY();

                //     cout << "ORIG" << origX << "," << origY << "\tDEST" << destX<<","<<destY <<","<< (char) board[destX][destY] -> getValue()<<endl;

                //     if(isSpace(destX, destY, this -> getSimpleMatrix())){
                //         cout << destX << ", " << destY << endl;
                //         this -> placePiece(curr , destX, destY);  
                //         cout << "MOVED: " << curr -> getX() << "," << curr-> getY() << ","  << curr -> getValue() << endl; 
                //         this -> setChange(true);                    
                //     } else {
                //          // Also, now erase the movedPath            
                //         break;
                //     }
                // }
                // curr -> eraseMovedPath(eraseIndex, 0);
                continue;
            } else if (containsVectorPoint(curr -> getPointVisited(), curr -> getNextMove() )) {
                // Already visisted the next move
                cout << "Next step is already in Current progression step - Do Nothing" << endl;
                continue;
            } else if (isPrivateZone(curr, curr -> getNextMove())) {
                // location in private zone
                cout << "Private Zone - Do Nothing" << endl;
                continue;
            } else if (this -> board[curr -> getNextMove().getX()][curr -> getNextMove().getY()] -> getValue() == SPACE || (isalpha((char)this -> board[curr -> getNextMove().getX()][curr -> getNextMove().getY()] -> getValue()) && isupper((char)this -> board[curr -> getNextMove().getX()][curr -> getNextMove().getY()] -> getValue()) )) {
                cout << "Next Area is Blank " << endl;
                // Add the position to pointVisited
                curr -> addVisited(Point(curr -> getX(), curr -> getY()));

                // If the ActiveUnit is at it's destination
                if(curr -> getNextMove().getX() == curr -> getDest().getX() && curr -> getNextMove().getY() == curr -> getDest().getY()) {
                    // Get rid of the piece in activePieces
                    int eraseIndex = -1;
                    for(int i = 0; i < this -> activePieces.size(); i++) {
                        if(this -> activePieces.at(i) -> getX() == curr -> getX()
                            && this -> activePieces.at(i) -> getY() == curr -> getY()){
                            eraseIndex = i;
                        }
                    }
                    if(eraseIndex == -1) {
                        cout << "ERROR: Move unit to empty position" << endl;
                        return;
                    }
                    // Check if the destination piece will interfere with any other pieces. 
                    if(doesDestInterfere(this -> activePieces.at(eraseIndex))){
                        cout << "DON'T REMOVE YET" << endl;
                    } else {
                        // this -> solvedPieces.push_back(activePieces.at(eraseIndex));
                        this -> placePiece(curr , curr -> getNextMove().getX(),curr -> getNextMove().getY());
                        this -> activePieces.erase(activePieces.begin() + eraseIndex);
                    }
                } else {
                    // move unit to next position
                    this -> placePiece(curr , curr -> getNextMove().getX(),curr -> getNextMove().getY());

                }
                this -> setChange(true);
                change = true;
            } else if(isBringBlank(curr)) {
                // Bring blank to next position
                cout << "Bring Blank " << endl;

                // TODO: Modularize the three below points into a function
                // Add the position to pointVisited
                curr -> addVisited(Point(curr -> getX(), curr -> getY()));

                // move unit to next position
                this -> placePiece(curr , curr -> getNextMove().getX(),curr -> getNextMove().getY());

                // If the ActiveUnit is at it's destination
                if(curr -> getX() == curr -> getDest().getX() && curr -> getY() == curr -> getDest().getY()) {
                    // Get rid of the piece in activePieces
                    int eraseIndex = -1;
                    for(int i = 0; i < this -> activePieces.size(); i++) {
                        if(this -> activePieces.at(i) -> getX() == curr -> getX()
                            && this -> activePieces.at(i) -> getY() == curr -> getY()){
                            eraseIndex = i;
                        }
                    }
                    if(eraseIndex == -1) {
                        cout << "ERROR: Move unit to empty position" << endl;
                        return;
                    } else {
                        // this -> solvedPieces.push_back(activePieces.at(eraseIndex));
                        this -> activePieces.erase(activePieces.begin() + eraseIndex);
                    }
                }

                this -> setChange(true);
                change = true;
            } 
            // else if (isAlterPathAvail(curr -> getAlterPathAt(curr -> getX(), curr -> getY(), false), this -> getSimpleMatrix())) {
            //     cout << "Alternate Path" << endl;
            //     // For alternate path...
            //     // So if there's nothing along the alternatePath, then move the active unit along the alternatePath...
            //     vector<Point> alterPath = curr -> getAlterPathAt(curr -> getX(), curr -> getY(), false);
            //     placePiece(curr, alterPath.at(alterPath.size()-1).getX(), alterPath.at(alterPath.size()-1).getY());
                
            //     cout << "Curr Point" << curr -> getX() << ", " << curr -> getY() << endl;
                
            //     this -> setChange(true);
            //     change = true;
            // } 
            else {
                // Do something else
                cout << "Else - Do Nothing" << endl;
                continue;
            }
            char** sMaze = this -> getSimpleMatrix();

            for(int i = 0; i < this -> getRowCount(); i++){
                // cout << "| ";
                for (int j = 0; j < this -> getColCount(); j++){
                    cout << sMaze[i][j] << " " ;
                    // cout << ((maze.getBoard()+i)+j) << " ";
                } cout <<  endl;
            }

        }
        break;
    }
    cout << "Finished Progression Step" << endl;
    
}

void Maze::doRepositioning(){
    // Used if the maze is stuck...
    sort(this -> activePieces.begin(), this -> activePieces.end(), compareUnitPointer);
    vector<ActiveUnit*> r = this -> activePieces;

    for(int a = 0; a < r.size(); a++){
        cout << r.at(a) -> toString() << endl;
        vector<Point> moved = r.at(a) -> getPointVisited();
        // TODO: instead of reversing, just start from the end
        reverse(moved.begin(), moved.end());

        for(int m = 0; m < moved.size(); m++){
            placePiece(r.at(a), moved.at(m).getX(), moved.at(m).getY());
        }
    }
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

    // This is to print out the Destination. 
    // If another unit happens to land on another destination, then just put the active unit on top until it goes awway
    // cout << "Current Active Pieces"
    for(int a = 0; a < this -> activePieces.size(); a++) {
        int activeX = activePieces.at(a) -> getDest().getX();
        int activeY = activePieces.at(a) -> getDest().getY();
        if(this -> board[activeX][activeY] -> getValue() == SPACE){
            this -> board[activeX][activeY] -> setValue(toupper((char)activePieces.at(a) -> getValue()));
        }
    }

    for (int r = 0; r < row; r++) {
        arr[r] = new char[col];
        for (int c = 0; c < col; c++) {
            // cout << "(" << (char) (this -> board[r][c] -> getValue()) << "," << this -> board[r][c] -> getX() << "," << this -> board[r][c] -> getY() << ") ";
            arr[r][c] = (char) (this -> board[r][c] -> getValue());
        } 
    }

    return arr;
}

void Maze::addActive(ActiveUnit p) {
    // this -> activePieces -> push_back(p);
}

void Maze::placePiece(ActiveUnit* curr, int d_x, int d_y) { 
    // Piece *currPiece = this -> board[c_x][c_y];
    Piece *destPiece = this -> board[d_x][d_y];
    int currX = curr -> getX();
    int currY = curr -> getY();

    // cout << "placePiece: " << tolower(destPiece -> getValue()) << " and " << tolower(curr -> getValue()) << endl;
    if (tolower(destPiece -> getValue()) == tolower(curr -> getValue()) ){
        // This is if the active unit meets its desination
        curr -> setValue('0');
        // destPiece -> setValue(' ');
    }

    curr -> setX(d_x);
    curr -> setY(d_y);

    destPiece -> setX(currX);
    destPiece -> setY(currY);
    destPiece -> setValue(' ');

    board[currX][currY] = destPiece;
    Piece * currPiece = curr;
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
        Point destPoint = Point(destinPiece[i].getX(), destinPiece[i].getY());
        // cout<< activePiece[i].getX() << " , " << activePiece[i].getY() << " and " << sMaze[activePieceX][activePieceY] << endl;
        ActiveUnit * temp= new ActiveUnit(activePiece[i].getX(), activePiece[i].getY(), sMaze[activePieceX][activePieceY]);

        vector<Point> currPath = getbfsPath(Point(activePieceX, activePieceY), destPoint, this -> getSimpleMatrix(), rowSize, colSize, Point(-1, -1));
        // vector<Point> test = getAStarPath(Point(activePieceX, activePieceY), destPoint, this -> getSimpleMatrix(), rowSize, colSize, Point(-1, -1));
        // temp -> setAPath(test);
        temp->createPath(currPath);
        temp->setAlterConnect(true);      
        temp->setInitialPosition(Point(activePieceX, activePieceY)); 
        // Alter Path now...
        vector<Point> alterPath;
        for(int i = 1; i < currPath.size() - 1; i++){
            Point currPoint = currPath.at(i-1);
            Point skipPoint = currPath.at(i);
            Point nextPoint = currPath.at(i+1);

            vector<Point> currAlterPath = getbfsPath(currPoint, nextPoint, this -> getSimpleMatrix(), rowSize, colSize, skipPoint);
            if(currAlterPath.size() == 0){
                temp->setAlterConnect(false);
            }
            temp->addAlterPathLoc(alterPath.size());
            for(int r = 0; r < currAlterPath.size(); r++) {
                alterPath.push_back(currAlterPath.at(r));
            }
        }
        // TODO: Utilize the Optimization talked in the paper
        temp->createAlterPath(alterPath);
        temp->setDest(destPoint);
        if(currPath.size() > 1) {
            temp->setNextMove(currPath.at(1));
        }

        // cout << temp->getX() << ", " << temp -> getY() << endl;
        // printVectors(temp->getPath());

        this -> activePieces.push_back(temp);
    }
       

}