/*
 * Exercise 2-10.
 *
 * Rewrite the function lower, which converts upper case letters to lower case, with a conditional expression.
 */

#include <stdio.h>

int lower(char);

int main() {
	printf("%c -> %c\n", 'A', lower('A'));
	printf("%c -> %c\n", 'Z', lower('Z'));
}

int lower(char c) {
	return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}
