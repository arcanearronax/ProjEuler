#include "ProjEuler.h"

double P001() {
	return (double)sumMultiples(3,5,1000);
}

double P002() {
	int limit = 4000000;

	int val=0;
	int sum=0;
	int index=1;

	while (val < limit) {
		if (val%2 == 0) {
			sum += val;
		}

		val = fibonacciNum(index);
		index++;
	}
	return (double) sum;
}

double P003() {
	double num=600851475143;
	return largestPrimeFactor(num);
}

double P004() {
	int maxDig=3;
	return (double) largestPalindrome(maxDig,maxDig);
}

double P005() {
	int min=1;
	int max=20;
	return (double) leastCommonMult(min, max);
}

double P006() {
	double min=1;
	double max=100;
	return (squareSum(min,max) - sumSquare(min,max));
}

double P007() {
	int index=10001;
	return primeByIndex(index);
}

double P008() {
	int nums[1000];
  int *point;
  point =(int *)&nums;
	charArrToIntArr(p008Series, point);
	return prodAdjNums(nums);
}

double P009() {
  double sum=1000;
	return prodPythTripSum(sum);
}

double P010() {
  //int limit=2000000;
  //return sumPrimesLessOrEqual(limit);
  int limit=2000000;
  return sumPrimesLessOrEqual(limit);
}

double P011() {

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



  //return (double) thingShit(dimX, dimY, point, nums);
  return largestAdjProd(dimX, dimY, point, nums);
}

double P012() {
  double divs=500;
  return infinumTriNumByDiv(divs);
}

double P013() {
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

double P014() {
  int bound=1000000;
  return longestCollatzChain(bound);
}

double P015() {
  Grid temp;
  temp.maxX=20;
  temp.maxY=20;
  Grid *grid;
  grid = (Grid *)&temp;
  return lattPaths(grid);
}

double P016() {
  int base=2;
  int exp=1000;

  int arr[exp];
  for (int i=0; i<exp; i++) {
    arr[i]=0;
  }
  arr[exp-1]=base;
  int *point;
  point = (int *) &arr;

  double temp = expArrInt(arr, exp, base, exp);

  //printArr(arr, exp);

  temp=0;
  for (int i=0; i<exp; i++) {
    temp += arr[i];
  }

  return temp;
}

double P017() {
  int min=1;
  int max=1000;

  return (double) largestNumLetCount(min, max);
}

double P018() {
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

double P019() {
  return countSundays();
}

double P020() {
  double num = (double) 100;
  int digits = 200;//numDig(bound);
  int arr[digits];
  int *ptr = (int *)&arr;

  largeNumFactorial(num, ptr, digits);
  return sumArr(arr, digits);;
}

double P021() {
	int bound=10000;
	return sumAmicableNumbers(bound);
}

void result(double res) {
	printf("Result: %.0lf\n", res);
}

void resultLL(long long res) {
  printf("Result: %lld\n", res);
}

void main(int argc, char *argv[]) {
	//0 indicates a match
	if (argc > 1) {
		if (strcmp(argv[1], "-p") == 0) {
			//printf("Success\n");
			if (argc > 2) {
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
          resultLL(P010());
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
