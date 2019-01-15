#include "../Headers/Maze.h"
#include "../Headers/Piece.h"
#include "../Headers/Path.h"
#include "../Headers/Heuristic.h"


#include <iostream>

using namespace std;

const char WALL = '1';
const char SPACE = ' ';
const char SOLVED = '0';

Maze::Maze() {
    this -> board[0][0] = new Piece(0,0,SPACE);
    this -> board[0][1] = new Piece(0,1,'C');
    this -> board[0][2] = new Piece(0,2,'D');
    this -> board[0][3] = new Piece(0,3,SPACE);

    this -> board[1][0] = new Piece(1,0,SPACE);
    this -> board[1][1] = new Piece(1,1,SPACE);
    this -> board[1][2] = new Piece(1,2,SPACE);
    this -> board[1][3] = new Piece(1,3,SPACE);

    this -> board[2][0] = new Piece(2,0,WALL);
    this -> board[2][1] = new Piece(2,1,'A');
    this -> board[2][2] = new Piece(2,2,'B');
    this -> board[2][3] = new Piece(2,3,WALL);

    this -> board[3][0] = new Piece(3,0,SPACE);
    this -> board[3][1] = new Piece(3,1,'a');
    this -> board[3][2] = new Piece(3,2,'b');
    this -> board[3][3] = new Piece(3,3,SPACE);

    this -> board[4][0] = new Piece(4,0,SPACE);
    this -> board[4][1] = new Piece(4,1,'c');
    this -> board[4][2] = new Piece(4,2,'d');
    this -> board[4][3] = new Piece(4,3,SPACE);
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
    if(maze[x][y] == ' ') {
        return true;
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
void Maze::sortActivePieces(){
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
    
    printVectors(alterPath); 

    if(alterPath.size() == 0) {
        // Check, since it doesn't have any alterPath, if you can place the blockingPiece in either four direction
        int x[4] = {-1, 0, 1, 0};
        int y[4] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++){
            int blockX = curr -> getNextMove().getX() + x[i];
            int blockY = curr -> getNextMove().getY() + y[i];
            if(isSpace(blockX, blockY, this -> getSimpleMatrix())){
                // Also, set note that the piece has been moved
                //TODO: Seriously, make a hashmap of this...
                for(int r = 0; r <activePieces.size(); r++) {
                    int actX = activePieces.at(r) -> getX();
                    int actY = activePieces.at(r) -> getY();

                    if(actX == curr -> getNextMove().getX()
                            && actY == curr -> getNextMove().getY()){
                        
                        if(activePieces.at(r) -> getOriginal().getX() == -1 && 
                            activePieces.at(r) -> getOriginal().getY() == -1){
                            
                            cout << "NEW ORIGINAL FOR " << (char)activePieces.at(r) -> getValue() << ": " << actX << ", " << actY << endl;
                            activePieces.at(r) -> setOriginal(Point(actX, actY));
                            activePieces.at(r) -> setMovedPath(Point(actX, actY));

                        }
                        activePieces.at(r) -> setMovedPath(Point(blockX, blockY));
                        placePiece(activePieces.at(r), blockX, blockY);
                        cout << "BROUGHT PIECE " << (char)activePieces.at(r) -> getValue() << ": " << activePieces.at(r) -> getX() << ", " << activePieces.at(r) -> getY() << endl;
                    }
                }
                cout << "PLACED " << blockX << "," << blockY <<  ","  << (char)this -> board[blockX][blockY] -> getValue() << endl;

                break;
            }
        }

        return true;
    }
    for(int i = 0; i < alterPath.size(); i++) {
        cout << "AT "<< i << " "; 
        // if(isPrivateZone(curr, alterPath.at(i))) {
        //     return false;
        // } 
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
                vector<Point> movedPath = curr -> getMovedPath();
                reverse(movedPath.begin(), movedPath.end()); // Simpler... TODO: FIX so that the iterator does it
                int eraseIndex = 0;
                for(int i = 0; i < movedPath.size() - 1; i++) {
                    int destX = movedPath.at(i+1).getX();
                    int destY = movedPath.at(i+1).getY();

                    int origX = movedPath.at(i).getX();
                    int origY = movedPath.at(i).getY();

                    cout << "ORIG" << origX << "," << origY << "\tDEST" << destX<<","<<destY <<","<< (char) board[destX][destY] -> getValue()<<endl;

                    if(isSpace(destX, destY, this -> getSimpleMatrix())){
                        cout << destX << ", " << destY << endl;
                        this -> placePiece(curr , destX, destY);  
                        cout << "MOVED: " << curr -> getX() << "," << curr-> getY() << ","  << curr -> getValue() << endl;                     
                    } else {
                         // Also, now erase the movedPath            
                        break;
                    }
                }
                curr -> eraseMovedPath(eraseIndex, 0);

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

                change = true;
            } else if (isAlterPathAvail(curr -> getAlterPathAt(curr -> getX(), curr -> getY(), false), this -> getSimpleMatrix())) {
                cout << "Alternate Path" << endl;
                // For alternate path...
                // So if there's nothing along the alternatePath, then move the active unit along the alternatePath...
                vector<Point> alterPath = curr -> getAlterPathAt(curr -> getX(), curr -> getY(), false);
                placePiece(curr, alterPath.at(alterPath.size()-1).getX(), alterPath.at(alterPath.size()-1).getY());
                
                cout << "Curr Point" << curr -> getX() << ", " << curr -> getY() << endl;
                change = true;
            } else {
                // Do something else
                cout << "Else - Do Nothing" << endl;
                vector<Point> alterPath = curr -> getAlterPathAt(curr -> getX(), curr -> getY(), false);
                printVectors(alterPath);
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

void Maze::doRegression(){
    // Reverse 
    vector<ActiveUnit*> r = this -> activePieces;
    for(int a = 0; a < r.size(); a++){
        // int d = straightLine(r.at(a)->getX(), r.at(a)->getY(), r.at(a)->getDest().getX(), r.at(a)->getDest().getY());
        cout << r.at(a) -> toString() << endl;
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
        temp->createPath(currPath);
        temp->setAlterConnect(true);       
        
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