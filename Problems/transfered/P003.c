#include <stdio.h>
#include "../arithmetic.c"
#define NUM 600851475143

void main() {

	//double *factor;

    //factor = getFactors(NUM);

    printf("Result: %.0lf\n",largestPrimeFactor(NUM));
}
