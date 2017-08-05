#include <string.h>

void charArrToIntArr(char series[], int *nums) {

  for (int i=0; i<1000; i++) {
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
}

double prodAdjNums(int *nums) {

  double temp=1;
  double prod=1;

  for (int i=0; i<987; i++) {
      //printf("%d", nums[i]);
      for (int j=i; j<i+13; j++) {
          temp *= (double) nums[j];
      }
      if (temp > prod) {
          prod=temp;
          //printf("%d \n", i);
      }
      temp=1;
  }

  return prod;

}
