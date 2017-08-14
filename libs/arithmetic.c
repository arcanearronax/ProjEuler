#include <math.h>

/*
 *  arithmetic.c
 *
 *  Contains functions and structs relevant to
 *  arithmetic calculations. Relies on math.h.
 *
 *  Functions should include some indication of
 *  which problem relies on it.
 *
 *
 */

/*
 *  ***********************************************
 *  ******************* STRUCTS *******************
 *  ***********************************************
 */

/*
 *  Meant to store a triplet of longs.
 *  Relies: P009
 */
typedef struct {
  long a;
  long b;
  long c;
} Triplet;

/*
 *  ***********************************************
 *  ****************** FUNCTIONS ******************
 *  ***********************************************
 */

/*  Relies: P001
 *  This is than breaking up the problem.
 *  Returns -1 in case of error
 */
long sumMultiples(long n1, long n2, long bound) {

  if (n1 < 0 || n2 < 0 || bound < 0 || n1 > bound || n2 > bound) {
    printf("Invalid Values - sumMultiples - num1=%ld, num2=%ld, bound=%ld\n", n1, n2, bound);
    return (long) -1;
  }

	//Let's make sure n1 <= n2
	if (n1 > n2) {
		long ntemp = n1;
		n1 = n2;
		n2 = ntemp;
	}

	long sum = 0;
  long i;
	for (i=n1; i<bound; i+=1) {
		if ((fmod(i,n1) == 0) || (fmod(i,n2) == 0)) {
			sum += i;

      if (sum < 0) {
        return (long) -1;
      }
		}
	}

	return sum;
}

/*
 *  Relies: P002
 *  Indexed first 1 at 0
 *  Returns -1 in case of error
 */
long fibonacciNum(long idx) {

  if (idx < 0) {
    printf("Invalid Value - fibonacciNum - idx=%ld\n",idx);
    return (long) -1;
  }

	long n1 = 0;
	long n2 = 1;
	long ntemp = 0;

  long i;
	for (i = 0; i<idx; i+=1) {
		ntemp = n1+n2;
		n1 = n2;
		n2 = ntemp;
    // Just in case we go overboard
    if (n2 < 0) {
      return (long) -1;
    }

	}
	return n2;
}

/*
 *  Relies: (none)
 *  Returns -1 if no factor found
 */
long largestFactor(long num) {

	long inc = 2;
	long soln = -1;
	while (inc <= (num / 2)) {

		if (fmod(num,inc) == 0) {
			soln = inc;
			break;
		}
	}
	return soln;
}

/*
 *  Relies: largestPrimeFactor
 *  Requires: num > 0
 *  Returns 1 if prime, 0 if composite, -1 otherwise
 *  Note: This function returns an int
 */
int isPrime(long num) {

  if (num < 1) {
    printf("Invalid Value - isPrime - num=%ld\n",num);
    return (long) -1;
  }

  long fact = 2;
  int div = 1;
	long sqroot=sqrt(num);

    while (fact <= sqroot) {
        if (fmod(num, fact) == 0) {
            div = 0;
            break;
        }
        fact+=1;
        if (fact < 1) {
          return (long) -1;
        }
    }
    return div;
}

/*
 *  Relies: P003, primeByIndex
 *  Requires: num > 0
 *  Return the largest prime factor
 *  Return -1 if the factor isn't found
 */
