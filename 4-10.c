/*
 * Exercise 4-10.
 *
 * An alternate organization uses getline to read an entire input line; this makes getch and ungetch unneccesarry. Revise the calculator to use this approach.
 */

/*
 * the following is very bad copy paste code
 */

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

#define MAXVAL 10000 /* maximum depth of val stack */
#define MAXLINE 10000 /* maximum line length */
#define MAXOP 10000 /* maximum operator or operand length */

void push(double);
double pop();
double top();
int my_getline(char[], int);

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

/* reverse Polish calculator */
int main() {
	char l[MAXLINE];
	char op[MAXOP]; /* operator or operand */
	double x = 0, y = 0, z = 0, m = 0;
	while(my_getline(l, MAXLINE) > 0) {
		int i = 0;
		while(true) { /* Process one operator or operand */
			while(isspace(l[i])) i++;
			if(l[i] == '\0') break; /* No oper{ator,and} to read */

			int op_index = i; /* first index of operand */
			if(l[i] == 's' && isspace(l[i+1])) { /* swap */
				i++;
				double op2 = pop();
				double op1 = pop();
				push(op2);
				push(op1);
			} else if(l[i] == 'd' && isspace(l[i+1])) { /* duplicate */
				i++;
				push(top());
			} else if(l[i] == 'c' && isspace(l[i+1])) { /* duplicate */
				i++;
				sp = 0;
			} else if(l[i] == 'p' && isspace(l[i+1])) {
				i++;
				pop();
			} else if(l[i] == '+' && isspace(l[i+1])) {
				i++;
				push(pop() + pop());
			} else if(l[i] == '-' && isspace(l[i+1])) {
				i++;
				double op2 = pop();
				push(pop() - op2);
			} else if(l[i] == '*' && isspace(l[i+1])) {
				i++;
				push(pop() - pop());
			} else if(l[i] == '/' && isspace(l[i+1])) {
				i++;
				double op2 = pop();
				if(op2 == 0.0) {
					puts("error: zero divisor\n");
				} else {
					push(pop() / op2);
				}
			} else if(l[i] == '%' && isspace(l[i+1])) {
				i++;
				double op2 = pop();
				double op1 = pop();
				if(op2 - (int) op2 + op1 - (int) op1 > 0) {
					puts("disregarding operands' mantissas");
				}
				if(op2 == 0.0) {
					puts("error: zero divisor\n");
				} else {
					push((int)op1 % (int)op2);
				}
			} else if(l[i] == 'S' && isspace(l[i+1])) {
				i++;
				push(sin(pop()));
			} else if(l[i] == 'E' && isspace(l[i+1])) {
				i++;
				push(exp(pop()));
			} else if(l[i] == 'P' && isspace(l[i+1])) {
				i++;
				double op2 = pop();
				push(pow(pop(), op2));
			} else if(l[i] == 'm' && isspace(l[i+1])) {
				i++;
				push(m);
			} else if(l[i] == 'x' && isspace(l[i+1])) {
				i++;
				push(x);
			} else if(l[i] == 'y' && isspace(l[i+1])) {
				i++;
				push(y);
			} else if(l[i] == 'z' && isspace(l[i+1])) {
				i++;
				push(z);
			} else if(l[i] == 'X' && isspace(l[i+1])) {
				i++;
				x = pop();
			} else if(l[i] == 'Y' && isspace(l[i+1])) {
				i++;
				y = pop();
			} else if(l[i] == 'Z' && isspace(l[i+1])) {
				i++;
				z = pop();
			} else if(isdigit(l[i]) || l[i] == '-' || l[i] == '+' || l[i] == '.') { /* literal */
				if(l[i] == '+' || l[i] == '-') {
					op[i - op_index] = l[i];
					i++;
				}
				while(isdigit(l[i])) {
					op[i - op_index] = l[i];
					i++;
				}
				if(l[i] == '.') {
					op[i - op_index] = '.';
					i++;
				}
				while(isdigit(l[i])) {
					op[i - op_index] = l[i];
					i++;
				}

				op[i - op_index] = '\0';
				push(atof(op));
			} else {
				while(!isspace(l[i])) {
					op[i - op_index] = l[i];
					i++;
				}
				op[i - op_index] = '\0';
				printf("error: invalid operator/operand %s\n", op);
			}
		}

		m = top();
		printf("\t%.8g\n", m);
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

/* my_getline:  get line into s, return length */
int my_getline(char s[], int lim) {
	int c, i;
	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}
