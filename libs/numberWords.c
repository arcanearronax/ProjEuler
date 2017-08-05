//Lotta of variables
int ONE = 3;
int TWO = 3;
int THREE = 5;
int FOUR = 4;
int FIVE = 4;
int SIX = 3;
int SEVEN = 5;
int EIGHT = 5;
int NINE = 4;
int TEN = 3;
int ELEVEN = 6;
int TWELVE = 6;
int ZERO = 0;

int TEEN = 4;
int THIR = 4;
int FIF = 3;
int EIGH = 4;

int TY = 2;
int TWENTY = 6;
int FORTY = 5;

int AND = 3;
int HUNDRED = 7;

int numLetCount1(int num, int res) {
  //printf("NUMCOUNT1 %d\n", num);
  if (num == 1) {
    res += ONE;
  } else if (num == 2) {
    res += TWO;
  } else if (num == 3) {
    res += THREE;
  } else if (num == 4) {
    res += FOUR;
  } else if (num == 5) {
    res += FIVE;
  } else if (num == 6) {
    res += SIX;
  } else if (num == 7) {
    res += SEVEN;
  } else if (num == 8) {
    res += EIGHT;
  } else if (num == 9) {
    res += NINE;
  } else {
    res += ZERO;
  }
  //printf("STUFF-%d\n",res);
  return res;
}

int numLetCount2(int num, int res) {
  //printf("--num=%d\n",num%10);
  if (num == 10) {
    //printf("test1\n");
    res += TEN;
  } else if (num == 11) {
    res += ELEVEN;
  } else if (num == 12) {
    res += TWELVE;
  } else if (num < 20) {
    res += TEEN;
    if (num == 13) {
      res += THIR;
    } else if (num == 15) {
      res += FIF;
    } else if (num == 18) {
      res += EIGH;
    } else {
      res=numLetCount1(num%10, res);
    }
  } else if (num/10 == 2) {
    //printf("test2\n");
    res += TWENTY;
    if (num > 20) {
      res=numLetCount1(num%10, res);
    }
  } else if (num/10 == 3) {
    //printf("test3\n");
    res += THIR;
    res += TY;
    if (num > 30) {
      res=numLetCount1(num%10, res);
    }
  } else if (num/10 == 4) {
    //printf("test4\n");
    res += FORTY;
    if (num > 40) {
      res=numLetCount1(num%10, res);
    }
  } else if (num/10 == 5) {
    //printf("test6\n");
    res += FIF;
    res += TY;
    if (num > 50) {
      res=numLetCount1(num%10, res);
    }
  } else if (num/10 == 8) {
      //printf("test8\n");
      res += EIGH;
      res += TY;
      if (num > 80) {
        res=numLetCount1(num%10,res);
      }
  } else {
    res += TY;
    //
    int temp=num/10;
    //printf("testElse--%d\n",temp);
    res=numLetCount1(temp,res);
    if (num%10 != 0) {
      res=numLetCount1(num%10, res);
    }
  }
  //printf(">>num=%d\n",num);
  //printf("MOD=%d\n", (num % 10));
  return res;
}

int numLetCount3(int num, int res) {
  res += HUNDRED;

  int digit = (num / 100);
  res=numLetCount1(digit, res);
  //printf("SHIT %d\n",res);
  return res;
}

int numLetCount4(int num, int res) {
  //One Thousand
  res += 11;
  return res;
}

int countDigits(int num) {
  int digits;
  if (num > 999) {
    digits=4;
  } else if (num > 99) {
    digits=3;
  } else if (num > 9) {
    digits=2;
  } else {
    digits=1;
  }
  return digits;
}

int numLetCount(int num) {
  int digits = countDigits(num);
  int res=0;

  //printf("num=%d\t\tdigits=%d\n", num, digits);

  if (digits == 4) {
    res=numLetCount4(num, res);
  } else {
    if (digits > 2) {
      res=numLetCount3(num, res);
      num = num%100;
      //printf("TESTNUM-%d\n",res);
      digits = countDigits(num);
      //see if we need to add and
      if (num != 0) {
        res+=AND;
        //printf("AND...\n");
      }
    }
    if (digits > 1) {
      res=numLetCount2(num, res);
      //printf("DAMN1\n");
    }
    if (digits > 0) {
      res=numLetCount1(num,res);
      printf("num=%d\t\tdigits=%d\t\tres=%d\n", num, digits,res);
    }
  }
  return res;
}

int largestNumLetCount(int min, int max) {
  int res=0;

  for (int i=min; i<=max; i++) {
    //res=0;
    res += numLetCount(i);
    //printf("--NUM=%d\t\tres=%d\n", i, res);
  }
  return res;
}
