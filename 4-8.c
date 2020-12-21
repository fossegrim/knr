/*
 * Exercise 4-8.
 *
 * Suppose that there will never be more than one character of pushback. Modify getch and ungetch accordingly.
 */

#include <stdio.h>
char push_backch = EOF;

char getch();
void ungetch(char);

int main() {
	char c;

	/* output stdin to stdout */
	while((c = getch()) != EOF) {
		ungetch(c);
		c = getch();
		putchar(c);
	}
}

char getch() { /* get a (possibly pushed-back) character */
	if(push_backch == EOF) {
		return getchar();
	} else {
		char temp = push_backch;
		push_backch = EOF;
		return temp;
	}
}

void ungetch(char c) { /* push character back on input */
	push_backch = c;
}
