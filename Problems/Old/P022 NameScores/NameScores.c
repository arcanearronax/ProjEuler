#include <stdio.h>

void main() {

	int count=0;
	long long score=0;
	char ch;
	FILE *ptr = fopen("p022_names.txt", "r");

	//function to read in characters from the file
	while(((ch = fgetc(ptr)) >= 34) && (ch <= 90)) {
		if (ch == '"') {
			count++;
			printf("count: %d\n", count);
		} else if (ch == ',') {
			count--;
			printf("	count: %d\n", count);
		} else {
		score += (long) ((int)((ch - 64)*count));
		//printf("count: %d\n");
		//printf("	num: %c, %d\n", ch, (ch-64));
		}
	}
	
	fclose(ptr);
	
	printf("score: %d\n", score);
}
