/*
 * Exercise 4-2.
 *
 * Extend atof to handle scientific notation of the form
 * 123.45e-6
 * where a floating-point number may be followed by e or E and an optionally signed exponent.
 */

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

double atof(char[]);
int powi(int, int);

int main() {
	char fstr1[] = "123.321";
	printf("%s -> %f\n", fstr1, atof(fstr1));

	char fstr2[] = "3.1415";
	printf("%s -> %f\n", fstr2, atof(fstr2));

	char fstr3[] = "3.1415E2";
	printf("%s -> %f\n", fstr3, atof(fstr3));

	char fstr4[] = "3.1415E-2";
	printf("%s -> %f\n", fstr4, atof(fstr4));

	char fstr5[] = "3.1415E-0";
	printf("%s -> %f\n", fstr5, atof(fstr5));
}

double atof(char s[]){
	int i, sign;
	double val, power;

	for (i = 0; isspace(s[i]); i++);  /* skip white space */

	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-') i++;

	for(val = 0.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
	}

	if(s[i] == '.') i++;
	for(power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}

	val = sign * val / power;

	/* exponent must be integer */
	if(s[i] == 'e' || s[i] == 'E') { /* if exponent */
		i++;
		bool is_negative = s[i] == '-';
		if (s[i] == '+' || s[i] == '-') i++;
		int exponent;
		for(exponent = 0; isdigit(s[i]); i++) {
			exponent = 10 * exponent + (s[i] - '0');
		}

		val *= is_negative ? 1.0 / powi(10, exponent) : powi(10, exponent);
	}

	return val;
}

/* powi: get the power of a positive integer */
int powi(int base, int exponent) {
	return exponent == 0 ? 1 : base * powi(base, exponent - 1);
}
