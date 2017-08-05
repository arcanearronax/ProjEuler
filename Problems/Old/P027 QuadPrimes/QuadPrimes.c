#include <stdio.h>

#define A 10
#define B 10
#define LIM 100

//The formula being used is n^2+an+b
void main() {

	//Declare counter variable
	int i=0, j=0;

	//create an array of numbers and fill it
	int vals[LIM];
	vals[0] = 1;
	for (i=0; i<LIM; i++) {
		vals[i] = i+1;
	}

	//clear the vals array of composite numbers
	for (i=1; i<LIM/2; i++) {
		for (j=i+1; j<LIM; j++) {
			if (vals[i] != 0) {
				if (vals[j] % vals[i] == 0) {
					vals[j] = 0;
				}
			}
		}
	}

}

int isPrime() {

}

//return the number of primes in the sequence
int countPrime() {

}
