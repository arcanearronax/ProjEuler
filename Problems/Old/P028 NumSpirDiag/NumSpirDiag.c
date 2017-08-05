#include <stdio.h>
#define SIZE 1001

void main() {

    int i=SIZE/2, j=SIZE/2, i1, j1, move=1, right=1, down=1, count=2;
    int grid[SIZE][SIZE]={0};
    long sum=-1;

    //fill in starting position
    grid[i][j] = 1;

    //fill in the grid with numbers
    while (count <= SIZE*SIZE) {
        //check to see if we need to go right or left
        if (right == 1) {
            //fill in the numbers going right
            for (i1=0; i1<move; i1++) {
                if (count > SIZE*SIZE) {
                    break;
                }
                j++;
                grid[i][j] = count;
                count++;
                //printf("%d, \n", count);
            }
        } else {
            //fill in the numbers going left
            for (i1=0; i1<move; i1++) {
                if (count > SIZE*SIZE) {
                    break;
                }
                j--;
                grid[i][j] = count;
                count++;
                //printf("%d, \n", count);
            }
        }
        if (count > SIZE*SIZE) {
            break;
        }
        //change the horizontal direction
        if (right == 1) {
            right=0;
        } else {
            right=1;
        }
        //check to see if we need to go down or up
        if (down == 1) {
            //fill in the numbers going down
            for (j1=0; j1<move; j1++) {
                if (count > SIZE*SIZE) {
                    break;
                }
                i++;
                grid[i][j] = count;
                count++;
                //printf("%d, \n", count);
            }
        } else {
            //fill in the numbers going up
            for (j1=0; j1<move; j1++) {
                if (count > SIZE*SIZE) {
                    break;
                }
                i--;
                grid[i][j] = count;
                count++;
                //printf("%d, \n",count);
            }
        }
        //change the vertical direction
        if (down == 1) {
            down=0;
        } else {
            down=1;
        }
        move++;
    }
    
    //add up left-down diagonal
    for (i=0; i<SIZE; i++) {
        sum += grid[i][i];
    }

    //add up right-up diagonal
    for (i=0; i<SIZE; i++) {
        sum += grid[SIZE-1-i][i];
    }

    printf("%ld \n", sum);
}
