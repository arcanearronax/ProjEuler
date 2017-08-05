#include <stdio.h>
#include <math.h>

int numSize(int val, int size);

void main() {

    //declare the necessary variables
    int product=0, i, j;

    //nested loop to produce products
    for (i=999; i > 99; i--) {
        for (j=999; j >= i; j--) {
            if (i*j > product) {
                if (isPalindrome(i*j) == 1) {
                    product = i*j;
                }
            }
        }
    }
    printf("The palindrome is %d \n", product);
}

//function to determine if product is palindrome, 1=yes, 0=no
int isPalindrome(int product) {

    //declare pal, 0 if false, 1 if true
    int pal=0, i;
    
    //determine the size of the number
    int size = 1;
    size = numSize(product, size);

    //declare the array
    int numArray[size];

    //convert input number to an array of ints 
    for (i=0; i<size; i++) {
        numArray[i] = calcDigit(i, size, product);
    }

    //loop to determine if the number is a palindrome
    for (i=0; i<size; i++) {
        if (numArray[i] == numArray[size-i-1]) {
            pal=1;
        } else {
            pal=0;
            break;
        }
    }
    return pal;
}

//determine the number of digits in an int
int numSize(int val, int size) {

    int i;

    //recursive, submitting 1/10th of the value to count digits
    if (val/10 >= 1) {
        size++;
        size = numSize(val/10, size);
    }
    return size;
}

//calculate the digits in the number, to be used in a for loop
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
