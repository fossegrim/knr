/*
 * Exercise 5-14.
 *
 * Modify the sort program to handle a -r flag, which indicates sorting in reverse (decreasing) order. Be sure that -r works with -n.
 */

#include "alloc.c"
#include "lines.c"
#include "qsort.c"

#define MAXLINES 10000 /* Maximum number of lines */
#define USAGE "usage:  sort [-nr]\n"

int main(int argc, char *argv[]) {
    int numeric, reverse;

    /* Parse flags */
    numeric = 0; /* -n */
    reverse = 0; /* -r */
    {
	int argi;
	for(argi = 1; argi < argc; argi++) {
	    if(argv[argi][0] == '-' && argv[argi][1] != '\0') {
		int flagi;
		for(flagi = 1; argv[argi][flagi] != '\0'; flagi++) {
		    if(argv[argi][flagi] == 'n') numeric = 1;
		    else if(argv[argi][flagi] == 'r') reverse = 1;
		    else {
			fputs(USAGE, stderr);
			return 1;
		    }
		}
	    } else {
		fputs(USAGE, stderr);
		return 1;
	    }
	}
    }

    /* Sort stdin */
    {
	int lines;
	char *lineptr[MAXLINES];
	int cmp(char *, char*);

	lines = read_lines(lineptr, MAXLINES);
	if(lines == -1) {
	    fprintf(stderr, "error: maximum %d lines\n", MAXLINES);
	    return 1;
	}

	_qsort(
	    lineptr,
	    lines,
	    numeric ? numcmp : (int (*)(char *, char *)) strcmp,
	    reverse);

	write_lines(lineptr, lines);
    }
}
