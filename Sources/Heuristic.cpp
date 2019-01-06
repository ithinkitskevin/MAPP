#include "../Headers/Heuristic.h"
#include "../Headers/Maze.h"

#include <math.h>
#include <iostream>
#include <queue>

struct queueNode { 
    int x;
    int y;
    int dist; 
}; 

float straightLine(int p_x, int p_y, int d_x, int d_y){
    /* 
        p_x : Player's x position 
        p_y : Player's y position
        d_x : Destination's x position
        d_y : Destination's y position

        returns the distance between the two points via distance formula rounded to two decimal points
    */
    return roundf( sqrt(pow((p_x - d_x),2) + pow((p_y - d_y),2)) * 100 ) / 100;
}

// bool isValid(int row, int col, int rowCount, int colCount)  {  
//     return (row >= 0) && (row < rowCount) && 
//            (col >= 0) && (col < colCount); 
// } 

// // TODO: Fix later - Works, but it's a reused code from Path.cpp
// int manhattanDistance(int s_x, int s_y, int d_x, int d_y, Maze maze){
//     int rowCount = maze.getRowCount();
//     int colCount = maze.getColCount();
    
//     char ** mat = maze.getSimpleMatrix();

//     if (!mat[s_x][s_y] || !mat[d_x][d_y]) {
//         return -1; 
//     }
  
//     bool visited[rowCount][colCount]; 
//     memset(visited, false, sizeof visited); 
      
//     visited[s_x][s_y] = true; 
  
//     queue<queueNode> q; 
      
//     queueNode s = {s_x, s_y, 0}; 
//     q.push(s); 
  
//     const int rowNum[] = {-1, 0, 0, 1}; 
//     const int colNum[] = {0, -1, 1, 0}; 

//     while (!q.empty()) { 
//         queueNode curr = q.front(); 
//         int currX = curr.x;
//         int currY = curr.y;

//         if ((currX == d_x) && (currY == d_y)) {
//             return curr.dist; 
//         }

//         q.pop(); 
  
//         for (int i = 0; i < 4; i++) { 
//             int row = currX + rowNum[i]; 
//             int col = currY + colNum[i]; 
              
//             if (isValid(row, col, rowCount, colCount) && mat[row][col] && !visited[row][col] && mat[row][col] != '1') { 
//                 visited[row][col] = true; 
//                 queueNode Adjcell = { row, col, curr.dist + 1 }; 
//                 q.push(Adjcell); 
//             } 
//         } 
//     } 
  
//     return -1; 
// }