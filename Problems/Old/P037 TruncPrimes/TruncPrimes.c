#include <stdio.h>

void main() {

    int i, j, num[10]={0}, primes[1000000]={0}, temp;

    //build an array of prime numbers
    for (i=11; i<1000000; i++) {
        if (isPrime(i) == 1) {
            primes[i]=i;
        }
    }

    //determine if a number is truncprime l2r or not
    for

}

isPrime(int val) {

    int i, prime=1;

    for (i=2; i <= val / 2; i++) {
        if (val % i == 0) {
            prime=0;
        }
    }

    return prime;
}

//calculate the i'th digit of val
int calcDigit(int i, int size, int val) {
    int temp, dum;
    //calculate a single digit
    if (i == 0) {
        temp = val / pow(10, size - i - 1);
    } else {
        temp = val /  pow(10, size - i - 1);
        dum = (val /  pow(10, size -i));
        temp -= 10 * dum;
    }
    return temp;
}

//calculate the size of a number
int numSize(int val, int size) {

    int i;

    //recursive, submitting 1/10th of the value to count digits
    if (val/10 >= 1) {
        size++;
        size = numSize(val/10, size);
    } else {
        size++;
    }

    return size;
}

