/*
 * Exercise 1-19.
 *
 * Write a function reverse(s) that reverses the character string s. Use it to write a program that reverses its input a line at a time.
 */

#include <stdio.h>
#define BUFFER_SIZE 1000

void reverse(char[], int length);
int max(int, int);
void print_buffer(char[], int);

int main() {
	char line[BUFFER_SIZE];
	int line_length = 0;
	char c;
	while((c = getchar()) != EOF) {
		switch(c) {
			case '\n':
				reverse(line, line_length);
				print_buffer(line, line_length);
				puts("");
				line_length = 0;
				break;
			default:
				line[line_length] = c;
				line_length++;
		}
	}
	reverse(line, line_length);
	print_buffer(line, line_length);
}

void reverse(char s[], int length) {
	if(length == 0) {
		return;
	}

	int max_offset = max((length / 2) - 1, 0);
	for(int offset = 0; offset <= max_offset; offset++) {
		char temp = s[offset];
		s[offset] = s[length - 1 - offset];
		s[length - 1 - offset] = temp;
	}
}

void print_buffer(char buffer[], int buffer_length) {
	for(int i = 0; i < buffer_length; i++) {
		putchar(buffer[i]);
	}
}

int max(int a, int b) {
	return a > b ? a : b;
}
