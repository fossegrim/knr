/*
 * Exercise 1-14.
 *
 * Write a program to print a histogram of the frequencies of different characters in its input.
 */

#include <stdio.h>
#define ASCII_CHARS 256

int is_whitespace(char);

int main() {
	char character_instances[ASCII_CHARS] = {0};

	int c;
	while((c = getchar()) != EOF) {
		character_instances[c]++;
	}

	for(int i = 0; i < ASCII_CHARS; i++) {
		if(character_instances[i] == 0) {
			continue;
		}

		switch(i) {
			case '\t':
				printf("\\t ");
				break;
			case '\n':
				printf("\\n ");
				break;
			default:
				printf("%c  ", i);
		}

		for(int j = 0; j < character_instances[i]; j++) {
			putchar('#');
		}

		puts("");
	}
}
