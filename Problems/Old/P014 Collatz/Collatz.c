#include <stdio.h>
#include <time.h>

#define LIMIT 1000000

long collatz(unsigned long long val);

void main() {

    long max, seq=0, coll;
    long i;

	clock_t start, stop;
	int time = 0;

	start = clock();

    for (i=2; i<=LIMIT; i++) {
        coll = collatz(i);
        if (coll > seq) {
            seq = coll;
            max = i;
        }
    }

	stop = clock();

	time = (stop - start) / 1000;

    printf("The answer is %ld \n", max);
	printf("Runtime:%d\n", time);
}

long collatz(unsigned long long val) {

    unsigned long long seq = 1;

    while (val != 1) {
        if (val % 2 == 0) {
            val /= 2;
            seq++;
        } else {
            val = 3 * val + 1;
            seq++;
        }
    }

    return seq;
}
