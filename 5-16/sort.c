/*
 * Exercise 5-16.
 *
 * Add the -d (``directory order'') option, which makes comparisons only on letters, numbers and blanks. Make sure it works in conjunction with -f.
 */

#include "alloc.c"
#include "lines.c"
#include "qsort.c"
#include "cmp.c"

#define MAXLINES 10000 /* Maximum number of lines */
#define USAGE "usage:  sort [-dfnr]\n"

void exit_with_usage();

int main(int argc, char *argv[]) {
    int directory_case, fold_case, numeric, reverse;

    /* Parse flags */
    directory_case = 0;	/* -d */
    fold_case = 0;	/* -f */
    numeric = 0;	/* -n */
    reverse = 0;	/* -r */
    {
	int argi;
	for(argi = 1; argi < argc; argi++) {
	    if(argv[argi][0] == '-' && argv[argi][1] != '\0') {
		int flagi;
		for(flagi = 1; argv[argi][flagi] != '\0'; flagi++) {
		    if(argv[argi][flagi] == 'd') directory_case = 1;
		    else if(argv[argi][flagi] == 'f') fold_case = 1;
		    else if(argv[argi][flagi] == 'n') numeric = 1;
		    else if(argv[argi][flagi] == 'r') reverse = 1;
		    else exit_with_usage();
		}
	    } else exit_with_usage();
	}
    }

    if(numeric && fold_case) {
	fputs("error: -f and -n are mutually exclusive", stderr);
	return 1;
    }
    if(numeric && directory_case) {
	fputs("error: -d and -n are mutually exclusive", stderr);
	return 1;
    }

    /* Sort stdin */
    {
	int lines;
	char *lineptr[MAXLINES];

	lines = read_lines(lineptr, MAXLINES);
	if(lines == -1) {
	    fprintf(stderr, "error: maximum %d lines\n", MAXLINES);
	    return 1;
	}

	{
	    int sorted = 0;
	    if(directory_case) {
		_qsort(lineptr, lines, dircmp, reverse);
		sorted = 1;
	    }
	    if(fold_case) {
		_qsort(lineptr, lines, fldcmp, reverse);
		sorted = 1;
	    }
	    if(numeric) {
		_qsort(lineptr, lines, numcmp, reverse);
		sorted = 1;
	    }

	    if(!sorted) {
		_qsort(lineptr, lines, (int (*)(char *, char*)) strcmp, reverse);
	    }
	}

	write_lines(lineptr, lines);
    }
}

void exit_with_usage() {
    fputs(USAGE, stderr);
    exit(1);
}
