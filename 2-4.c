/*
 * Exercise 2-4.
 *
 * Write an alternative version of squeeze(s1,s2) that deletes each character in s1 that matches any character in the string s2.
 */

#include <stdio.h>

void squeeze(char[], char[]);

int main() {
	char s1[] = "Hei, jeg heter olav";
	char s2[] = "abcdefgvH";
	printf("s1: \"%s\"\n", s1);
	printf("s2: \"%s\"\n", s2);
	puts("squeeze(s1, s2)");
	squeeze(s1, s2);
	printf("s1: \"%s\"\n", s1);
}

void squeeze(char s1[], char s2[]) {
	// Delete each char in s1 that matches any char in s2
	for(int i = 0; s2[i] != '\0'; i++) {
		int read_index = 0;
		int write_index = 0;

		for(int read_index = 0; s1[read_index] != '\0'; read_index++) {
			if(s1[read_index] != s2[i]) {
				// Although it would be more readable to increment in next line, I don't because that is how it was done in the book.
				s1[write_index++] = s1[read_index];
			}
		}

		s1[write_index] = '\0';
	}
}
