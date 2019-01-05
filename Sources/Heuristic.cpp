#include "../Headers/Heuristic.h"
#include <math.h>

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