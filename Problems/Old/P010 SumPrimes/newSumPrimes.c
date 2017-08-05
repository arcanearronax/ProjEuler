#include <stdio.h>
#define LIMIT 2000000
#include <time.h>

//create the array and zero it out
int numArray[LIMIT] = {0};

/*
*Create an array of numbers of the form 3+2n.
*Multiply numbers in the array by 1-LIMIT/(number in array),
*zero out any number which appears in the array
*/
void main() {

    //time tracking variables
    clock_t begin, end;
    double runtime;

    //start the clock counter
    begin=clock();

    //counter and sum=2 (since 2 won't be checked)
    int i, j;
    unsigned long long sum=2;

    //add 3+2n to the array, this will cover primes >=3
    for (i=3; i<LIMIT; i+=2) {
        numArray[i] = i;
    }

    //outer loop will select a number from the array
    for (i=3; i<LIMIT; i+=2) {
        //continue operating with the number if non-zero
        if (numArray[i] != 0) {
            //muliply number in array by j, if product is in array, 0 out
            for (j=2; j*i < LIMIT; j++) {
               numArray[i*j] = 0;
            }
            sum += numArray[i];
        }
    }

    end=clock();

    printf("The sum is %llu \n", sum);

    
    runtime = (double) (end - begin) / CLOCKS_PER_SEC;

    printf("Runtime is %lf \n", runtime);

    printf("size = %lu \n", sizeof(sum));
}
