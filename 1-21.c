/*
 * Exercise 1-21.
 *
 * Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. When either a tab or a single blank would suffice to reach a tab stop, which should be given preference?
 */

#include <stdio.h>
#include <stdbool.h>

/*
 * This is not actually how wide a tab is on my computer, but the program is the same nonetheless
 * The exercise instructed to use the "tab-stop" from the previous exercise and so I did.
 */
#define SPACES_PER_TAB 2

void print_blanks();

int main() {
	char c;
	int blanks_since_tab = 0; // how many blanks read since last print tab
	int blanks_in_a_row = 0; // how many blanks read sequentially

	while((c = getchar()) != EOF) {
		if(c == ' ') {
			blanks_since_tab++;
			blanks_in_a_row++;
			if(blanks_in_a_row % SPACES_PER_TAB == 0) {
				putchar('\t');
				blanks_since_tab = 0;
			}
			continue;
		}

		print_blanks(blanks_since_tab);
		blanks_in_a_row = 0;
		blanks_since_tab = 0;
		if(c != '\t') {
			putchar(c);
		}
	}
	print_blanks(blanks_since_tab);
}

void print_blanks(int amount) {
	for(int i = 0; i < amount; i++) {
		putchar(' ');
	}
}
