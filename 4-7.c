/*
 * Exercise 4-7.
 *
 * Write a routine ungets(s) that will push back an entire string onto the input. Should ungets know about buf and bufp or should it just use ungetch?
 */

/*
 * ungets(s) should not know about buf and bufp and simply use ungetch, since code reuse is good and code duplication is bad.
 */

#include <stdio.h>
#include <string.h>

#define BUFSIZE 100 /* size of ungetch buffer */

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getop(char[]);
int getch();
void ungetch(int);
void ungets(char[]);

int main() {
	char c;
	char first_chars[11];
	first_chars[10] = '\0';

	/* should output stdin to stdout provided at least 10 chars are inputted */
	for(int i = 0; i < 10; i++) {
		first_chars[i] = getch();
	}
	ungets(first_chars);

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

void ungets(char s[]) {
	int l = strlen(s);
	for(int i = l - 1; i >= 0; i--) {
		ungetch(s[i]);
	}
}
