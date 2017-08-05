#include <stdio.h>

void main() {

    int bound, sum = 2, i, fib1 = 2, fib2 = 3, temp;

    printf("What upper bound do you wish to use? ");
    scanf("%d", &bound);

    while(fib2 <= bound) {
         if (fib2 % 2 == 0) {
            sum += fib2;
        } else {
            sum = sum;
        }
        temp = fib1;
        fib1 = fib2;
        fib2 = temp + fib2;
    }
    
    printf("The sum of the even fibonacci numbers less than the bound is %d \n", sum);

}
