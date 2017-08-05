#include <stdio.h>
#include <time.h>

#define limit 1000000

/*
*Create an array where the number of terms in the collatz
*sequence for i+1 corresponds to seqs[i].
*
*When examining i, find the first value already in the array,
*then add the current sequence number to the one in the array.
*/

void main() {

	//Delcare the array of sequence sizes, counters, and index counts
	int seqs[limit], i=0, j=0, num=2, index=0, indexMax=0, countTemp=1, countMax=0;

	//Timer jazz
	clock_t start, stop;
	int time = 0;

	start = clock();

	//Zero out the sequence array
	for (i=0; i<limit; i++) {
		seqs[i] = 0;
	}

	for (num=2; num<=limit; num++) {
		index = num;
		countTemp = 0;
		while (index != 1) {
			if (index % 2 == 0) {
				index /= 2;
			} else {
				index = 3 * index + 1;
			}
			countTemp++;
	
			//printf("num=%d\n", num);
			//printf("index=%d\n", index);
			//printf("countTemp=%d\n", countTemp);
	
			if (num > index) {
				seqs[num] = seqs[index] + countTemp;
				if (countTemp > countMax) {
					countMax = countTemp;
					indexMax = num;
				}
			}
		}
	}

	stop = clock();
	
	time = (stop - start) / 1000;

	printf("Solution: %d at %d\n", countMax, indexMax);
	printf("Runtime: %dms\n", time);
}
