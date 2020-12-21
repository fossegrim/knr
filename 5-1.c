/*
 * Exercise 5-1.
 *
 * As written, getint treats a + or - not followed by a figit as a valid representation of zero. Fix it to push such a character back on the input.
 */

#include <stdio.h>
#include <ctype.h>

#define MAXSIZE 10000

int getint(int*);

int main() {
    int status_code, n;

    while((status_code = getint(&n)) != EOF && status_code != 0) {
	printf("%d\n", n);
    }
}

int getch(void);
void ungetch(int);

/* getint:  get next integer from input into *pn */
int getint(int *pn) {
    int c, sign;
    while (isspace(c = getch()))   /* skip white space */
	;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
	ungetch(c);  /* it is not a number */
	return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
	c = getch();
	if(!isdigit(c)) {
	    /* put back chars and return to signal that it wa snot a number */
	    ungetch(sign == 1 ? '+' : '-');
	    ungetch(c);
	    return 0;
	}
    }
    for (*pn = 0; isdigit(c); c = getch())
	*pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
	ungetch(c);
    return c;
}

int sp = -1;
int stack[MAXSIZE];

int getch() {
    return sp >= 0 ? stack[sp--] : getchar();
}

void ungetch(int a) {
    stack[++sp] = a;
}
