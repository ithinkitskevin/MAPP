#ifndef PATH_H
#define PATH_H

#include "Point.h"
#include "Maze.h"
#include <string>

vector<Point> getbfsPath(Point, Point , char**, int, int , Point);
vector<Point> getAStarPath(Point, Point , char**, int, int , Point);

#endif // PATH_H
