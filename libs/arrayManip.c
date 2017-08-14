void charArrToIntArr(char series[], int *nums) {

  for (long i=0; i<1000; i++) {
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

long prodAdjNums(long *nums) {

  long temp=1;
  long prod=1;

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

double largestHorizProd(int dimX, int dimY, int *point[dimX][dimY], int nums) {
  double temp=1;
  double prod=0;

  for (int i=0; i<=dimX-nums; i++) {
    for (int j=0; j<dimY; j++) {
      for (int k=0; k<nums; k++) {
        temp *= (double) *point[j][i+k];
      }
      if (temp > prod) {
        prod=temp;
      }
      temp=1;
    }
  }
  return prod;
}

double largestVertProd(int dimX, int dimY, int *point[dimX][dimY], int nums) {
  double temp=1;
  double prod=0;

  for (int i=0; i<dimY; i++) {
    for (int j=0; j<=dimX-nums; j++) {
      for (int k=0; k<nums; k++) {
        temp *= (double) *point[j][i+k];
      }
      if (temp > prod) {
        prod = temp;
      }
      temp=1;
    }
  }
  return prod;
}

double largestDiagProd1(int dimX, int dimY, int *point[dimX][dimY], int nums) {
  double temp=1;
  double prod=0;

  for (int i=0; i<=dimX-nums; i++) {
    for (int j=0; j<=dimY-nums; j++) {
      for (int k=0; k<nums; k++) {
        temp *= (double) *point[j+k][i+k];
      }
      if (temp > prod) {
        prod=temp;
      }
      temp=1;
    }
  }
  return prod;
}

double largestDiagProd2(int dimX, int dimY, int *point[dimX][dimY], int nums) {
  double temp=1;
  double prod=0;

  for (int i=(nums-1); i<dimX; i++) {
    for (int j=0; j<=dimY-nums; j++) {
      for (int k=0; k<nums; k++) {
        temp *= *point[j+k][i-k];
      }
      if (temp > prod) {
        prod=temp;
      }
      temp=1;
    }
  }
  return prod;
}

double largestAdjProd(int dimX, int dimY, int *point[dimX][dimY], int nums) {
  double lgProd=0;
  double temp=0;

  temp = largestHorizProd(dimX, dimY, point, nums);

  if (temp > lgProd) {
    lgProd = temp;
  }

  temp = largestVertProd(dimX, dimY, point, nums);

  if (temp > lgProd) {
    lgProd = temp;
  }

  temp = largestDiagProd1(dimX, dimY, point, nums);

  if (temp > lgProd) {
    lgProd = temp;
  }

  temp = largestDiagProd2(dimX, dimY, point, nums);

  if (temp > lgProd) {
    lgProd = temp;
  }

  return lgProd;

}

void prodIntArr(int *arr, int size, int num) {
  for (int i=0; i<size; i++) {
    arr[i] = arr[i] * num;
  }
  for (int i=size-1; i>0; i--) {
    if (arr[i] != (arr[i]%10)) {
      arr[i-1]+=((int)(arr[i]/10));
      arr[i]=(arr[i]%10);
    }
  }
}

//P013 and potentially others depend on this
double arrToDouble(int rows, int *sum) {
  int digits=10;
  int count=0;
  int id=rows-1;
  while(sum[id] == 0) {
    count++;
    id--;
  }


  double ret=0;
  double temp=1;
  for (int i=digits; i>=0; i--) {
    //printf("%d",sum[digits-i]);
    temp = (pow(10,i)*sum[digits-i-1]);
    ret += temp;
    temp=1;
  }
  return ret;
}

double retDoubleFromArr(int *arr, int size) {
  double ret=0;

  //printf("Size=%d\n",size);

  for (int i=0; i<size; i++) {
    int temp = (pow(10,i)*arr[size-i-1]);
    //printf("%d\n",temp);
    ret += temp;
  }
  return ret;
}

void printArr(int *arr, int size) {
  int noPrint=1;
  for (int i=0; i<size; i++) {
    if (arr[i] != 0) {
      noPrint=0;
    }
    if (!noPrint) {
      printf("%d", arr[i]);
    }
  }
  printf("\n");
}

double expArrInt(int *arr, int size, int num, int exp) {
  for (int i=1; i<exp; i++) {
    prodIntArr(arr, size, num);
  }
  return retDoubleFromArr(arr, size);
}

void doubleToArr(double num, int *arr, int digits) {

  for (int i=0; i<digits; i++) {
    arr[i] = 0;
  }

  double temp = num;
  int count=0;
  while (temp >= 1) {
    arr[digits-1-count]=(int) (fmod(temp, 10));
    //printf("");
    temp /= 10;
    count++;
  }
}

void arrProd(int *arr1, int *arr2) {
  // Ehh...
}

void largeNumFactorial(double num, int *arr, int digits) {
  doubleToArr(num, arr, digits);

  for (int i=2; i<(int) num; i++) {
    for (int j=digits-1; j>=0; j--) {
      if (arr[j] != 0) {
        int temp=arr[j]*i;
        arr[j] = temp;
      }
    }

    for (int j=digits-1; j>=0; j--) {
      if (arr[j] > 9) {
        arr[j-1] += (arr[j]/10);
        arr[j] = (arr[j]%10);
      }
    }
  }
}

double sumArr(int *arr, int digits) {
  double res=0;

  for (int i=0; i<digits; i++) {
    res += (double) arr[i];
  }

  return res;
}
