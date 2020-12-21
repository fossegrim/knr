/*
 * Exercise 3-2.
 *
 * Write a function escape(s,t) that converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a function for the other direction as well, converting escape sequences into real characters.
 */

#include <stdio.h>
// hurr durr buffer overflow hurr durr
#define BUFFER_SIZE 100

void escape(char[], char[]);
void unescape(char[], char[]);

int main() {
	char buffer1[BUFFER_SIZE];
	int i;
	char c;
	for(i = 0; (c = getchar()) != EOF; i++) {
		buffer1[i] = c;
	}
	buffer1[i+1] = '\0';

	puts("---ESCAPED---");
	char buffer2[BUFFER_SIZE];
	escape(buffer1, buffer2);
	printf("%s\n", buffer2);
	puts("---UNESCAPED---");
	char buffer3[BUFFER_SIZE];
	unescape(buffer2, buffer3);
	printf("%s\n", buffer3);
}

void escape(char s1[], char s2[]) {
	int read_index = 0;
	int write_index = 0;
	while(s1[read_index] != '\0') {
		switch(s1[read_index]) {
			case '\n':
				s2[write_index] = '\\';
				write_index++;
				s2[write_index] = 'n';
				break;
			case '\t':
				s2[write_index] = '\\';
				write_index++;
				s2[write_index] = 't';
				break;
			default:
				s2[write_index] = s1[read_index];
		}

		read_index++;
		write_index++;
	}
	s2[write_index] = '\0';
}

void unescape(char s1[], char s2[]) {
	int read_index = 0;
	int write_index = 0;
	while(s1[read_index] != '\0') {
		if(s1[read_index] == '\\') {
			read_index++;
			switch(s1[read_index]) {
				case 'n':
					s2[write_index] = '\n';
					break;
				case 't':
					s2[write_index] = '\t';
					break;
				default:
					s2[write_index] = '\\';
					write_index++;
					s2[write_index] = s1[read_index];
			}
		} else {
			s2[write_index] = s1[read_index];
		}

		read_index++;
		write_index++;
	}
	s2[write_index] = '\0';
}
