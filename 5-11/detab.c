/*
 * Exercise 5-11.
 *
 * Modify the program entab and detab (written as exercises in Chapter 1) to accept a list of tab stops as arguments. Use the default tab settings if there are no arguments.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXTABSTOPS 10000

void print_blanks(int);

int main(int argc, char *argv[]) {
    int tab_stops[MAXTABSTOPS];
    int tab_stops_count = 0;

    /* parse argv / set tab stops */
    if(argc > 1) {
	int i;
	for(i = 0; argv[i + 1] != NULL; tab_stops_count = ++i) {
	    tab_stops[i] = atoi(argv[i + 1]);
	}
    } else {
	int i, tab_stop;
	/* 2, 4, 8, ... */
	for(i = 0, tab_stop = 2; i < MAXTABSTOPS; i++, tab_stop *= 2) {
	    tab_stops[i] = tab_stop;
	    tab_stops_count = i;
	}
    }

    /* output detabbed stdin to stdout */
    {
	char c;
	int is_at_beginning_of_line = 1;
	int tabs_at_beginning_of_line = 0;

	while((c = getchar())) {
	    if(is_at_beginning_of_line && c == '\t') {
		print_blanks(tab_stops[tabs_at_beginning_of_line] - tab_stops[tabs_at_beginning_of_line - 1]);
		tabs_at_beginning_of_line++;
	    } else {
		is_at_beginning_of_line = 0;
		if(c == '\n') {
		    is_at_beginning_of_line = 1;
		    tabs_at_beginning_of_line = 0;
		} else if(c == EOF) {
		    break;
		}
		putchar(c);
	    }
	}
    }
}
    
void print_blanks(int amount) {
    int i;
    for(i = 0; i < amount; i++) {
	putchar(' ');
    }
}
