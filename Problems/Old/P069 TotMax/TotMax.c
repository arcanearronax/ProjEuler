#include <stdio.h>
#define BOUND 50000

/*
*Create an array of numbers then an array of primes,
*remove the primes from the first array, find the 
*totients, then make the comparison
*/

void main() {

    int i, j, num=1, phi=0, temp=0, nums[BOUND]={0}, primes[BOUND]={0};
    float quot=0;

    //create arrays, a full and prime array
    for (i=2; i<BOUND; i++) {
        nums[i]=i;
        primes[i]=i;
    }

    //remove composite number from prime array
    for (i=2; i<BOUND; i++) {
        for (j=2; j<i; j++) {
            if (primes[i] % j == 0) {
                primes[i] = 0;
                break;
            }
        }
    }

    //remove primes from nums array, calculate totients
    for (i=4; i<BOUND; i++) {
        if (primes[i] != 0) {
            nums[i] = 0;
        }
        printf("%d \n", nums[i]);
    } 

    //calculate the totient
    for (i=4; i<BOUND; i++) {
        if (nums[i] != 0) {
            temp=totient(nums[i]);
            if ((((float) nums[i])/((float) temp)) > quot) {
                num=nums[i];
                phi=temp;
                quot = (((float) nums[i])/((float) temp));
            }
        }
    }

    printf("The answer is %d \n", num);
}

//check to see if val is prime, 1 if yes, 0 if no
int isPrime(int val) {
    
    int i, prime=1;

    for (i=2; i<val/2; i++) {
        if (val % i == 0) {
            prime=0;
            break;
        }
    }

    return prime;
}

//determine the totient of num
int totient(int num) {

    int i, temp=1;

    for (i=2; i<=num/2; i++) {
        if (num % i != 0) {
            temp++;
        }
    }

    return temp;
}
