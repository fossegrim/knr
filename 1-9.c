/*
 * Exercise 1-9.
 *
 * Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.
 */

#include <stdio.h>

int main() {
	int is_prev_char_blank = 0;

	int c;
	while((c = getchar()) != EOF) {
		if(c != ' ') {
			putchar(c);
		} else if(!is_prev_char_blank) {
			putchar(' ');
		}
		is_prev_char_blank = c == ' ';
	}
}
