/*
 * Exercise 1-20.
 *
 * Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter?
 */

#include <stdio.h>
#include <stdbool.h>

#define SPACES_PER_TAB 2

void indent();

int main() {
	char c;
	bool has_only_read_tabs_in_current_line = true;
	while((c = getchar()) != EOF) {
		if(c == '\t' && has_only_read_tabs_in_current_line) {
			indent();
			continue;
		}

		if(c == '\n') {
			has_only_read_tabs_in_current_line = true;
		}
		putchar(c);
	}
}

void indent() {
	for(int i = 0; i < SPACES_PER_TAB; i++) {
		putchar(' ');
	}
}
