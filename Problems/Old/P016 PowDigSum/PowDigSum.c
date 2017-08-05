#include <stdio.h>

#define POW 1000

void main() {

	int num[POW], i, j, pos, sum=0, index;

	//Setup the array, include 1 for clear reasons
	for (i=0; i<POW; i++) {
		num[i] = 0;
	}
	num[POW-1] = 1;

	//k loop to run process repeatedly
	for (pos=POW; pos>0; pos--) {
		//printf("pos: %d\n", pos);
		//i loop to multiply the array values by 2
		for (i=POW-1; i>=0; i--) {
			//printf("num[%d]: %d\n", i, num[i]);
			num[i] *= 2;
			}
		for (i=POW-1; i>=0; i--) {
			num[i-1] += (num[i] / 10);
			num[i] = num[i] % 10;
		}
	}

	for (i=0; i<POW; i++) {
		if (num[i] != 0) {
			index = i;
			break;
		}
	}

	for (i=index; i<POW; i++) {
		printf("%d", num[i]);
	}
	printf("\n");

	for (i=0; i<POW; i++) {
		sum +=num[i];
	}

	printf("Sum: %d\n", sum);
}
