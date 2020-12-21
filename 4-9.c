/*
 * Exercise 4-9.
 *
 * Our getch and ungetch do not handle a pushed-back EOF correctly. Decide what their properties ought to be if an EOF is pushed back, then implement your design.
 */

/*
 * /Our/ getch and ungetch does not handle pushed-back EOF correctly because EOF did not fit into a char at the time this was written. Today, however on x64 architecture a char can hold an EOF and as such nothing must be changed for our program to handle EOF.
 */

#include <stdio.h>
#include <string.h>

#define BUFSIZE 100 /* size of ungetch buffer */

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch();
void ungetch(int);

int main() {
	char c;
	char first_chars[11];
	first_chars[10] = '\0';

	/* should output stdin to stdout */
	while((c = getch()) != EOF) {
		putchar(c);
	}
}

int getch() { /* get a (possibly pushed-back) character */
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) { /* push character back on input */
	if (bufp >= BUFSIZE) printf("ungetch: too many characters\n");
	else buf[bufp++] = c;
}
