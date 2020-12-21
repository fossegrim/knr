/*
 * Exercise 5-10.
 *
 * Write the program expr, which evaluates a reverse Polish expression from the command line, where each operator or operand is a separate argument. For example,
 *
 * expr 2 3 4 + *
 *
 * evaluates 2 * (3+4).
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void rpn(char *[], int);
int parse_int(char *, int *);
char parse_operator(char *);
int pop();
void push(int);
void try_push(int);
void print();

int main(int argc, char *argv[]) {
    /* skip program name */
    argv++;

    rpn(argv, argc - 2);

    /* print stack */
    print();
}

void rpn(char *ops[], int l) {
    int i, operand, stack_op1, stack_op2;
    char operator;
    for(i = 0; i <= l; i++) {
	if(parse_int(ops[i], &operand)) {
	    push(operand);
	} else if((operator = parse_operator(ops[i])) != EOF) {
	    stack_op2 = pop();
	    stack_op1 = pop();
	    switch(operator) {
	    case '+':
		push(stack_op1 + stack_op2);
		break;
	    case '-':
		push(stack_op1 - stack_op2);
		break;
	    case '*':
		push(stack_op1 * stack_op2);
		break;
	    case '/':
		push(stack_op1 / stack_op2);
		break;
	    }
	} else {
	    fprintf(stderr, "error: could not parse oper{ator,and} \"%s\"", ops[i]);
	}
    }
}

/* parse_int:  if str represents an integer write it to n and return 1, otherwise return 1 */
int parse_int(char *str, int *n) {
    char *strp = str;
    
    /* verify that str is a valid integer */
    while(*strp != '\0') {
	if(!isdigit(*strp)) return 0;
	strp++;
    }

    *n = atoi(str);
    return 1;
}

/* parse_operator: if str represents +, -, *, or / return the char operator it represents, otherwise return EOF */
char parse_operator(char *str) {
    if(strcmp("+", str) == 0) return '+';
    else if(strcmp("-", str) == 0) return '-';
    else if(strcmp("*", str) == 0) return '*';
    else if(strcmp("/", str) == 0) return '/';
    else return EOF;
}
    

#define STACKSIZE 1000
int stack[STACKSIZE];
int *stack_top = stack - 1; /* top element in stack */

/* pop: if the stack is empty print error message and exit, otherwise return the top of the stack and decrement stack_top */
int pop() {
    if(stack_top >= stack) {
	return *stack_top--;
    } else {
	fprintf(stderr, "error: could not pop(empty stack)\n");
	exit(1);
    }
}

/* push:  if the stack is full print error message and exit, otherwise push n*/
void push(int n) {
    if(stack_top < stack + STACKSIZE) {
	*++stack_top = n;
    } else {
	fprintf(stderr, "error: could not push(full stack)\n");
	exit(1);
    }
}

/* print:  print the stack */
void print() {
    int *sp = stack;

    /* print top of stack (no preceding space) */
    if(sp <= stack_top) printf("%d", *sp++);

    /* print the rest of the stack (preceding space) */
    while(sp <= stack_top) printf(" %d", *sp++);
    
    puts("");
}
