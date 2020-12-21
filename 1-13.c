/*
 * Exercise 1-13.
 *
 * Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
 */

#include <stdio.h>

int is_whitespace(char);

int main() {
	int word_length = 0;
	int prev_char = ' '; // Must be whitespace initially

	int c;

	while((c = getchar()) != EOF) {
		if(!is_whitespace(c)) {
			word_length++;
		} else if(!is_whitespace(prev_char)) {
			for(int i = 0; i < word_length; i++) {
				printf("#");
			}
			printf("\n");
			word_length = 0;
		}
		prev_char = c;
	}
}

int is_whitespace(char c) {
        return c == ' ' || c == '\t' || c == '\n';
}
