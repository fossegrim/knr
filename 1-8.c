/*
 * Exercise 1-8.
 *
 * Write a program to count blanks, tabs, and newlines.
 */

#include <stdio.h>
int main() {
	int blanks = 0;
	int tabs = 0;
	int newlines = 0;

	int c;
	while((c = getchar()) != EOF) {
		switch(c) {
			case ' ':
				blanks++;
				break;
			case '\t':
				tabs++;
				break;
			case '\n':
				newlines++;
				break;
		}
	}

	printf("blanks: %d\n", blanks);
	printf("tabs: %d\n", tabs);
	printf("newlines: %d\n", newlines);
}
