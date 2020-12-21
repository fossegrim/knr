/*
 * Exercise 4-6.
 *
 * Add commands for handling variables. (It's easy to provide twenty-siz variables with single-letter names.) Add a variable for the most recently printed value.
 */

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>
#include <math.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define MAXVAL 100 /* maximum depth of val stack */
#define BUFSIZE 100 /* size of ungetch buffer */

void push(double);
double pop();
double top();
int getop(char[]);
int getch();
void ungetch(int);

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

/* reverse Polish calculator */
int main() {
	int type;
	double op2;
	char s[MAXOP];
	int x = 0, y = 0, z = 0, m = 0; /* xyz are used defined variables and m is the last printed value */
	while ((type = getop(s)) != EOF) {
		switch(type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if(op2 == 0.0) {
				puts("error: zero divisor\n");
			} else {
				push(pop() / op2);
			}
			break;
		case '%':
			op2 = pop();
			double op1 = pop();
			if(op2 - (int) op2 + op1 - (int) op1 > 0) {
				puts("diregarding the operands' mantissas");
			}
			if(op2 == 0.0) {
				puts("error: zero divisor\n");
			} else {
				push((int) op1 % (int) op2);
			}
			break;
		case 's':
			push(sin(pop()));
			break;
		case 'e':
			push(exp(pop()));
			break;
		case 'p':
			op2 = pop();
			push(pow(pop(), op2));
			break;
		case '\n':
			printf("\t%.8g\n", top());
			m = top();
			break;
		case 'd': /* duplicate */
			push(top());
			break;
		case 'S': /* swap */
			op2 = pop();
			op1 = pop();
			push(op2);
			push(op1);
			break;
		case 'P': /* pop */
			pop();
			break;
		case 'c': /* clear */
			sp = 0;
			break;
		/* get variable */
		case 'x':
			push(x);
			break;
		case 'y':
			push(y);
			break;
		case 'z':
			push(z);
			break;
		case 'm':
			push(m);
			break;
		/* set variable */
		case 'X':
			x = pop();
			break;
		case 'Y':
			y = pop();
			break;
		case 'Z':
			z = pop();
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
}

/* push:  push f onto value stack */
void push(double f) {
	if (sp < MAXVAL) val[sp++] = f;
	else printf("error: stack full, can't push %g\n", f);
}

/* pop:  pop and return top value from stack */
double pop() {
	if (sp > 0) return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* top:  return the top value from stack */
double top() {
	if (sp > 0) return val[sp - 1];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* getop:  get next character or numeric operand */
int getop(char s[]) {
	// Skip whitespace
	char c;
	while ((c = getch()) == ' ' || c == '\t');

	// If encounter -, determine if it is a number in which case (write '-' to s[0] and set i=1). If it is not a number ungetch '-'
	int i = 0;
	if(c == '-') {
		char next_c = getch();
		ungetch(next_c);

		if(next_c == '.' || isdigit(next_c)) {
			s[i] = '-';
			i++;
		} else {
			ungetch(c); /* put back so that it is read as a operator */
		}
	} else {
		ungetch(c);
	}

	c = getch();
	if(!(c == '.' || isdigit(c))) { /* return operator */
		s[0] = c;
		s[1] = '\0';
		return c;
	}
	ungetch(c);

	// at this point, i should be the index we should write the digits to (1 if there is a '-' in s[0], 0 otherwise), and getch should read the first digit or '.' of our numbre
	// read the number to s
	while(isdigit(c = getch())) {
		s[i] = c;
		i++;
	}
	ungetch(c);

	if((c = getch()) == '.') {
		s[i] = c;
		i++;
		while(isdigit(c = getch())) {
			s[i] = c;
			i++;
		}
	}
	s[i] = '\0';
	// put back the first(and last) non digit char we read if not EOF
	if(c != EOF) ungetch(c); /* put back the unused char we read in the if, or while expression */

	return NUMBER;
}

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch() { /* get a (possibly pushed-back) character */
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) { /* push character back on input */
	if (bufp >= BUFSIZE) printf("ungetch: too many characters\n");
	else buf[bufp++] = c;
}
