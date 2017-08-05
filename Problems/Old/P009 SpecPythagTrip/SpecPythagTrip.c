#include <stdio.h>
#include <math.h>

/*
*   solving a^2+b^2=c^2
*   a=m^2-n^2, b=2mn, c=m^2+n^2
*   a+b+c=100 => 2m(m+n)=1000
*   solve the latter and then substitute
*/

void main() {

    int a, b, c, m, n, i;

    //find the quotient in the equation
    for (i=0; i<500; i++) {
        if((int) (pow(i,2)+2000) % (int) sqrt(pow(i,2)+2000) == 0) {
            n=i;
            break;
        }
    }

    m = (-n + sqrt(pow(n,2)+2000)) / 2;

    a = pow(m,2) - pow(n,2);
    b = 2 * m * n;
    c = pow(m,2) + pow(n,2);

    printf("a=%d, b=%d, c=%d \n", a, b, c);

    printf("The solution is %d \n", a*b*c);
}
