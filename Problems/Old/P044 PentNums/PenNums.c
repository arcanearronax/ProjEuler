#include <stdio.h>
#define LIMIT 1000

void main() {

    int i, j, k, l, pents[LIMIT]={0}, ans1, ans2, dum=LIMIT, ans[LIMIT];

    for (i=1; i<LIMIT; i++) {
        pents[i] = (i*((3*i)-1))/2;
    }
    
    for (i=1; i<LIMIT-1; i++) {
        for (j=1; j<i; j++) {
            for (k=i+1; i<LIMIT; k++) {
                if (pents[k] > pents[i] + pents[j]) {
                    break;
                } else if (pents[k] == pents[i] + pents[j]) {
                    ans[i] = pents[k]

    printf("The answer is %d \n", dum);
}
