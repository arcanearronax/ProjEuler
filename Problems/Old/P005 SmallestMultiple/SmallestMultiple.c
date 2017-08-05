#include <stdio.h>

void main() {
    //declare bound, counters, array, and product
	int bound = 20, i, j, prod=1;
    int numArray[bound];

    //fill the array with 1,..., 20
    for (i=0; i<bound; i++) {
        numArray[i] = i + 1;
    }

    /*
    *nested loop, the j counter will find factors
    *i counter will run for larger numbers
    *if array[i]
    */
    for (i=0; i<bound; i++) {
        for (j=0; j<i; j++) {
            if (numArray[j] != 1) {
                if (numArray[i] % numArray[j] == 0) {
                    numArray[i] /= numArray[j];
                }
            }
        }
    }

    for (i=0; i<bound; i++) {
        prod *= numArray[i];
    }

    printf("The product is %d \n", prod);

}


