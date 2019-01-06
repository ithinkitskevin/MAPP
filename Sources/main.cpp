#include <iostream>
#include <vector>
#include <string>
#include "../Headers/Maze.h"
#include "../Headers/Heuristic.h"
#include "../Headers/Path.h"
#include "../Headers/Point.h"

using namespace std;

/*
List of commands
g++ -c Heuristic.cpp Piece.cpp main.
cpp && g++ Heuristic.o Piece.o main.o -o my_program && ./my_progr
am
rm Heuristic.o main.o my_program
*/

bool testSlidable(){
    /*
        1. Alternate Connectivity. 
            There needs to exist alternate path for all path location EXCEPT the last one
        2. Initial Blank - In the path, the first space needs to be empty
            There needs to exist a path in general
        3. 
    */  


    return true;
}

int main(){
    Maze maze;
    // maze.toString();

    // if (! testSlidable()){
    //     cout << "Current maze is NOT slidable." << endl;
    //     return 1;
    // }

    char** sMaze = maze.getSimpleMatrix();

    for(int i = 0; i < maze.getRowCount(); i++){
        for (int j = 0; j < maze.getColCount(); j++){
            cout << sMaze[i][j] << " " ;
        } cout << endl;
    }
    // cout << "------start------" << endl;
    vector<Point> ree = getbfsPath(Point(5,2), Point(1,6), maze); // B
    vector<Point> ree2 = getbfsPath(Point(5,1), Point(1,2), maze); // A

    return 0;
}
