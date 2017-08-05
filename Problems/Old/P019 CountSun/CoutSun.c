#include <stdio.h>

/*
* Use main to call functions which will run through
* the years, counting the month starting on Sunday
* 0=Sunday,...,6=Saturday; start day is Monday
*/
void main() {

	//declare the year, sundays, and DoY counters
	int year=1900, sunday=0, doy = 1;
	int *sundays = &sunday;

	for (year=1900; year<=2000; year++) {
		thirtyOne(*sundays, *doy);						//January
		if (year % 4 == 0) {							//February
			leapYear(*sundays, *doy);
		} else {
			february(*sundays, *doy);
		}
		thirtyOne(*sundays, *doy);						//March
		thirty(*sundays, *doy);							//April
		thirtyOne(*sundays, *doy);						//May
		thirty(*sundays, *doy);							//June
		thirtyOne(*sundays, *doy);						//July
		thirtyOne(*sundays, *doy);						//August
		thirty(*sundays, *doy);							//September
		thirtyOne(*sundays, *doy);						//October
		thirty(*sundays, *doy);							//November
		thirty(*sundays, *doy);							//December
	}

	printf("Sundays: %d\n", sundays);

}

void february(int *sundays, int *doy) {

    int temp = *doy - 1;
    temp = temp % 7;

    if ((temp - 1) == 0) {
        *sundays = *sunday + 1;
    }
 
    *doy = temp;

}

void leapYear(int *sundays, int *doy) {

    int temp = *doy;
    temp = temp % 7;

    if ((temp - 1) == 0) {
        *sundays = *sunday + 1;
    }
 
    *doy = temp;

}

void thirty(int *sundays, int *doy) {

	int temp = *doy + 1;
	temp = temp % 7;
	
	if ((temp - 1) == 0) {
		*sundays = *sunday + 1;
	}

	*doy = temp;	
}

void thirtyOne(int *sundays, int *doy) {

    int temp = *doy + 2;
    temp = temp % 7;

    if ((temp - 1) == 0) {
        *sundays = *sunday + 1;
    }
 
    *doy = temp;

}
