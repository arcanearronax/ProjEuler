#include <stdio.h>

void main() {

    int sum=0, i;

    for (i=1; i<10000; i++) {
        if (isAmicable(i) == 1) {
            printf("%d \n", i);
            sum += i;
        }
    }

    printf("The answer is %d \n", sum);
}

int isAmicable(val) {

    int i, sum1=0, sum2=0, amic=0;

    for (i=1; i <= val / 2; i++) {
        if (val % i == 0) {
            sum1 += i;
        }
    }

    for (i=1; i <= sum1 / 2; i++) {
        if (sum1 % i == 0) {
            sum2 += i;
        }
    }
    
    if (val == sum2) {
        amic = 1;
    }
    
    if (val == sum1) {
        amic = 0;
    }
    
    return amic;
}
