/*
 * Exercise 4-12.
 *
 * Adapt the ideas of printd to write a recursive version of itoa; that is, convert an integer into a string by calling a recursive routine
 */

#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 1000

int main() {
	int n;
	char s[BUFSIZE];
	void itoa(int, char[]);

	n = 123456;
	itoa(n, s);
	printf("%d = %s\n", n, s);

	n = -321456;
	itoa(n, s);
	printf("%d = %s\n", n, s);

	n = 0;
	itoa(n, s);
	printf("%d = %s\n", n, s);
}

void itoa(int n, char s[]) {
	int m;
	int digits(int);
	void itoa_recurse(int, char[], int);

	m = digits(n);

	s[0] = n >= 0 ? '+' : '-';
	s[m + 1] = '\0';
	itoa_recurse(abs(n), s, m);
}

int digits(int n) {
	int i;
	for(i = 1; (n /= 10) != 0; i++);
	return i;
}

void itoa_recurse(int n, char s[], int digits) {
	/* void itoa_recurse(int, char[], int); */
	if(digits == 0) return;

	s[digits] = n % 10 + '0';
	itoa_recurse(n / 10, s, digits - 1);
}

