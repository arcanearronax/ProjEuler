#include <stdio.h>
#define LIMIT 1000

void main() {

    //declare the fib sequences, index counter, and loops
    int fib1[LIMIT] = {0};
    int fib2[LIMIT] = {0};
    int fibCurr[LIMIT] = {0};
    int index=2, i, j;

    //declare the initial values
    fib1[LIMIT-1] = 1;
    fib2[LIMIT-1] = 1;

    //while loop ends when fibCurr has 1000 digits
    while (fibCurr[0] == 0) {
        //for loop will add the values
        for (i=LIMIT-1; i>=0; i--) {
            fibCurr[i] = fib1[i] + fib2[i];
        }
        index++;
        //fix any instances of fibCurr[i] > 9
        for (i=LIMIT-1; i>=0; i--) {
            if (fibCurr[i] > 9) {
                fibCurr[i] -= 10;
                fibCurr[i-1]++;
            }
        }
        //move numbers
        for (i=LIMIT-1; i>=0; i--) {
            fib1[i] = fib2[i];
            fib2[i] = fibCurr[i];
        }
    }

    printf("The index is %d \n", index);
}
