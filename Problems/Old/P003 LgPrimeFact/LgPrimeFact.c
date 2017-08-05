#include <stdio.h>

void main() {

    long val, i=2, j=2, div=1, prime=1;

    printf("What number would you like to find the largest prime factor of? ");

    scanf("%ld", &val);

    //loop to produce prime candidates
    for(i = val; i > 1; i--) {
        if (val % i == 0) {
            if (isPrime(i) == 1) {
                prime=i;
                break;
            }
        }
    }

    printf("The largest prime factor is %ld \n", prime);
}

//test to see if the number is prime
int isPrime(long cand) {

    long i, prime=1;

    for (i=2; i <= cand / 2; i++) {
        if (cand % i == 0) {
            prime=0;
        }
    }
    //return 1 if prime, 0 if composite
    return prime;
}
