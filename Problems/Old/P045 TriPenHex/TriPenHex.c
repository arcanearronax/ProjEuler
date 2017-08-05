#include <stdio.h>
#include <math.h>
#define LIMIT 30000

void main() {

    unsigned int hex[LIMIT]={0}, hexPen[LIMIT]={0}, pen, tri, ans=0;
    int i, j;

    //fill the Hex array, starting with #144
    for (i=144; i<LIMIT+144; i++) {
        hex[i-144] = (i*(2*i-1));
        //printf("%d \n", hex[i-144]);
    }

    //check pentagonal numbers against hex array, create new array
    for (i=0; i<LIMIT; i++) {
        if (isPent(hex[i]) == 1) {
            hexPen[i] = hex[i];
            //printf("%lld \n", i);
        }
    }

    //check triagle numbers against new array
    for (i=0; i<LIMIT; i++) {
        if (hexPen[i] != 0) {
            if (isTriang(hexPen[i]) == 1) {
                ans=hexPen[i];
                break;
            }
        }
    }

    printf("The answer is %d \n", ans);
}

int isPent(int val) {
    long i=0, ret=0;

    for (i=2; (i*(3*i-1)/2) <= val; i++) {
        if (val == (i*(3*i-1)/2)) {
            ret = 1;
            break;
        }
    }
    return ret;
}

int isTriang(int val) {
    long i=0, ret=0;

    for (i=2; (i*(i+1)/2) <= val; i++) {
        if (val == (i*(i+1)/2)) {
            ret = 1;
            break;
        }
    }

    return ret;
}
