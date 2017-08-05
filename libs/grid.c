#include <stdio.h>
#include "arithmetic.c"


typedef struct {
    int x;
    int y;
    int maxX;
    int maxY;
} Grid;

Grid buildGrid(int x, int y, int maxX, int maxY) {
    Grid grid;

    grid.x = x;
    grid.y = y;
    grid.maxX = maxX;
    grid.maxY = maxY;

    return grid;
}

int moveRight(Grid *grid) {

    int temp=1;

    if (grid->x >= grid->maxX) {
        temp=0;
    } else {
        grid->x += 1;
    }

    return temp;
}

int moveLeft(Grid *grid) {

    int temp=1;

    if (grid->x > 0) {
        grid->x -= 1;
    } else {
        temp=0;
    }

    return temp;
}

int moveDown(Grid *grid) {

    int temp=1;

    if (grid->y == grid->maxY) {
        temp=0;
    } else {
        grid->y+=1;
    }

    return temp;
}

int moveUp(Grid *grid) {

    int temp=1;

    if (grid->y > 0) {
        grid->y-=1;
    } else {
        temp=0;
    }

    return temp;
}

int gridCrawler(Grid *grid, int score) {
    printf("Position: (%d,%d) - score=%d\n", grid->x, grid->y, score);
    int temp;
    if (grid->x < grid->maxX) {
        temp = moveRight(grid);
        score = gridCrawler(grid, score);
        temp = moveLeft(grid);
    }

    if (grid->x == grid->maxX) {
        return score+1;
    }

    if (grid->y < grid->maxY) {
        temp = moveDown(grid);
        score = gridCrawler(grid,score);
        temp = moveUp(grid);
    }

    //if ((grid->x == grid->maxX) && (grid->y == grid->maxY)) {
    //    score++;
    //}
    return score;
}

//Number of paths equal to binomial coeff ( m+n   n)
double lattPaths(Grid *grid) {
    printf("LattPath: %d, %d\n", (grid->maxX+grid->maxY), grid->maxY);
    return binomCoeff((double)(grid->maxX+grid->maxY), (double)(grid->maxY));
}
