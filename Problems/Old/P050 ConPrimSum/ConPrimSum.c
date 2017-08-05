#include <stdio.h>
#define LIMIT 1000000
#define QUANT 78498

void main() {

    int i, j, k, max, sum, nums[LIMIT]={0}, primes[QUANT]={0};

    //add 2 to the array, since the loop will not
    nums[1]=2;

    //fill the array with numbers of the form 3+2n
    for (i=3; i<LIMIT; i+=2) {
        nums[i]=i;
    }

    //remove composite numbers from the array
    for (i=3; i<LIMIT; i++) {
        if (nums[i] != 0) {
            for (j=3; j*i < LIMIT; j++) {
                nums[i*j] = 0;
            }
        }
    }

    //create an array with only primes
    j=0;
    for (i=0; i<LIMIT; i++) {
        if (nums[i] > 0) {
            primes[j] = nums[i];
            j++;
            //printf("%d \n", primes[j-1]);
        }
    }
    
    //add sequence of primes, which decreases in length, and end when found
    for (i=550; i > 0; i--) {
        for (j=0; j<=QUANT-i; j++) {
            sum = 0;
            for (k=j; k<j+i; k++) {
                sum += primes[k];
                if (sum > LIMIT ) {
                    sum=0;
                    break;
                }
            }
            if ((sum != 0) && (isPrime(sum) == 1)) {
                printf("%d \n", sum);
                max=i;
                break;
            } 
        }
        if ((sum != 0) && (isPrime(sum) == 1)) {
            break;
        }
    }
    
    printf("The answer is %d \n", max);

}

//determine if val is prime, 1 if yes, 0 if no
isPrime(int val) {

    int i, prime=1;

    for (i=2; i < val / 2; i++) {
        if (val % i == 0) {
            prime=0;
            break;
        }
    }

    return prime;
}

