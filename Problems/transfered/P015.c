#include <stdio.h>
#include "../grid.c"
#define MAXX 20
#define MAXY 20

void main() {
    //Create the Grid struct
    Grid g;
    g = buildGrid(0,0,MAXX,MAXY);
    //Create a pointer for a Grid
    Grid *point;
    //Give the pointer the struct's address
    point = (Grid *)&g;

    double score = lattPaths(point);
    printf("Result: %.0lf\n", score);

}
