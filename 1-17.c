/*
 * Exercise 1-17.
 *
 * Write a program to print all input lines that are longer than 80 characters.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool read_81_chars_of_line(char []);
void handle_line(char []);

int main() {
	char buffer[81]; // No null terminator

	for(;;) {
		handle_line(buffer);
	}
}

void handle_line(char buffer[]) {
	if(read_81_chars_of_line(buffer)) {
		for(int i = 0; i < 81; i++) {
			putchar(buffer[i]);
		}
		char c;
		while((c = getchar())) {
			switch(c) {
				case EOF:
					exit(EXIT_SUCCESS);
				case '\n':
					putchar(c);
					return;
				default:
					putchar(c);
			}
		}
	}
}

bool read_81_chars_of_line(char buffer[]) {
	for(int i = 0; i < 81; i++) {
		buffer[i] = getchar();
		switch(buffer[i]) {
			case EOF:
				exit(EXIT_SUCCESS);
			case '\n':
				return 0;
		}
	}
	return 1;
}
