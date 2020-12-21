/*
 * Exercise 3-6.
 *
 * Write a version of itoa that accepts three arguments instead of two. The third argument is a minimum field width; the converted number must be padded with blanks on the left if necesarry to make it wide enough.
 */

#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// Hurr durr buffer overflow
#define BUFFER_SIZE 100

void itoa(int, char[], int);
void reverse(char[]);
void pad(char[], int);
int min(int, int);
int max(int, int);

int main() {
	char buffer[BUFFER_SIZE];

	int mwn = 3;
	itoa(12345, buffer, mwn);
	printf("%s\n", buffer);
	itoa(2, buffer, mwn);
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

/* pad: pad s, such that the minimum width is mfw, in place */
void pad(char s[], int mfw) {
	int l = strlen(s);
	int missing_spaces = max(0, mfw - l);

	int read_index = l - 1;
	int write_index = l - 1 + missing_spaces;
	s[write_index + 1] = '\0';

	while(read_index >= 0) {
		//printf("replace %c with %c\n", s[write_index], s[read_index]);
		s[write_index] = s[read_index];
		read_index--;
		write_index--;
	}
	while(write_index >= 0) {
		//printf("replace %c with %c\n", s[write_index], s[read_index]);
		s[write_index] = ' ';
		write_index--;
	}
}

void itoa(int n, char s[], int mwn) {
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
	pad(s, mwn);
}

int min(int a, int b) {
	return a < b ? a : b;
}

int max(int a, int b) {
	return a > b ? a : b;
}
