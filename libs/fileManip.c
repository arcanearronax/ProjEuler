#include <stdio.h>
#include "./arrayManip.c"

void fileToMultiDimArr(char *name, int rows, int len, int arr[][len], int *sum) {
  FILE *ptr = fopen(name, "r");

  for (int i=0; i<rows; i++) {
    sum[i] = 0;
  }

  //arr[0][0]=0;
  //printf("arr[0][0]=%d\n", arr[0][0]);
  int count=0;
  char buff[len+1];

  while (fgets(buff, sizeof(buff), ptr)) {
    //printf("TEST2\n");
    if (count%2 == 0) {
      for (int i=0; i<len; i++) {
        arr[count/2][i] = (int ) (buff[i]-'0');
        //printf("%d",arr[count/2][i]);
      }
      //printf(" - Test\n");
    }
    count++;
  }
}

//sum should have (rows) elements
void sumMultiDimArr(int rows, int len, int arr[][len], int *sum) {
  //Don't carry the one yet
  for (int i=len-1; i>=0; i--) {
    for (int j=0; j<rows; j++) {
      sum[i] += arr[j][i];
    }
  }

  //Now we need to carry the one
  int temp=0;
  for (int i=rows-1; i>0; i--) {
    temp=(int)(sum[i]/10);
    //printf("SUM[%d]=%d\n", i, sum[i]);
    sum[i]-=(temp*10);
    //printf(" \tTEMP=%d\n", temp);
    sum[i-1]+=temp;
    //printf("\t\tSUM[%d]=%d\n", i, sum[i]);
  }

  //And finally adjust if the 0'th term > 9
  while (sum[0] > 9) {
    for (int i=rows-1; i>1; i--) {
      sum[i] = sum[i-1];
    }
    sum[1] = (sum[0] % 10);
    sum[0]=(int)(sum[0] / 10);
  }
}

double sumNumsFile(char *name, int rows, int len) {
  	//Counter to add line from file to 2D array
  	int count = 0, index = 0, i, j, temp=0;
  	//create the character buffer to read in lines
  	char buff[len+1];
  	//Create a 2D array to hold the numbers, array for sum
  	int nums[rows][len], sum[rows];
    //Open the file which contains the numbers
  	FILE *ptr = fopen(name, "r");

  	//zero out the sum array
  	for (i=0; i<rows; i++) {
  		sum[i] = 0;
  	}

  	//Read in the file ptr line by line
  	while (fgets(buff, sizeof(buff), ptr)) {
  		if (count % 2 == 0) {
  			for (index=0; index<len; index++) {
  				nums[count/2][index] = ((int) buff[index]-'0');
  			}
  		}
  		//Counter to move down one row after converting the first number
  		count++;
  	}

  	//nested loop to add the numbers in the arrays, i=col & j=row
  	for (i=len-1; i>=0; i--) {
  		for (j=0; j<rows; j++) {
  			sum[i+len] += nums[j][i];
  		}
  	}

  	//carry the values in columns, since it's likely they're > 9
  	for (i=rows-1; i>=0; i--) {
  		temp = sum[i] / 10;
  		sum[i-1] += temp;
  		sum[i] = sum[i] % 10;
  	}
  return (double) 1;
}

void getFileDim(FILE *ptr, int *maxRow, int *maxCol) {

  int len = 10000;
  char buff[len];

  for (int i=0; i<len; i++) {
    buff[i]='\0';
  }

  int countCol = 0;
  do {
    if (strcmp(buff,"\0\n") != 0) {
      *maxRow += 1;
    }

    for (int i=0; i<len; i++) {
      countCol++;

      if (buff[i] == '\0') {
        break;
      }

      if (buff[i] != '\n') {
        //printf("test: %c\n",buff[i]);
        if (countCol > *maxCol) {
          *maxCol = countCol;
        }
      }
    }
    countCol=0;

    for (int i=0; i<len; i++) {
      buff[i]='\0';
    }

    //printf("maxRow=%d,\tmaxCol=%d\n",maxRow, maxCol);

  } while (fgets(buff, sizeof(buff), ptr));
  rewind(ptr);
}

// Completed
void fileToIntMat(FILE *ptr, int maxRow, int maxCol, int arr[][maxCol]) {
  char buff[maxCol+3];

  int countCol=0;
  int countRow=0;
  while (fgets(buff, sizeof(buff), ptr)) {
    //printf("TEST=%s\n",buff);
    for (int i=0; i<maxCol; i++) {
      if (buff[i] >= '0' && buff[i] <= '9') {
        //printf("i=%d\n", i);
        int tInt = (int) (((int)(buff[i] - '0')))*10 + (int)(buff[i+1] - '0');

        //printf("tInt=%d\tcountCol=%d\n", tInt, countCol);
        arr[countRow][countCol] = tInt;
        countCol++;
        i++;
      }
    }
    //printf("\n");
    //printf("TEST: %s\n", buff);
    countCol=0;
    countRow++;
  }
}

double maxTriangPathSum(int maxRow, int maxCol, int arr[][maxCol]) {

  double sum = (double) arr[0][0];

  int rowLen = 0;
  for (int i=0; i<maxCol; i++) {
    if (arr[maxRow-1][i] != -1) {
      rowLen++;
    }
  }

  for (int i=maxRow-1; i>=0; i--) {
    for (int j=0; j<rowLen; j++) {
      if (arr[i][j] != -1) {
        //printf("%d", arr[i][j]);

        if (arr[i][j] > arr[i][j+1]) {
          arr[i-1][j] += arr[i][j];
        } else {
          arr[i-1][j] += arr[i][j+1];
        }

      }
    }
    rowLen--;
  }
  return (double) arr[0][0];
}

void getNameMaxes(FILE *filePtr, int *maxLen, int *nameCount) {
  char buff = fgetc(filePtr);

  int tNameCount=1;
  int maxNameLen=0;
  int curNameLen=0;
  do {
    //printf("\tBREAK\n");
    if (buff != '"') {
      if (buff == ',') {
        tNameCount++;
        if (curNameLen > maxNameLen) {
          maxNameLen = curNameLen;
        }
        curNameLen=0;
      } else {
        curNameLen++;
        //printf("CurNameLen: %c\n",buff);
      }
    }
  } while ((buff=fgetc(filePtr)) != EOF);

  maxLen[0] = maxNameLen;
  nameCount[0] = tNameCount;
  rewind(filePtr);
}

void readInNames(FILE *filePtr, int maxLen, char arr[][maxLen]) {
  char buff = fgetc(filePtr);

  int row=0;
  int col=0;
  do {
    if (buff != '"') {
      if (buff == ',') {
        row++;
        col=0;
      } else {
        arr[row][col] = buff;
        col++;
      }
    }
  } while ((buff=fgetc(filePtr)) != EOF);
}
