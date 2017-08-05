#include <stdio.h>

#define POW 100
#define SIZE 200

/*
* Most of this was taken from P016
* then a bit of modification occurred
*/

void main() {

    int num[SIZE], i, j, pos, sum=0, index;

    //Setup the array, include 1 for clear reasons
    for (i=0; i<SIZE; i++) {
        num[i] = 0;
    }
    num[SIZE-1] = 1;

    //k loop to run process repeatedly
    for (pos=POW; pos>0; pos--) {
        //i loop to multiply the array values by 2
        for (i=SIZE-1; i>=0; i--) {
            num[i] *= pos;
            }
        for (i=SIZE-1; i>=0; i--) {
            num[i-1] += (num[i] / 10);
            num[i] = num[i] % 10;
        }
    }

    for (i=0; i<SIZE; i++) {
        if (num[i] != 0) {
            index = i;
            break;
        }
    }

    for (i=index; i<SIZE; i++) {
        printf("%d", num[i]);
    }
    printf("\n");

    for (i=0; i<SIZE; i++) {
        sum +=num[i];
    }

    printf("Sum: %d\n", sum);
}

