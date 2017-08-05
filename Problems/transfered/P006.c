#include <stdio.h>
#include "../arithmetic.c"
#define MIN 1
#define MAX 100

void main() {

    printf("Result: %d\n", (int) (squareSum(MIN,MAX)-sumSquare(MIN,MAX)));
}
