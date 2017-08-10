#include <math.h>

typedef struct {
  double a;
  double b;
  double c;
} Triplet;

//Pass the smaller of the two numbers first
int sumMultiples(int n1, int n2, int bound) {

	//Let's make sure n1 <= n2
	if (n1 > n2) {
		int ntemp = n1;
		n1 = n2;
		n2 = ntemp;
	}

	int sum = 0;
	for (int i=n1; i<bound; i++) {
		if ((i % n1 == 0) || (i % n2 == 0)) {
			sum += i;
		}
	}

	return sum;
}

//Indexed 0 at the first 1
int fibonacciNum(int idx) {

	int n1 = 0;
	int n2 = 1;
	int ntemp = 0;

	for (int i = 0; i<idx; i++) {
		ntemp = n1+n2;
		n1 = n2;
		n2 = ntemp;
	}
	return n2;
}

//Returns -1 if no factor found
double largestFactor(double num) {

	double inc = 2;
	double soln = -1;
	while (inc <= (num / 2)) {

		if (fmod(num,inc) == 0) {
			soln = inc;
			break;
		}
	}
	return soln;
}

int isPrime(double num) {

    double fact = 2;
    double div = 1;
	double sqroot=sqrt(num);

    while (fact <= sqroot) {
        //printf("\tnum=%.0lf\ttemp=%.0lf\n",num,fact);
        if (fmod(num, fact) == 0) {
            div = 0;
            //printf("\t\tnum=%.0lf \tfact=%.0lf\n",num,div);
            break;
        }
        fact+=1;
    }
    return div;
}

//Return the largest prime factor
double largestPrimeFactor(double num) {

    double div = 1;
    double primeFact = -1;

    while (div <= num && div > 0) {
        if (fmod(num,div) == 0) {
            //printf("num=%.0lf\tdiv=%.0lf\n",num,div);
            if (isPrime(num / div) == 1) {
                primeFact = num / div;
                break;
            }
            num = num / div;
        }
        div+=1;
    }

    return primeFact;
}

int numDig(double num) {
    int count = 0;
    while(num >= 1) {
        num/=10;
        count ++;
        //printf("num=%.0lf\tcount=%d\n",num,count);
    }
    return count;
}

int isPalindrome(int num) {

    int len = numDig((double) num);
    int numArr[len];
    int temp=0;
    for (int i=0; i<len; i++) {
        numArr[i] = (int) ((double) num / pow(10, len-i-1));

        temp = (int) (numArr[i] * pow(10, len-i-1));
        num -= (double) temp;
        //printf("num1: %d\n", temp);
    }

    int pal = 1;
    for (int i=0; i<(int)(len/2); i++) {
        //printf("num1=%d\tnum2=%d\n",numArr[i],numArr[len-i-1]);
        if (numArr[i] != numArr[len-i-1]) {
            pal=0;
            break;
        }
    }
    return pal;
}

//Need to rename this...
int upperBound(int maxDig) {

    //Get the largest possible palindrome based on digit count
    int limit=0;
    for (int i=1; numDig(i) <= maxDig; i=((i*10)+1)) {
        //do nothing
        limit = i;
        //printf("temp=%d\n",temp);
    }
    limit*=9;

    return limit;
}

//Returns the largest palindrome that's the product of 2 ints.
int largestPalindrome(int xNumDig, int yNumDig) {

    int result=-1;
    int resX=0;
    int resY=0;
    for (int x=upperBound(xNumDig); x>upperBound(xNumDig-1); x--) {
        for (int y=x; y>upperBound(yNumDig-1); y--) {
            int prod = x*y;
            //printf("x=%d\ty=%d\tresult=%d\n",x,y,result);
            if (isPalindrome(prod) == 1) {
                if (prod > result) {
                    result=prod;
                    resX=x;
                    resY=y;
                }
            }
            if (resY > x) {
                resX=-1;
                break;
            }
        }
        if (resX == -1) {
            break;
        }
    }

    return result;

}

//Return the LCM of the numbers in a range
int leastCommonMult(int min, int max) {

    int count = max-min+1;
    int nums[count];

    for (int i=min; i<=max; i++) {
        nums[i-min] = i;
        //printf("nums=%d\n",nums[i-min]);
    }

    int lcm=1;
    for (int i=0; i<count; i++) {
        for (int j=i+1; j<count; j++) {
            //printf("nums[i]=%d\tnums[j]=%d\n",nums[i],nums[j]);
            if (nums[j] % nums[i] == 0) {
                nums[j] /= nums[i];
                //lcm *= nums[i];
            }
        }
        lcm*=nums[i];
        //printf("lcm=%d\n",lcm);
    }
    return lcm;
}

double sumSquare(double min, double max) {
    double sum=0;

    for (int i=(int) min; i <= (int) max; i++) {
        sum += (double) i*i;
    }

    return sum;
}

double squareSum(double min, double max) {
    double sum=0;

    for (int i=(int) min; i <= (int) max; i++) {
        sum += (double) i;
    }

    sum *= sum;

    return sum;
}

double primeByIndex(int index) {
    int idx=0;
    double num=1;
    while (idx<index) {
        num+=1;
        //printf("num=%.0lf\n",num);
        if (isPrime(num) == 1) {
            idx++;
        }
    }
    return num;
}

