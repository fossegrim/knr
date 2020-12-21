/*
 * Exercise 3-4.
 *
 * In a two's complement number respresentation, our version of itoa does not handle the largest negative number, that is, the value of n equal to -(2^(wordsize-1)). Explain why not. Modify it to print that value correctly, regardless of the machine on which it runs.
 */

/*
 * The reason, /our/ version of itoa does not handle the largest negative value, is that when n is negated it overflows since the absolute value of the INT_MIN is greater than the value of INT_MAX.
 */

#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// Hurr durr buffer overflow
#define BUFFER_SIZE 100

void itoa(int, char[]);
void reverse(char[]);

int main() {
	char buffer[BUFFER_SIZE];

	// Should print INT_MAX and INT_MIN
	itoa(INT_MAX, buffer);
	printf("%s\n", buffer);

	itoa(INT_MIN, buffer);
	printf("%s\n", buffer);
}

/* reverse:  reverse string s in place */
void reverse(char s[]) {
	int c, i, j;
	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void itoa(int n, char s[]) {
	int i = 0;
	bool is_negative = n < 0;
	do {
		s[i++] = abs(n % 10) + '0';
	} while((n /= 10) != 0);
	if(is_negative) {
		s[i++] = '-';
	}
	s[i] = '\0';
	reverse(s);
}
