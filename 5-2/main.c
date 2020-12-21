/*
 * Exercise 5-2.
 *
 * Write getfloat, the floating-point analog of getint. What type does getfloat return as its function value?
 */

/*
 * getfloat returns int its function value. The floating-point is written to the pointee.
 */

#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAXSIZE 10000

int getfloat(double*);

int main() {
    int status_code;
    double f;

    while((status_code = getfloat(&f)) != EOF && status_code != 0) {
	printf("%f\n", f);
    }
}

int getch(void);
void ungetch(int);

/* getfloat:  get next floating-point from input into *pf */
int getfloat(double *pf) {
    int c, sign, power = 0;

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
    /* read integral part */
    for (*pf = 0; isdigit(c); c = getch())
	*pf = 10 * *pf + (c - '0');
        /* read mantissa */
    switch(c) {
    case '.': /* english decimal point*/
    case ',': /* norwegian decimal point*/
    {
	c = getch();

	while(isdigit(c)) {
	    *pf = 10 * *pf + (c - '0');
	    power++;

	    c = getch();
	}
    }
    }
    if (c != EOF)
	ungetch(c);
    *pf *= sign;
    *pf = *pf / pow(10, power);
    return c;
}

int sp = -1;
double stack[MAXSIZE];

int getch() {
    return sp >= 0 ? stack[sp--] : getchar();
}

void ungetch(int a) {
    stack[++sp] = a;
}
