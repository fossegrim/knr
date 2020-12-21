/*
 * Exercise 1-18.
 *
 * Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines.
 */

#include <stdio.h>
#include <stdbool.h>
#define BUFFER_SIZE 1000

bool handle_line(char []);
bool is_whitespace(char);
void print_without_trailing_whitespace(char[], int);

int main() {
	// DONE delete blank lines
	// TODO remove trailing whitespace
	char buffer[BUFFER_SIZE];
	while(handle_line(buffer));
}


// handle a line and return 0 if the end if EOF
bool handle_line(char buffer[]) {
	bool is_only_whitespace = true;
	bool is_eof_reached = false;
	int i;
	for(i = 0; i < BUFFER_SIZE; i++) {
		char c = getchar();
		if(c == EOF) {
			is_eof_reached = true;
			break;
		} else if(!is_whitespace(c)) {
			is_only_whitespace = false;
		}
		buffer[i] = c;
		if(c == '\n') {
			break;
		}
	}
	if(!is_only_whitespace) {
		int chars_read = i + 1;
		print_without_trailing_whitespace(buffer, chars_read);
	}
	if(is_eof_reached) {
		return 0;
	} else {
		return 1;
	}
}

bool is_whitespace(char c) {
	return c == ' ' || c == '\n' || c == '\t' || c == '\r';
}

void print_without_trailing_whitespace(char buffer[], int length) {
	int last_index_to_print = length - 1;
	for(int i = length - 1; i >= 0; i--) {
		if(!is_whitespace(buffer[i])) {
			last_index_to_print = i;
			break;
		}
	}

	for(int i = 0; i <= last_index_to_print; i++) {
		putchar(buffer[i]);
	}

	// Print missing newline
	puts("");
}
