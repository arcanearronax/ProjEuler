#include <stdio.h>
#include "../arithmetic.c"
#define LIMIT 4000000

void main() {

	int val = 0;
	int sum = 0;
	int index = 1;
	while (val < LIMIT) {
		
		if (val % 2 == 0) {
			sum += val;
		}

		val = fibonacciNum(index);
		index++;

	}

	printf("Result: %d\n", sum);
}
