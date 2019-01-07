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
        3. 
    */      
    maze.setUp();
    for(int i = 0; i < maze.getActiveUnits().size(); i++){
        printVector(maze.getActiveUnits().at(i).getPath());
        cout << endl;
        printVector(maze.getActiveUnits().at(i).getAlterPath());
        cout << endl;
        cout << endl;
    }
    
    // First, my rule. All units MUST have a path. 
    for(int i = 0; i < maze.getActiveUnits().size(); i++){
        if(maze.getActiveUnits().at(i).getPath().size() == 0){
            return false;
        }
    }
    // Second rule. Alternate Connectivity.
    for(int i = 0; i < maze.getActiveUnits().size() - 1; i++){
        if(maze.getActiveUnits().at(i).getPath().size() == maze.getActiveUnits().at(i).getAlterPath().size()){
            return false;
        }
    }

    return true;
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
        for (int j = 0; j < maze.getColCount(); j++){
            cout << sMaze[i][j] << " " ;
        } cout << endl;
    }

    return 0;
}