long largestPrimeFactor(long num) {

    long div = 1;
    long primeFact = -1;

    while (div <= num && div > 0) {
        if (fmod(num,div) == 0) {
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

/*
 *  Relies: isPalindrome, maxValByDig
 *  Requires: num >= 0
 *  Returns -1 if error
 *
 */
long numDig(long num) {
    if (num < 0) {
        printf("Invalid Value - numDig - num=%ld\n",num);
        return (long) -1;
    }

    if (num == 0) {
        return (long) 1;
    }

    long count = 0;
    while(num >= 1) {
        num/=10;
        count+=1;
        if (count < 0) {
            return (long) -1;
        }
    }
    return count;
}

/*
 *  Relies: largestPalindrome
 *  Requires: num > 0
 *  Return 1 if num is a palindrome, 0 otherwise, -1 if error
 *  Note: Returns an int
 */
int isPalindrome(long num) {
  if (num < 0) {
    printf("Invalid Value - isPalindrome - num=%ld\n",num);
    return (long) -1;
  }

  long len = numDig(num);
  long numArr[len];
  long temp=0;
  long i;
  for (i=0; i<len; i++) {
    numArr[i] = (num / pow(10, len-i-1));
    temp = (numArr[i] * pow(10, len-i-1));
    num -= temp;
  }

  int pal = 1;
  for (i=0; i<(int)(len/2); i++) {
    if (numArr[i] != numArr[len-i-1]) {
      pal=0;
      break;
      }
  }
  return pal;
}

/*
 *  Relies: largestPalindrome
 *  Requires: maxDig > 1
 *  Return the largest prime factor
 *  Return -1 if the factor isn't found
 */
long maxValByDig(long maxDig) {

    if (maxDig < 1) {
        printf("Invalid Value - maxValByDig - maxDig=%ld\n",maxDig);
    }

    //Get the largest possible palindrome based on digit count
    long limit=0;
    long i;
    for (i=1; numDig(i) <= maxDig; i=((i*10)+1)) {
        limit = i;
    }
    limit*=9;

    return limit;
}

/*
 *  Relies: P004
 *  xNumDig - number of digits in x, yNumDig - number of digits in y
 *  Find the largest palindrome, z, such that z=x*y
 *  Return -1 if error
 */
long largestPalindrome(long xNumDig, long yNumDig) {

  if (xNumDig < 1 || yNumDig < 1) {
    printf("Invalid Values - largestPalindrome - xNumDig=%ld, yNumDig=%ld\n",xNumDig, yNumDig);
  }

    long result=-1;
    long resX=0, resY=0;
    long x=0, y=0;
    for (x=maxValByDig(xNumDig); x>maxValByDig(xNumDig-1); x--) {
        for (y=x; y>maxValByDig(yNumDig-1); y--) {
            long prod = x*y;
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

/*
 *  Relies: P005
 *  min is lower bound, max is upper bound (inclusive)
 *  Find the LCM of a sequential range
 *  Return -1 if error
 *  Note: overflow can occur pretty early
 */
long leastCommonMult(long min, long max) {

    long count = max-min+1;
    if (max < min || count < 0) {
      printf("Invalid Values - leastCommonMult - min=%ld, max=%ld, count=%ld\n", min, max, count);
      return (long) -1;
    }
    long nums[count];

    long i;
    for (i=min; i<=max; i++) {
        nums[i-min] = i;
    }

    long lcm=1;
    for (i=0; i<count; i++) {
        long j;
        for (j=i+1; j<count; j++) {
            if (nums[j] % nums[i] == 0) {
                nums[j] /= nums[i];
            }
        }
        lcm*=nums[i];
        if (lcm < 0) {
            return (long) -1;
        }
    }
    return lcm;
}

/*
 *  Relies: P006
 *  min is the lower bound, max is the upper bound (inclusive)
 *  Find the sum of the squares of numbers in a range
 *  Return -1 if error
 */
long sumSquare(long min, long max) {
    if (max < min) {
      printf("Invalid Values - sumSquare - min=%ld, max=%ld\n", min, max);
      return (long) -1;
    }
    long sum=0;

    long i;
    for (i=min; i<=max; i++) {
        sum += i*i;
        if (sum < 0) {
          return (long) -1;
        }
    }
    return sum;
}

/*
 *  Relies: P006
 *  min is the lower bound, max is the upper bound (inclusive)
 *  Find the square of the sum of numbers in a range
 *  Return -1 if error
 */
long squareSum(long min, long max) {
    if (max < min) {
      printf("Invalid Values - squareSum - min=%ld, max=%ld\n", min, max);
      return (long) -1;
    }
    long sum=0;

    long i;
    for (i=min; i<=max; i++) {
        sum += i;
        }

    sum *= sum;

    if (sum < 0) {
      return (long) -1;
    }

    return sum;
}

/*
 *  Relies: P007
 *  Requires index > 0
 *  Return the n'th prime number, indexed at 1
 *  Return -1 if error
 */
long primeByIndex(long index) {
    if (index < 1) {
        printf("Invalid Value - primeByIndex - index=%ld\n", index);
    }
    long idx=0;
    long num=1;
    while (idx<index) {
        num+=1;
        if (isPrime(num) == 1) {
            idx++;
            if (idx < 0) {
              return (long) -1;
            }
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

long sumPrimesLessOrEqual(int limit) {
  int primes[limit];
  createPrimeArray(primes, limit);

  long sum=0;
  //Start at 1 since we have 1 in the array
  for (int i=1; i<limit; i++) {
    if (primes[i] != 0) {
      sum+= (long)primes[i];
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
