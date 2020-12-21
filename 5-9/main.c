/*
 * Exercise 5-9.
 *
 * Rewrite the routines day_of_year and month_day with pointers instead of indexing.
 */

#include <stdio.h>

int day_of_year(int, int, int);
int month_day(int, int, int *, int *);
void test_day_of_year();
void test_month_day();

int main() {
    test_day_of_year();
    puts("===---===");
    test_month_day();
}

void test_day_of_year() {
    int year, month, day, doy;

    /* valid date */
    year = 2020;
    month = 1;
    day = 1;
    doy = day_of_year(year, month, day);
    if(doy == -1) {
	fprintf(stderr, "error: invalid date %04d-%02d-%02d\n", year, month, day);
    } else {
	printf("%04d-%02d-%02d is the %d. day in the year\n", year, month, day, doy);
    }

    /* month too low */
    year = 2003;
    month = 0;
    day = 1;
    doy = day_of_year(year, month, day);
    if(doy == -1) {
	fprintf(stderr, "error: invalid date %04d-%02d-%02d\n", year, month, day);
    } else {
	printf("%04d-%02d-%02d is the %d. day in the year\n", year, month, day, doy);
    }

    /* month too high */
    year = 2005;
    month = 13;
    day = 1;
    doy = day_of_year(year, month, day);
    if(doy == -1) {
	fprintf(stderr, "error: invalid date %04d-%02d-%02d\n", year, month, day);
    } else {
	printf("%04d-%02d-%02d is the %d. day in the year\n", year, month, day, doy);
    }

    /* day too low */
    year = 2010;
    month = 2;
    day = 0;
    doy = day_of_year(year, month, day);
    if(doy == -1) {
	fprintf(stderr, "error: invalid date %04d-%02d-%02d\n", year, month, day);
    } else {
	printf("%04d-%02d-%02d is the %d. day in the year\n", year, month, day, doy);
    }

    /* day too high (not leap year) */
    year = 2007;
    month = 2;
    day = 29;
    doy = day_of_year(year, month, day);
    if(doy == -1) {
	fprintf(stderr, "error: invalid date %04d-%02d-%02d\n", year, month, day);
    } else {
	printf("%04d-%02d-%02d is the %d. day in the year\n", year, month, day, doy);
    }

    /* valid date (leap year) */
    year = 2008;
    month = 2;
    day = 29;
    doy = day_of_year(year, month, day);
    if(doy == -1) {
	fprintf(stderr, "error: invalid date %04d-%02d-%02d\n", year, month, day);
    } else {
	printf("%04d-%02d-%02d is the %d. day in the year\n", year, month, day, doy);
    }
}

void test_month_day() {
    int year, yearday, month, monthday, success;

    /* valid date */
    year = 2020;
    yearday = 1;
    success = month_day(year, yearday, &month, &monthday);
    if(success) {
	printf("%04d/%03d (year/day) equivalent to %04d-%02d-%02d\n", year, yearday, year, month, monthday);
    } else {
	fprintf(stderr, "error: invalid year/day combination %04d/%03d\n", year, yearday);
    }

    /* day too low */
    year = 2007;
    yearday = 0;
    success = month_day(year, yearday, &month, &monthday);
    if(success) {
	printf("%04d/%03d (year/day) equivalent to %04d-%02d-%02d\n", year, yearday, year, month, monthday);
    } else {
	fprintf(stderr, "error: invalid year/day combination %04d/%03d\n", year, yearday);
    }

    /* day too high (not leap year) */
    year = 2019;
    yearday = 366;
    success = month_day(year, yearday, &month, &monthday);
    if(success) {
	printf("%04d/%03d (year/day) equivalent to %04d-%02d-%02d\n", year, yearday, year, month, monthday);
    } else {
	fprintf(stderr, "error: invalid year/day combination %04d/%03d\n", year, yearday);
    }

    /* valid date (leap year) */
    year = 2020;
    yearday = 366;
    success = month_day(year, yearday, &month, &monthday);
    if(success) {
	printf("%04d/%03d (year/day) equivalent to %04d-%02d-%02d\n", year, yearday, year, month, monthday);
    } else {
	fprintf(stderr, "error: invalid year/day combination %04d/%03d\n", year, yearday);
    }
}

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year:  return day of year from month & day, return -1 if month or day is invalid*/
int day_of_year(int year, int month, int day)
{
    int i, leap;
    leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;

    if(month > 12 || month < 1) return -1;
    if(day > *(*(daytab + leap) + month) || day < 1) return -1;

    for (i = 1; i < month; i++)
	day += *(*(daytab + leap) + i);
    return day;
}

/* month_day:  set month, day from day of year, return 0 if the year and yearday combination is invalid, else return 1 */
int month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;

    if(yearday < 1 || yearday > 365 + leap) return 0;

    for (i = 1; yearday > *(*(daytab + leap) + i); i++)
	yearday -= *(*(daytab + leap) + i);
    *pmonth = i;
    *pday = yearday;
    return 1;
}
