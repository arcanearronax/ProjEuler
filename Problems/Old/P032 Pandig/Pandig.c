#include <stdio.h>
#include <math.h>

void main() {

    long i, j, sum=0l;

    for (i=1l; i<10l; i++) {
        for (j=1l; j<10l; j++) {
            if (numSize(i,0)+numSize(j,0)+numSize(i*j,0) == 9) {
                if (isPan(i, j) == 1) {
                    sum+= (long) (i*j);
                }
            }
        }
    }

    printf("%ld \n", sum);

}

//calculate the size of the number
int numSize(long val, int size) {

    //recursive, submitting 1/10th of the value to count digits
    if (val/10l >= 1l) {
        size++;
        size = numSize(val/10l, size);
    } else {
        size++;
    }

    return size;
}

//chack to see if i, j, i*j concat is pandigital
int isPan(long val1, long val2) {

    int i, j=0, identity[9], copy=0, count, yes=0;

    for (i=0; i<numSize(val1,0); i++) {
        identity[j] = calcDig(i, numSize(val1,0), val1);
    }

    for (i=0; i<numSize(val2,0); i++) {
        identity[j] = calcDig(i, numSize(val2,0), val2);
    }

    for (i=0; i<numSize(val1*val2,0); i++) {
        identity[j] = calcDig(i, numSize(val1*val2,0), val1*val2);
    }

    for (i=1; i<10; i++) {
        count=0;
        for (j=0; j<9; j++) {
            if (identity[j] == i) {
                count++;
            }
        }
        if (count == 1) {
            yes++;
        }
    }

    return (yes/9);
}

int calcDig(int i, int size, int val) {
    int temp, dum;
    //calculate a single digit
    if (i == 0) {
        temp = val / pow(10, size - i - 1);
    } else {
        temp = val /  pow(10, size - i - 1);
        dum = (val /  pow(10, size -i));
        temp -= 10 * dum;
    }
    return temp;
}
