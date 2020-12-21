/*
 * Exercise 1-16.
 *
 * Revise the main routine of the longest-line program so it will correctly print the length of arbitrary long input lines, and as much as possible of the text.
 */

// excuse the mess.
// I wrote this 3:30 at night so it is probably bad...
// READ ONLY
#include <stdio.h>
#define MAXLINE 1000

int getline_(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];
	max = 0;
	while((len = getline_(line, MAXLINE)) > 0) {
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}

	if (max > 0) {
		printf("\"");
		printf("%s", longest);
		printf("\"\n");
		printf("length: %d\n", max);
	}

	return 0;
}

int getline_(char s[],int lim) {
	// set as much of the line there is space for to char and return the correct length
	// off by one
	int c, i;
	for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c!='\n'; i++) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	if (c != EOF && c != '\n') {
		// limit was hit
		for(; (c = getchar()) != EOF; i++) {
			if(c == '\n') {
				i++;
				break;
			}
		}
	}
	return i;
}

void copy(char to[], char from[]) {
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0') {
		++i;
	}
}
