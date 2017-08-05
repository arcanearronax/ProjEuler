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
	long long i=0, j=0;
	long long seqs[limit], num=2, index=0, indexMax=0, countTemp=0, countMax=0;


	//Timer jazz
	clock_t start, stop, loopStart, loopStop;
	int time = 0, loopTime=0;

	start = clock();

	//Zero out the sequence array
	//for (i=0; i<limit; i++) {
	//	seqs[i] = 0;
	//}

	for (num=2; num<=limit; num++) {
		index = num;
		countTemp = 0;
		while (index != 1) {
			countTemp++;
			//printf("num=%llu\n", num);
			//printf("	index=%llu\n", index);
			//printf("	countTemp=%llu\n", countTemp);
			//printf("	countMax=%llu\n", countMax);
			if (index % 2 == 0) {
				//loopStart = clock();
	            if (num > index) {
	                seqs[num] = seqs[index] + countTemp;
    	            if (countTemp > countMax) {
        	            countMax = countTemp;
            	        indexMax = num;
						//break;
                	}
            	}
				//loopStop = clock();
				//loopTime += (loopStop - loopStart);

				index /= 2;
			} else {
				index = 3 * index + 1;
			}
			//printf("num=%d\n", num);
			//printf("index=%d\n", index);
			//printf("	indexMax=%d\n", indexMax);
		}
	}

	stop = clock();

	time = (stop - start) / 1000;
	
	printf("Solution: %lld with %lld\n", indexMax, countMax);
	printf("Runtime: %dms\n", time);
	//printf("LoopTime: %d\n", (loopTime/1000));
}
