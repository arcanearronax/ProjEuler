double thingShit(int dimX, int dimY, int *point[dimX][dimY], int nums) {
  return (double) *point[0][1];
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
