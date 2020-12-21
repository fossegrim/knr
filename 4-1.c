/*
 * Exercise 4-1.
 *
 * Write the function strindex(s, t) which returns the position of the rightmost occurence of t in s, or -1 if there is none.
 */

#include <stdio.h>
#include <stdbool.h>

#define BUFFER_SIZE 10000

int strindex(char[], char[]);
bool match(char[], int, char[]);

int main() {
	char s1[] = "test";
	char t1[] = "test";
	printf("index: %d\n", strindex(s1, t1)); // 0

	char s2[] = "testtest";
	char t2[] = "test";
	printf("index: %d\n", strindex(s2, t2)); // 4

	char s3[] = "testest";
	char t3[] = "test";
	printf("index: %d\n", strindex(s3, t3)); // 3

	char s4[] = "tesest";
	char t4[] = "test";
	printf("index: %d\n", strindex(s4, t4)); // -1
}

/* strindex: return index of t in s or -1 if not found */
int strindex(char s[], char t[]) {
	int match_index = -1;
	for(int i = 0; s[i] != '\0'; i++) {
		if(match(s, i, t)) {
			match_index = i;
		}
	}

	return match_index;
}

/* match: return true, if the s1, starting from i1, contains s2 */
bool match(char s1[], int i1, char s2[]) {
	// puts("===========");
	for(int i = 0;; i++) {
		// The end of either string is reached
		if(s2[i] == '\0') {
			return true;
		} else if(s1[i1 + i] == '\0' || s1[i1 + i] != s2[i]) {
			return false;
		}
	}
}
