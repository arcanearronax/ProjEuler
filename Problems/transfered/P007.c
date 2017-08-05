#include <stdio.h>
#include "../arithmetic.c"
#define INDEX 10001

void main() {
    double res = primeByIndex((int) INDEX);
    printf("Result: %.0lf\n", res);
}
