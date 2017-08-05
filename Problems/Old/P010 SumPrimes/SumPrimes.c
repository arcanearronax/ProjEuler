#include <stdio.h>

void main() {

	int bound, i, j;
    long sum=0;

	printf("Please input the bound: ");
	scanf("%d", &bound);

	for (i=2; i < bound; i++) {
        if (isPrime(i) == 1) {
            sum += i;
        }
        printf("The current number is %d \n", i);
	}

    printf("The value of sum is %ld \n", sum);
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
