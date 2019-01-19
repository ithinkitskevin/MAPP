#include "../Headers/Path.h"
#include "../Headers/Maze.h"
#include "../Headers/Point.h"

#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
#include <math.h>
#include <ctime>
using namespace std;


bool isValid(int row, int col, int rowCount, int colCount, char ** maze, char dest)  {  
    if(isalpha(maze[row][col])){
        if(isupper(maze[row][col]) && maze[row][col] != dest) {
            return false;
        }
    }
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

// Determine priority (in the priority queue)
bool operator<(const Point & a, const Point & b) 
{
  return a.getPriority() > b.getPriority();
}

// Got this from another source...
vector<Point> getAStarPath(Point src, Point dest, char** maze, int rowCount, int colCount, Point alterPath){
    priority_queue<Point> pq[2]; // list of open (not-yet-tried) nodes
    static int pqi; // pq index
    Point* n0;
    Point* m0;
    static int i, j, x, y, xdx, ydy;
    static char c;
    pqi=0;
    vector<Point> def;

    const int n = rowCount;
    const int m = colCount;

    int closed_nodes_map[n][m]; // map of closed (tried-out) nodes
    int open_nodes_map[n][m]; // map of open (not-yet-tried) nodes
    int dir_map[n][m]; // map of directions

    static int dx[4]={1, 0, -1, 0};
    static int dy[4]={0, 1, 0, -1};

    // reset the node maps
    for(y=0;y<m;y++)
    {
        for(x=0;x<n;x++)
        {
            closed_nodes_map[x][y]=0;
            open_nodes_map[x][y]=0;
        }
    }

    // create the start node and push into list of open nodes
    n0=new Point(src.getX(), src.getY(), 0, 0);
    n0->updatePriority(dest.getX(), dest.getY());
    pq[pqi].push(*n0);
    open_nodes_map[x][y]=n0->getPriority(); // mark it on the open nodes map

    // A* search
    while(!pq[pqi].empty()){
        // get the current node w/ the highest priority
        // from the list of open nodes
        n0=new Point( pq[pqi].top().getX(), pq[pqi].top().getY(), 
                     pq[pqi].top().getLevel(), pq[pqi].top().getPriority());

        x=n0->getX(); y=n0->getY();

        pq[pqi].pop(); // remove the node from the open list
        open_nodes_map[x][y]=0;
        // mark it on the closed nodes map
        closed_nodes_map[x][y]=1;

        // quit searching when the goal state is reached
        //if((*n0).estimate(xFinish, yFinish) == 0)
        if(x==dest.getX() && y==dest.getY())  {   
            // generate the path from finish to start
            // by following the directions
            string path="";
            vector<Point> fin;
            while(!(x==src.getX() && y==src.getY())) {
                fin.push_back(Point(x,y));
                j=dir_map[x][y];
                c='0'+(j+4/2)%4;
                path=c+path;
                x+=dx[j];
                y+=dy[j];
            }
            fin.push_back(Point(src.getX(), src.getY()));

            // garbage collection
            delete n0;
            // empty the leftover nodes
            while(!pq[pqi].empty()) pq[pqi].pop();       
            return fin;
        }

        // generate moves (child nodes) in all possible directions
        for(i=0;i<4;i++)
        {
            xdx=x+dx[i]; ydy=y+dy[i];

            if(!(xdx<0 || xdx>n-1 || ydy<0 || ydy>m-1 || maze[xdx][ydy]=='1' 
                || closed_nodes_map[xdx][ydy]==1))
            {
                // generate a child node
                m0=new Point( xdx, ydy, n0->getLevel(), 
                             n0->getPriority());
                m0->nextLevel(i);
                m0->updatePriority(dest.getX(), dest.getY());

                // if it is not in the open list then add into that
                if(open_nodes_map[xdx][ydy]==0)
                {
                    open_nodes_map[xdx][ydy]=m0->getPriority();
                    pq[pqi].push(*m0);
                    // mark its parent node direction
                    dir_map[xdx][ydy]=(i+4/2)%4;
                }
                else if(open_nodes_map[xdx][ydy]>m0->getPriority())
                {
                    // update the priority info
                    open_nodes_map[xdx][ydy]=m0->getPriority();
                    // update the parent direction info
                    dir_map[xdx][ydy]=(i+4/2)%4;

                    // replace the node
                    // by emptying one pq to the other one
                    // except the node to be replaced will be ignored
                    // and the new node will be pushed in instead
                    while(!(pq[pqi].top().getX()==xdx && 
                           pq[pqi].top().getY()==ydy))
                    {                
                        pq[1-pqi].push(pq[pqi].top());
                        pq[pqi].pop();  
                    }
                    pq[pqi].pop(); // remove the wanted node
                    
                    // empty the larger size pq to the smaller one
                    if(pq[pqi].size()>pq[1-pqi].size()) pqi=1-pqi;
                    while(!pq[pqi].empty())
                    {                
                        pq[1-pqi].push(pq[pqi].top());
                        pq[pqi].pop();       
                    }
                    pqi=1-pqi;
                    pq[pqi].push(*m0); // add the better node instead
                }
                delete m0; // garbage collection
            }
        }
        delete n0; // garbage collection
    }
    return def; // no route found

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

