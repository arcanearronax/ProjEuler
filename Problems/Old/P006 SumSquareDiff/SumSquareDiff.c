#include <stdio.h>

void main() {

	int bound, i, sum=0, square=0, diff;

	printf("Please input the bound: ");
	scanf("%d", &bound);

	for (i=1; i <= bound; i++) {
		sum += i * i;
	}

	for (i=1; i <= bound; i++) {
		square += i;
	}

	square *= square;

	diff = square - sum;

	printf("The difference is %d \n", diff);
}