double binomCoeff(double n, double k) {

    double numer=1;

    for (double i=1; i<=n; i+=1) {
        numer *= i;
    }

    double denom=1;

    for (double i=1; i<=(n-k); i+=1) {
        denom *= i;
    }
    for (double i=1; i<=k; i+=1) {
        denom *= i;
    }

    return (numer/denom);
}

/*
*   solving a^2+b^2=c^2
*   a=m^2-n^2, b=2mn, c=m^2+n^2
*   a+b+c=1000 => 2m(m+n)=1000
*   solve the latter and then substitute
*/
void pythagTripSum(Triplet *trip, double sum) {
  int m,n;

  for (int i=0; i<(int)sum/2; i++) {
    if (fmod(((double) (i*i + 2*sum)), sqrt(i*i+2*sum)) == 0) {
      n=i;
      break;
    }
  }

  m = (-n + sqrt(n*n+2*sum)) / 2;

  trip->a = (double) m*m - n*n;
  trip->b = (double) 2*m*n;
  trip->c = (double) m*m + n*n;


}

Triplet initTriplet() {
  Triplet trip;
  trip.a = (double) 0;
  trip.b = (double) 0;
  trip.c = (double) 0;
}

double prodPythTripSum(double sum) {
  Triplet trip;
  trip = initTriplet();
  pythagTripSum((Triplet *)&trip, sum);
  return (trip.a * trip.b * trip.c);
}

//Pass an empty array and limit
void createPrimeArray(int *primes, int limit) {
  for (int i=0; i<limit; i++) {
    primes[i] = i+1;
  }

  for (int i=1; i<limit; i++) {
    if (primes[i] != 0) {
      //printf("Testing: %d\n",primes[i]);
      int count = 2*(i+1);
      //printf("--count: %d\n", count);

      while (count <= limit) {
        //printf("Count: %d\n", count);
        if (count % primes[i] == 0) {
            primes[count-1] = 0;
        }
        count+=(i+1);
      }
    }
  }
}

long long sumPrimesLessOrEqual(int limit) {
  int primes[limit];
  createPrimeArray(primes, limit);

  long sum=0;
  //Start at 1 since we have 1 in the array
  for (int i=1; i<limit; i++) {
    if (primes[i] != 0) {
      sum+= (long long)primes[i];
    }
  }

  return sum;
}

double numDivisors(double triang) {
  double count=0;

  for (int i=1; i<=sqrt(triang); i++) {
    if (fmod(triang, (double) i) == 0) {
      count+=1;
    }
  }
  count*=2;
  //printf("Triang: %.0lf\t-\tcount: %.0lf\n", triang, count);

  return (double) count;
}

double infinumTriNumByDiv(double divs) {
  double triang=1;
  double term=1;
  while (numDivisors(triang) < divs) {
    term +=1;
    triang += term;
  }
  return triang;
}

double nextCollatz(double num) {
  if (fmod(num,2) == 0) {
    return (double) (num/2);
  } else {
    return (double) (3*num+1);
  }
}

double longestCollatzChain(int bound) {
  int colArr[bound];
  colArr[0]=1;
  for (int i=1; i<bound; i++) {
    colArr[i]=0;
  }

  //Fill the array with collatz chain lengths
  for (int i=2; i<=bound; i++) {
    //printf("Test=%d\n",i);
    int count=1;
    double currNum=nextCollatz(i);
    do {
      if (currNum <= bound) {
        if (colArr[((int)currNum)-1] != 0) {
          //printf("\tCurNum=%d\n", (int)currNum);
          colArr[i-1] = count+colArr[((int)currNum)-1];
          break;
        }
      }
      count++;
      currNum = nextCollatz(currNum);
    } while (colArr[bound-1] == 0);
  }

  //pick the largest
  double res=0;
  double temp=0;
  for (int i=0; i<bound; i++) {
    if (colArr[i] > temp) {
      res=i+1;
      temp=colArr[i];
    }
  }

  return res;
}

/*
 *  d(n) = sum of proper divisors of n
 *  If d(a) = b and d(b) = a and a != b
 *  then a and b are amicable.
 *
 */

double sumDiv(int num) {
  int divs[num];

  for (int i=0; i<num; i++) {
    divs[i]=0;
  }

  for (int i=1; i<=num/2; i++) {
    if (num % i == 0) {
      divs[i-1]=i;
      divs[(num/i)-1]=num/i;
    }
  }

  double res=0;
  for (int i=0; i<num-1; i++) {
    res += (double) divs[i];
  }

  return res;
}

double sumAmicableNumbers(int bound) {

  double amInd[bound];

  for (int i=0; i<bound; i++) {
    amInd[i]=0;
  }

  for (int i; i<bound; i++) {
    amInd[i] = sumDiv(i+1);
  }

  double res=0;
  for (int i=0; i<bound; i++) {
    int a = i+1;
    int b = amInd[i];

    if (b > 0) {
      if (b <= bound) {
        if (a == amInd[b-1] && a!=b) {
          res += (double) a;
          res += (double) b;
          amInd[i]=0;
          amInd[b-1]=0;
        }
      }
    }
  }
  return res;
}
