/*
 * Exercise 5-12.
 *
 * Extend entab and detab to accept the shorthand  
 *
 * entab -m +n 
 * to mean tab stops every n columns, starting at column m. Choose convenient (for the user) default behaviour.
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
    if(argc == 3 &&argv[1][0] == '-' && argv[2][0] == '+') {
	int m, n, i, increment, tab_stop;

	m = atoi(argv[1] + 1);
	n = atoi(argv[2] + 1);

	for(i = 0, tab_stop = m, increment = n; i < MAXTABSTOPS; i++, tab_stop += increment) {
	    tab_stops[i] = tab_stop;
	    tab_stops_count = i;
	}
    } else if(argc > 1) {
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

    /* output entabbed stdin to stdout */
    {
	char c;
	int is_at_beginning_of_line = 1;
	int blanks_at_beginning_of_line = 0;
        int blanks_since_last_tab_stop = 0;

	while((c = getchar())) {
	    if(is_at_beginning_of_line && c == ' ') {
		int at_tab_stop, i;

		blanks_at_beginning_of_line++;
		blanks_since_last_tab_stop++;

		at_tab_stop = 0;
		for(i = 0; (at_tab_stop = (tab_stops[i] == blanks_at_beginning_of_line)); i++);
		for(i = 0; i < tab_stops_count; i++) {
		    at_tab_stop = (tab_stops[i] == blanks_at_beginning_of_line);
		    if(at_tab_stop) break;
		}

		if(at_tab_stop) {
		    putchar('\t');
		    blanks_since_last_tab_stop = 0;
		}
	    } else {
		int i;
		if(is_at_beginning_of_line) {
		    /* printf("\nis_at_beginning_of_line: %d\n", is_at_beginning_of_line); */
		    /* printf("blanks_at_beginning_of_line: %d\n", blanks_at_beginning_of_line); */

		    for(i = 0; i < blanks_since_last_tab_stop; i++) putchar(' ');
		    is_at_beginning_of_line = 0;
		}
		if(c != EOF) putchar(c);
		if(c == '\n') {
		    is_at_beginning_of_line = 1;
		    blanks_at_beginning_of_line = 0;
		}
		if(c == EOF)break;
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
