#include <stdio.h>
#include <time.h>
#define LIMIT 1000

void main() {

	clock_t start = clock();

	int i, sum;

	for (i=1; i * 5 < LIMIT; i++) {
		sum += 5 * i;
	}
	
	for (i=1; i * 3 < LIMIT; i++) {
		if (3 * i % 5 != 0) {
			sum += 3 * i;
		}
	}

	clock_t stop = clock();

	int runt = ((int)(stop - start));

	printf("Runtime=%d\n", runt);
	printf("The sum is %d \n", sum);
}
