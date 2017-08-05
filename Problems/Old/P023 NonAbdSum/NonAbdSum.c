#include <stdio.h>
#include <time.h>

#define LIMIT 28123

void main() {

	int i, j, abds[LIMIT], sums[LIMIT], clocks, forClock;
	long long sum = 0;
	clock_t forStart, forStop, start, stop;

	start = clock();

	//Zero out the arrays
	for (i=0; i<LIMIT; i++) {
		abds[i] = 0;
		sums[i] = 0;
	}

	forStart = clock();

	//Fill abds with abundant nums, first index starts at 1
	for (i=2; i<=LIMIT; i++) {
		if (isAbd(i)) {
			abds[i-1] = i;
		}
	}

	forStop = clock();
	
	//add abundant nums and place them in the sums array
	for (i=0; i<LIMIT; i++) {
		for (j=0; j<LIMIT; j++) {
			if ((abds[i] != 0) && (abds[j] != 0)) {
				if (abds[i] + abds[j] < LIMIT) {
					sums[abds[i] + abds[j]] = abds[i] + abds[j];
				}
			}
		}
	}

	//invert the array
	for (i=1; i<LIMIT; i++) {
		if (sums[i] == 0) {
			sums[i] = i;
		} else {
			sums[i] = 0;
		}
	}

	//add up the nums in the sums array
	for (i=1; i<LIMIT; i++) {
		sum += (long long) sums[i];
	}

	stop = clock();

	clocks = (stop - start) / 1000;
	forClock = (forStop - forStart) / 1000;

	printf("Sum: %lld\n", sum);
	printf("clocks: %d\n", clocks);
	printf("forClock: %d\n", forClock);
	
}

int isAbd(int test) {
	int i, sum=1, ret=0;

	for (i=2; i<test; i++) {
		if (test % i == 0) {
			sum += i;
		}
	}

	if (sum > test) {
		ret = 1;
	}

	return ret;
}
