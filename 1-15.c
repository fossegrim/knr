/*
 * Exercise 1-15.
 *
 * Rewrite the temperature conversion program of Section 1.2 to use a function for conversion.
 */

#include <stdio.h>

float fahrenheit_to_celsius(float);

int main() {
	float fahr, celsius;
	float lower, upper, step;
	lower = 0;
	upper = 300;
	step = 20;
	fahr = lower;
	while (fahr <= upper) {
		celsius = fahrenheit_to_celsius(fahr);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}

float fahrenheit_to_celsius(float fahrenheit) {
	return (5.0/9.0) * (fahrenheit-32.0);
}
