/*
 * Exercise 1-12.
 *
 * Write a program that prints its input one word per line.
 */

#include <stdio.h>

int is_whitespace(char);

int main() {
	int c;
	int prev_char_is_whitespace = 1;

	while((c = getchar()) != EOF) {
		if(!is_whitespace(c)) {
			putchar(c);
		} else if(!prev_char_is_whitespace) {
			putchar('\n');
		}
		prev_char_is_whitespace = is_whitespace(c);
	}
}

int is_whitespace(char c) {
	return c == ' ' || c == '\t' || c == '\n';
}
