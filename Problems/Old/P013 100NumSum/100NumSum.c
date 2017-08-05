#include <stdio.h>
#include <time.h>
#define LIMIT 50

void main() {

	//timer shit
	clock_t start = clock(), stop;

	//Counter to add line from file to 2D array
	int count = 0, index = 0, i, j, temp=0;

	//create the character buffer to read in lines
	char buff[51];

	//Create a 2D array to hold the numbers, array for sum
	int nums[100][50], sum[100];

	//zero out the sum array
	for (i=0; i<100; i++) {
		sum[i] = 0;
	}

	//Open the file which contains the numbers
	FILE *ptr = fopen("input.txt", "r");

	//Read in the file ptr line by line
	while (fgets(buff, sizeof(buff), ptr)) {
		if (count % 2 == 0) {
			for (index=0; index<50; index++) {
				nums[count/2][index] = ((int) buff[index]-'0');
			}
		}
		//Counter to move down one row after converting the first number
		count++;
	}

	//nested loop to add the numbers in the arrays, i=col & j=row
	for (i=49; i>=0; i--) {
		for (j=0; j<100; j++) {
			sum[i+50] += nums[j][i];
		}
	}

	//carry the values in columns, since it's likely they're > 9
	for (i=99; i>=0; i--) {
		temp = sum[i] / 10;
		sum[i-1] += temp;
		sum[i] = sum[i] % 10;
	}


	for (i=0; i<100; i++) {
		if (sum[i] != 0) {
			printf("%d", sum[i]);
		}
	}
	printf("\n");

	stop = clock();

	printf("runtime: %d\n", (int) (stop-start));
}
