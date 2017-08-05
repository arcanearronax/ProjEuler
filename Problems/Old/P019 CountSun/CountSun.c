#include <stdio.h>

void february(int *sundays, int *doy);
void leapYear(int *sundays, int *doy);
void thirty(int *sundays, int *doy);
void thirtyOne(int *sundays, int *doy);

/*
* Use main to call functions which will run through
* the years, counting the month starting on Sunday
* 0=Sunday,...,6=Saturday; start day is Monday
*/
void main() {

	//declare the year, sundays, and DoY counters
	int year=1901, sundays=0, doy = 1;
	//int *sundays = &sunday;

	for (year=1901; year<2001; year++) {
		thirtyOne(&sundays, &doy);						//January
		printf("Jan %d, %d\n", year, doy);
		if ((year % 4 == 0) && (year != 1900)) {		//February
			leapYear(&sundays, &doy);
			printf("Leap %d, %d\n", year, doy);
		} else {
			february(&sundays, &doy);
			printf("Feb %d, %d\n", year, doy);
		}
		thirtyOne(&sundays, &doy);						//March
		printf("Mar %d, %d\n", year, doy);
		thirty(&sundays, &doy);							//April
		printf("Apr %d, %d\n", year, doy);
		thirtyOne(&sundays, &doy);						//May
		printf("May %d, %d\n", year, doy);
		thirty(&sundays, &doy);							//June
		printf("Jun %d, %d\n", year, doy);
		thirtyOne(&sundays, &doy);						//July
		printf("Jul %d, %d\n", year, doy);
		thirtyOne(&sundays, &doy);						//August
		printf("Aug %d, %d\n", year, doy);
		thirty(&sundays, &doy);							//September
		printf("Sep %d, %d\n", year, doy);
		thirtyOne(&sundays, &doy);						//October
		printf("Oct %d, %d\n", year, doy);
		thirty(&sundays, &doy);							//November
		printf("Nov %d, %d\n", year, doy);
		thirtyOne(&sundays, &doy);						//December
		printf("Dec %d, %d\n", year, doy);
	}

	printf("Sundays: %d\n", sundays);

}

/*
* The value of doy will correspond to the
* end day of the month calculated
*/

void february(int *sundays, int *doy) {

    int temp = *doy;
    temp = temp % 7;

    if ((temp + 1) % 7 == 0) {
        *sundays = *sundays + 1;
    }
 
    *doy = temp;

}

void leapYear(int *sundays, int *doy) {

    int temp = *doy + 1;
    temp = temp % 7;

    if ((temp) % 7 == 0) {
        *sundays = *sundays + 1;
    }
 
    *doy = temp;

}

void thirty(int *sundays, int *doy) {

	int temp = *doy + 2;
	temp = temp % 7;
	
	if ((temp - 1) % 7 == 0) {
		*sundays = *sundays + 1;
	}

	*doy = temp;	
}

void thirtyOne(int *sundays, int *doy) {

    int temp = *doy + 3;
    temp = temp % 7;

    if ((temp - 2) % 7 == 0) {
        *sundays = *sundays + 1;
    }
 
    *doy = temp;

}
