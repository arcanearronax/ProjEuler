#include <stdio.h>

void main() {

    int i, j, pow, base, sum;

    
}

//calculate the size of a number
int numSize(int val, int size) {

    int i;

    //recursive, submitting 1/10th of the value to count digits
    if (val/10 >= 1) {
        size++;
        size = numSize(val/10, size);
    } else {
        size++;
    }

    return size;
}

int calcDigit(int i, int size, int val) {
    int temp, dum;
    //calculate a single digit
    if (i == 0) {
        temp = val / pow(10, size - i - 1);
    } else {
        temp = val /  pow(10, size - i - 1);
        dum = (val /  pow(10, size -i));
        temp -= 10 * dum;
    }
    return temp;
}

int sum
