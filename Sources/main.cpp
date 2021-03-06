#include <iostream>
#include <vector>
#include <string>
#include "../Headers/Maze.h"
#include "../Headers/Heuristic.h"
#include "../Headers/Path.h"
#include "../Headers/Point.h"
#include "../Headers/Piece.h"


using namespace std;

/*
List of commands. Tet 
g++ -c Heuristic.cpp main.cpp Maze.cpp Path.cpp Piece.cpp Point.cpp && g++ Heuristic.o main.o Maze.o Path.o Piece.o Point.o -o my_program && ./my_program
rm Heuristic.o main.o my_program
*/

void createMaze(){
    // Create a piece from 2d Matrix...
    const int rowCount = 16;
    const int colCount = 21;

    char fooMat[rowCount][colCount] = {
        		{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},	// 1
				{'X','O',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','O',' ',' ','X'},	// 2
				{'X',' ',' ','X',' ',' ','X',' ',' ','X',' ',' ','X',' ',' ','X',' ',' ','X',' ','X'},	// 3
				{'X',' ',' ','X',' ',' ','X',' ',' ','X','O','O','X',' ',' ','X',' ',' ','X',' ','X'},	// 4
				{'X',' ',' ','X',' ',' ','X',' ',' ','X','O','O','X',' ',' ','X',' ',' ','X',' ','X'},	// 5
				{'X',' ',' ','X',' ',' ','X',' ',' ','X',' ',' ','X',' ','O','X',' ',' ','X',' ','X'},	// 6
				{'X',' ',' ','X',' ',' ','X',' ',' ','X',' ',' ','X',' ',' ','X',' ',' ','X',' ','X'},	// 7
				{'X',' ',' ','X',' ',' ','X',' ',' ','X',' ',' ','X',' ',' ','X',' ',' ','X',' ','X'},	// 8
				{'X','O',' ','X',' ',' ','X',' ',' ','X',' ',' ','X',' ',' ','X',' ',' ','X',' ','X'},	// 9
				{'X',' ',' ','X',' ',' ','X',' ',' ','X',' ',' ','X',' ',' ','X',' ',' ','X',' ','X'},	// 10
				{'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},	// 11
				{'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},	// 12
				{'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},	// 13
				{'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},	// 14
				{'X','W','W','W','W','W','W','W','W',' ',' ',' ','G','G','G','G','G','G','G','G','X'},	// 15
				{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'}	// 16

    };
    char fooMat2[rowCount][colCount] = {
            {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'}, //1
			{'X','O',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'}, //2
			{'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'}, //3
			{'X','X','X','X','X','X','X','X','X','X','O','X','X','X','X','X','X','X','X','X','X'}, //4
			{'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'}, //5
			{'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'}, //6
			{'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'}, //7
			{'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'}, //8
			{'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'}, //9
			{'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'}, //10
			{'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'}, //11
			{'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'}, //12
			{'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'}, //13
			{'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'}, //14
			{'X','W',' ','W',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'}, //15
			{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'}  //16
    };

    for(int r = 0; r < rowCount; r++) {
        for (int c = 0; c < colCount; c++){
                string newC = " ";

                if (fooMat2[r][c] == ' ') {
                    newC = "SPACE";
                } else if (fooMat2[r][c] ==  'X') {
                    newC = "WALL";
                } else if (fooMat2[r][c] == 'O') {
                    newC = "\'A\'";
                } else if (fooMat2[r][c] == 'W') {
                    newC = "\'a\'";
                }
            cout << "this -> board[" << r << "][" << c << "] = new Piece(" << r << "," << c <<  "," << newC << ");" << endl;
        }
    }
}

void printVector(vector<Point> p){
    for(int i = 0; i < p.size() ; i++){
        cout << p.at(i).getX() << ", " << p.at(i).getY();
        if(i != p.size()-1) {
            cout << " -> ";
        }
    } cout << endl;
}

bool testSlidable(Maze maze){
    /*
        1. Alternate Connectivity. 
            There needs to exist alternate path for all path location EXCEPT the last one
        2. Initial Blank - In the path, the first space needs to be empty
            There needs to exist a path in general
        3. Target Isolation
    */      
    vector<ActiveUnit*> activeUnit = maze.getActiveUnits();

    // for(int i = 0; i < activeUnit.size(); i++){
    //     printVector(maze.getActiveUnits().at(i) -> getPath());
    //     cout << endl;
    //     // for(int r = 0; r < maze.getActiveUnits().at(i) -> getAlterPathLoc().size() - 1; r++ ) {
    //     //     printVector(maze.getActiveUnits().at(i) -> getAlterPathAt(r));
    //     // }
    //     cout << endl;
    //     cout << endl;
    // }
    
    // My rule: All units MUST have a path. This also means Initial Blank (2nd rule).
    for(int i = 0; i < maze.getActiveUnits().size(); i++){
        if(maze.getActiveUnits().at(i) -> getPath().size() == 0){
            return false;
        }
    }

    // Alternate Connectivity, First Rule.
    for(int i = 0; i < maze.getActiveUnits().size() - 1; i++){
        if(maze.getActiveUnits().at(i) -> getAlterConnect() == false) {
            return false;
        }
    }
    // TODO: Target Isolation

    return true;
}


void printMaze(int rE, int cE, vector<Point> ve, char ** smaze){
    for(int v = 0; v < ve.size(); v++){
        smaze[ve.at(v).getX()][ve.at(v).getY()] = '*';
    }
    for(int r = 0; r < rE; r++) {
        for (int c = 0; c < cE; c++){
            cout << smaze[r][c] ;
        } cout <<endl;
    }
}

int main(){
    Maze maze;

    maze.setUp();
    

    if (! testSlidable(maze)){
        cout << "Current maze is NOT slidable." << endl;
        return 1;
    }
    char** sMaze = maze.getSimpleMatrix();

        for(int i = 0; i < maze.getRowCount(); i++){
            cout << "| ";
            for (int j = 0; j < maze.getColCount(); j++){
                cout << sMaze[i][j] << " " ;
                // cout << ((maze.getBoard()+i)+j) << " ";
            } cout << "|" << endl;
        }

    int x = 0;
    while(maze.stillActive() && x < 50){
        cout << "------------" << x << "------------" << endl;
        maze.getPriority();
        maze.doProgression();

        char** sMaze = maze.getSimpleMatrix();
        for(int i = 0; i < maze.getRowCount(); i++){
            cout << "| ";
            for (int j = 0; j < maze.getColCount(); j++){
                cout << sMaze[i][j] << " " ;
                // cout << ((maze.getBoard()+i)+j) << " ";
            } cout << "|" << endl;
        }
        vector<ActiveUnit*> va = maze.getActiveUnits();
    
        for(int v = 0;v < va.size(); v++) {
            cout << "LOOK HERE:" << va.at(v) -> getX() << "," << va.at(v) -> getY() << endl;
            printVector(va.at(v)->getPointVisited());
        } cout << endl;

        if(maze.getChange() == false){
            cout << "CHANGED OMG" << endl;
            maze.doRepositioning();
        }
        
        cout << "------------" << "END"<< x << "------------" << endl;
        x++;
    }
    

    return 0;
}
