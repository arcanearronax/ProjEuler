#include <stdio.h>

void main() {

	int bound, i, count=0, prime;

	printf("Please input the bound: ");
	scanf("%d", &bound);
    
    //count will increase each time i is prime
	for (i=2; count < bound; i++) {
		count += isPrime(i);
		if (count == bound) {
			prime = i;
		}
	}

	printf("The prime number is %d \n", prime);
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
