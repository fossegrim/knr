/*
 * Exercise 3-5.
 *
 * Write the function itob(n, s, b) that convers tthe interger n into a base b character representation in the strings. In particular, itob(n, s, 16) formats s as a hexadecimal integer s.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000

void reverse(char[]);
void itob(int, char[], int);
char ctob(char, int);
char dtoc(int);

int main() {
	char buffer[BUFFER_SIZE];

	char n = -17;
	int base = 2;
	itob(n, buffer, base);
	printf("%d in base%d is %s\n", n, base, buffer); /* -10001 */

	n = -16;
	base = 8;
	itob(n, buffer, base);
	printf("%d in base%d is %s\n", n, base, buffer); /* 20 */

	n = -31;
	base = 16;
	itob(n, buffer, base);
	printf("%d in base%d is %s\n", n, base, buffer); /* -1f */
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

/* b must be from 2 to 16 */
void itob(int n, char s[], int base) {
	int i = 0;
	bool is_negative = n < 0;
	do {
		s[i++] = dtoc(abs(n % base));
	} while((n /= base) != 0);
	if(is_negative) {
		s[i++] = '-';
	}
	s[i] = '\0';
	reverse(s);
}

/* dtoc: return a char representing the passed int */
char dtoc(int digit) {
	return (digit <= 9 ? '0' : 'A' - 10) + digit;
}
