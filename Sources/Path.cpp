#include "../Headers/Path.h"
#include "../Headers/Maze.h"
#include "../Headers/Point.h"

#include <iostream>
#include <queue>

using namespace std;

bool isValid(int row, int col, int rowCount, int colCount, char ** maze, char dest)  {  
    // if(isalpha(maze[row][col])){
    //     if(isupper(maze[row][col]) && maze[row][col] != dest) {
    //         cout << "UPPER At coord " << row << ", " << col << " - " << maze[row][col] << endl;  
    //         return false;
    //     }
    // }
    return (row >= 0) && (row < rowCount) && (col >= 0) && (col < colCount) && maze[row][col] != '1';
     
} 

bool getbfsPathUtil(char ** maze, int currX, int currY, Point dest, int xLimit, int yLimit, vector<Point> &path){
    if (currX == dest.getX() && currY == dest.getY()){
        // cout << "Found::" << currX << "," << currY << "\tsize: " << path.size() << endl;
        path.push_back(Point(currX, currY));
        return true;
    }

    if (isValid(currX, currY, xLimit, yLimit, maze, maze[dest.getX()][dest.getY()])){
        maze[currX][currY] = '1';
        path.push_back(Point(currX, currY));

        if(getbfsPathUtil(maze, currX+1, currY, dest, xLimit, yLimit, path)){
            return true;
        } 
        if(getbfsPathUtil(maze, currX, currY+1, dest, xLimit, yLimit, path)){
            return true;
        } 
        if(getbfsPathUtil(maze, currX+1, currY, dest, xLimit, yLimit, path)){
            return true;
        } 
        if(getbfsPathUtil(maze, currX, currY-1, dest, xLimit, yLimit, path)){
            return true;
        } 
        maze[currX][currY] = ' ';
        // path.pop_back();

        cout << path.size() << " since not found" << endl;

            // Find what we added in the path and remove it
                // TODO: Optimize into a hashlist (if that's a thing...)
            for(int i = 0; i < path.size(); i++){
                if(path.at(i).getX() == currX && path.at(i).getY() == currY){
                    cout << "REMOVED!!!" << path.at(i).getX() << ", " << path.at(i).getY() << endl;
                    path.erase(path.begin() + i );
                }
            }
            
            return false;
        
    }
    
    return false;
}

struct queueNode { 
    int x;
    int y;
    int predX;
    int predY;
}; 

vector<Point> getAStarPath(){
    vector<Point> path;



    return path;
}

vector<Point> getbfsPath(Point src, Point dest, char** maze, int rowCount, int colCount, Point alterPath){
    vector<Point> path;
         
    char ** mat = maze;
    
    if (!mat[src.getX()][src.getY()] || !mat[dest.getX()][dest.getY()]) {
        return vector<Point>(); 
    }
    
    queue<queueNode> queue; 
    vector<queueNode> predecessor;

    queueNode s = {src.getX(), src.getY()};
    queue.push(s); 
  
    const int rowNum[] = {-1, 0, 0, 1}; 
    const int colNum[] = {0, -1, 1, 0}; 

    bool visited[rowCount][colCount]; 
    memset(visited, false, sizeof visited); 
    visited[src.getX()][src.getY()] = true; 
    if(alterPath.getX() != -1 && alterPath.getY() != -1){
        visited[alterPath.getX()][alterPath.getY()] = true;
    }

    char destChar = maze[dest.getX()][dest.getY()];

    //TODO: SERIOUSLY OPTIMIZE THIS, IT HURTS TO LOOK AT
    while (!queue.empty()) { 
        queueNode curr = queue.front(); 
        queue.pop();
        int currX = curr.x;
        int currY = curr.y;
        // cout << currX << "," << currY << endl;
        predecessor.push_back(curr);

        if (! (currX == dest.getX() && currY == dest.getY()) ) {  
            queueNode nextPosition = {currX + 1, currY, currX, currY};
            if (isValid(currX+1, currY, rowCount, colCount, mat, destChar) && visited[currX+1][currY] == false){
                queue.push(nextPosition);
                visited[currX+1][currY] = true;
            }
            queueNode nextPosition2 = {currX , currY + 1, currX, currY};
            if (isValid(currX, currY + 1, rowCount, colCount, mat, destChar) && visited[currX][currY+1] == false){
                queue.push(nextPosition2);
                visited[currX][currY + 1] = true;
            }
            queueNode nextPosition3 = {currX - 1, currY, currX, currY};
            if (isValid(currX-1, currY, rowCount, colCount, mat, destChar) && visited[currX-1][currY] == false){
                queue.push(nextPosition3);
                visited[currX-1][currY] = true;
            }
            queueNode nextPosition4 = {currX, currY-1, currX, currY};
            if (isValid(currX, currY-1, rowCount, colCount, mat, destChar) && visited[currX][currY-1] == false){
                queue.push(nextPosition4);
                visited[currX][currY-1] = true;
            }
        } else {
            break;
        }
    }  
    
    int testX = -1;
    int testY = -1;
    reverse(predecessor.begin(), predecessor.end());
    for(int i = 0; i < predecessor.size(); i++) {
        // cout << predecessor.at(i).x << " and " << predecessor.at(i).y << " - " << predecessor.at(i).predX << " and " << predecessor.at(i).predY << endl; 
        // cout << testX << ", " << testY << endl; 
        if(testX == -1 && testY == -1){
            testX = predecessor.at(i).predX;
            testY = predecessor.at(i).predY;
            path.push_back(Point(predecessor.at(i).x, predecessor.at(i).y));
            continue;
        } 
        if(testX == predecessor.at(i).x && testY == predecessor.at(i).y){
            path.push_back(Point(predecessor.at(i).x, predecessor.at(i).y));
            testX = predecessor.at(i).predX;
            testY = predecessor.at(i).predY;
        }
    }
    reverse(path.begin(), path.end());

    return path;
}

