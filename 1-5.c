/*
 * Exercise 1-5.
 *
 * Modify the temperature conversion program to print the table in reverse order, that is, from 300 degrees to 0.
 */

#include <stdio.h>

int main() {
	float fahr, celsius;
	float lower, upper, step;
	lower = 0;
	upper = 300;
	step = 20;
	celsius = upper;
	printf("°C   °F\n");
	while (celsius >= lower) {
		fahr = celsius / (5.0/9.0) + 32.0;
		printf("%3.0f %6.1f\n", celsius, fahr);
		celsius -= step;
	}
}
