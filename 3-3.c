/*
 * Exercise 3-3.
 *
 * Write a function expand(s1, s2) that expands shorthand notations like a-z in the string s1 into the equivalent complete list abc..xyz in s2. Allow for letters of either case and digits and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading sr trailing - is taken literally.
 */

#include <stdio.h>
// Hurr durr buffer overflow
#define BUFFER_SIZE 10000

void expand(char[], char[]);

int main() {
	char buffer1[BUFFER_SIZE];
	int i;
	char c;
	for(i = 0; (c = getchar()) != EOF; i++) {
		buffer1[i] = c;	
	}
	buffer1[i] = '\0';
	char buffer2[BUFFER_SIZE];
	expand(buffer1, buffer2);
	printf("%s", buffer2);
}

/*
 * Expand [char1]-[char2] shorthand notations
 *
 * Leading and trailing "-" are interpreted literally.
 * char2 needs to be greater than char1 to be a valid shorthand notation. (char2 > char1> must be true)
 */
void expand(char s1[], char s2[]) {
	int read_index = 0;
	int write_index = 0;
	while(s1[read_index] != '\0') {
		// If valid shorthand notation
		if(s1[read_index + 1] == '-' && s1[read_index + 2] != '\0' && s1[read_index] < s1[read_index + 2]) {
			// Insert s1[read_index]..s2[read_index] (expantion)
			for(char c = s1[read_index]; c <= s1[read_index + 2]; c++) {
				s2[write_index] = c;
				write_index++;
			}
			// Advance read_index past the processed shorthand notation
			read_index += 3;
		} else {
			s2[write_index] = s1[read_index];
			read_index++;
			write_index++;
		}
	}
	s2[write_index] = '\0';
}
