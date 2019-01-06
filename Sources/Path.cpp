#include "../Headers/Path.h"
#include "../Headers/Maze.h"
#include "../Headers/Point.h"

#include <iostream>
#include <queue>

using namespace std;

bool isValid(int row, int col, int rowCount, int colCount, char ** maze)  {  
    return (row >= 0) && (row < rowCount) && (col >= 0) && (col < colCount) && maze[row][col] != '1'; 
} 

bool getbfsPathUtil(char ** maze, int currX, int currY, Point dest, int xLimit, int yLimit, vector<Point> &path){
    if (currX == dest.getX() && currY == dest.getY()){
        // cout << "Found::" << currX << "," << currY << "\tsize: " << path.size() << endl;
        path.push_back(Point(currX, currY));
        return true;
    }

    if (isValid(currX, currY, xLimit, yLimit, maze)){
        maze[currX][currY] = '1';
        path.push_back(Point(currX, currY));

        if(getbfsPathUtil(maze, currX+1, currY, dest, xLimit, yLimit, path)){
            return true;
        } 
        if(getbfsPathUtil(maze, currX-1, currY, dest, xLimit, yLimit, path)){
            return true;
        } 
        if(getbfsPathUtil(maze, currX, currY+1, dest, xLimit, yLimit, path)){
            return true;
        } 
        if(getbfsPathUtil(maze, currX, currY-1, dest, xLimit, yLimit, path)){
            return true;
        } 
        
            // Find what we added in the path and remove it
                // TODO: Optimize into a hashlist (if that's a thing...)
            for(int i = 0; i < path.size(); i++){
                if(path.at(i).getX() == currX && path.at(i).getY() == currY){
                    cout << "REMOVED!!!" << path.at(i).getX() << ", " << path.at(i).getY() << endl;
                    path.erase(path.begin() + i + 1);
                }
            }
            return false;
        
    }
    
    return false;
}

vector<Point> getbfsPath(Point src, Point dest, Maze maze){
    vector<Point> path;

    char ** mat = maze.getSimpleMatrix();

    if (! getbfsPathUtil(mat, src.getX(), src.getY(), dest, maze.getRowCount(), maze.getColCount(), path)) {
        return vector<Point>();
    }
    
    return path;
}
