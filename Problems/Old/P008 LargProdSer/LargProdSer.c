#include <stdio.h>

void main() {

    int i, j, test, nums[1000];
    long temp=1, prod=1;
    char series[1000] ="7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
 
    for (i=0; i<1000; i++) {
        if (series[i] == '0') {
            nums[i]=0;
        } else if (series[i] == '1') {
            nums[i]=1;
        } else if (series[i] == '2') {
            nums[i]=2;
        } else if (series[i] == '3') {
            nums[i]=3;
        } else if (series[i] == '4') {
            nums[i]=4;
        } else if (series[i] == '5') {
            nums[i]=5;
        } else if (series[i] == '6') {
            nums[i]=6;
        } else if (series[i] == '7') {
            nums[i]=7;
        } else if (series[i] == '8') {
            nums[i]=8;
        } else if (series[i] == '9') {
            nums[i]=9;
        }
    }
   
    for (i=0; i<987; i++) {
        printf("%d", nums[i]);
        for (j=i; j<i+13; j++) {
            temp *= nums[j];
        }
        if (temp > prod) {
            prod=temp;
            //printf("%d \n", i);
        }
        temp=1;
    }

    printf("The answer is %ld \n", prod);
}
