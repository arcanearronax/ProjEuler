#include <stdio.h>

void main() {

    //div=#of divisors, triang=the number, increase increments triang
    int div, triang, i, increase=0;

    printf("Please input the minimum number of divisors: ");
    scanf("%d", &div);

    //increase the triangle number while numDiv < 500
    do {  
        increase++;
        triang += increase;
        printf("Triangle=%d \n", triang);
    } while (numDiv(triang) < div);

    printf("The number is %d \n", triang);
}

//Finds the number of divisors of numDiv
int numDiv(int triang) {
    
    int count=1, i;
    
    //Loop to find which numbers divide triang
    for (i=1; i<=triang/2; i++) {
        if (triang % i == 0) {
            count++;
        }
    }
    return count;
}
