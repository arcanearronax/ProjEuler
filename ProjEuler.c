 #include "ProjEuler.h"

/*
 *	ProjEuler.c
 *
 *	This just needs to be compiled. It imports
 *	everything automatically.
 *
 *	Solutions are long, unless otherwise necessary.
 *	Naming convention is P###() and vars should be
 *	set for parameter values.
 *
 */

//Checked
long P001() {
	long num1 = 3;
	long num2 = 5;
	long bound = 1000;
	return sumMultiples(num1,num2,bound);
}

//Checked
long P002() {
	long limit = 4000000;

	long val=0;
	long sum=0;
	long index=1;

	while (val < limit) {
		if (fmod(val,2) == 0) {
			sum += val;
		}

		val = fibonacciNum(index);
		index+=1;
	}
	return sum;
}

//Checked
long P003() {
	long num=600851475143;
	return largestPrimeFactor(num);
}

//Checked
long P004() {
	int maxDig=3;
	return (long) largestPalindrome(maxDig,maxDig);
}

//Checked
long P005() {
	int min=1;
	int max=20;
	return (long) leastCommonMult(min, max);
}

//Checked
long P006() {
	long min=1;
	long max=100;
	return (squareSum(min,max) - sumSquare(min,max));
}

//Checked
long P007() {
	long index=10001;
	return primeByIndex(index);
}

long P008() {
	int nums[1000];
  int *point;
  point =(int *)&nums;
	charArrToIntArr(p008Series, point);
	return prodAdjNums(nums);
}

long P009() {
  long sum=1000;
	return prodPythTripSum(sum);
}

long P010() {
  //int limit=2000000;
  //return sumPrimesLessOrEqual(limit);
  int limit=2000000;
  return sumPrimesLessOrEqual(limit);
}

long P011() {

  int dimX=20;
  int dimY=20;
  int nums=4;
  //Create our 2D pointer
  int *point[dimX][dimY];
  for (int i=0; i<dimX; i++) {
    for (int j=0; j<dimY; j++) {
      point[i][j]=(int *)&P011MultiDimArr[i][j];
    }
  }

  return largestAdjProd(dimX, dimY, point, nums);
}

long P012() {
  long divs=500;
  return infinumTriNumByDiv(divs);
}

long P013() {
  int rows=100;
  int len=50;
  char *input="./libs/input.txt";
  int arr[rows][len];
	int sum[rows];
	int *point;
	point = (int *)&sum;

  fileToMultiDimArr(input, rows, len, arr, point);
	sumMultiDimArr(rows, len, arr, point);
	return arrToDouble(rows, sum);
}

long P014() {
  int bound=1000000;
  return longestCollatzChain(bound);
}

long P015() {
  Grid temp;
  temp.maxX=20;
  temp.maxY=20;
  Grid *grid;
  grid = (Grid *)&temp;
  return lattPaths(grid);
}

long P016() {
  int base=2;
  int exp=1000;

  int arr[exp];
  for (int i=0; i<exp; i++) {
    arr[i]=0;
  }
  arr[exp-1]=base;
  int *point;
  point = (int *) &arr;

  long temp = expArrInt(arr, exp, base, exp);

  //printArr(arr, exp);

  temp=0;
  for (int i=0; i<exp; i++) {
    temp += arr[i];
  }

  return temp;
}

long P017() {
  int min=1;
  int max=1000;

  return (long) largestNumLetCount(min, max);
}

long P018() {
  char fileStr[15] = "./libs/P018.txt";
  FILE *file = fopen(fileStr, "r");
  int maxRow = 0;
  int maxCol = 0;

  getFileDim(file, (int *)&maxRow, (int *)&maxCol);

	int arr[maxRow][maxCol];

  // -1 so we know what to skip over.
	for (int i=0; i<maxRow; i++) {
		for (int j=0; j<maxCol; j++) {
			arr[i][j]=-1;
		}
	}

	fileToIntMat(file, maxRow, maxCol, arr);
  return maxTriangPathSum(maxRow, maxCol, arr);
}

long P019() {
  return countSundays();
}

long P020() {
  long num = (long) 100;
  int digits = 200;//numDig(bound);
  int arr[digits];
  int *ptr = (int *)&arr;

  largeNumFactorial(num, ptr, digits);
  return sumArr(arr, digits);;
}

long P021() {
	int bound=1000;
	return sumAmicableNumbers(bound);
}

void result(long res) {
	printf("Result: %ld\n", res);
}

void resultL(long res) {
  printf("Result: %ld\n", res);
}

void runTime(int dur) {
	float temp;
	// There's gotta be a better way to do this, but that's for
	if (dur < 1000) {
		temp = ((float) 1000* dur) / ((float) CLOCKS_PER_SEC);
	} else {
	temp = (float) ((long) 1000* dur)/((float)CLOCKS_PER_SEC);
	temp /= (float)1000;
}
	printf("Runtime: %1.3lf s\n", temp);
}

void main(int argc, char *argv[]) {
	if (argc > 1) {
		// Looking for the solution to a problem
		if (strcmp(argv[1], "-p") == 0) {
			if (argc > 2) {
				// This feels a bit too repetitive, but it works
				time_t start;
				start = clock();
				if (strcmp(argv[2],"1") == 0) {
					result(P001());
				} else if (strcmp(argv[2],"2") == 0) {
					result(P002());
				} else if (strcmp(argv[2],"3") == 0) {
					result(P003());
				} else if (strcmp(argv[2],"4") == 0) {
					result(P004());
				} else if (strcmp(argv[2],"5") == 0) {
					result(P005());
				} else if (strcmp(argv[2],"6") == 0) {
					result(P006());
				} else if (strcmp(argv[2],"7") == 0) {
					result(P007());
				} else if (strcmp(argv[2],"8") == 0) {
					result(P008());
				} else if (strcmp(argv[2],"9") == 0) {
          result(P009());
        } else if (strcmp(argv[2],"10") == 0) {
          resultL(P010());
        } else if (strcmp(argv[2],"11") == 0) {
          result(P011());
        } else if (strcmp(argv[2],"12") == 0) {
          result(P012());
        } else if (strcmp(argv[2],"13") == 0) {
          result(P013());
        } else if (strcmp(argv[2],"14") == 0) {
          result(P014());
        } else if (strcmp(argv[2],"15") == 0) {
          result(P015());
        } else if (strcmp(argv[2],"16") == 0) {
          result(P016());
        } else if (strcmp(argv[2],"17") == 0) {
          result(P017());
        } else if (strcmp(argv[2],"18") == 0) {
          result(P018());
        } else if (strcmp(argv[2],"19") == 0) {
          result(P019());
        } else if (strcmp(argv[2],"20") == 0) {
          result(P020());
        } else if (strcmp(argv[2],"21") == 0) {
					result(P021());
				} else {
					printf("Not Solved\n");
				}
				int dur = clock()-start;
				runTime(dur);
			} else {
				printf("Invalid number of args\n");
			}
		} else {
			printf("Invalid Selection\n");
		}
	} else {
		printf("Invalid number of args\n");\
	}
}
